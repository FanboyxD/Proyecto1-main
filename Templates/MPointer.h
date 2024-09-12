#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <memory>
#include <cstdlib> // Para malloc y free

// Declaración anticipada de la clase template MPointer
template <typename T>
class MPointer;

// Declaración anticipada de la clase para pruebas
class QuickSortGtest_Friend;

// Clase que maneja el recolector de basura para MPointer
class MPointerGC {
public:
    // Devuelve una instancia única del recolector de basura (singleton)
    static MPointerGC& Instance() {
        static MPointerGC instance;
        return instance;
    }

    // Registra un MPointer y devuelve un ID único para él
    template <typename T>
    size_t RegisterMPointer(const MPointer<T>& myPtr) {
        std::lock_guard<std::mutex> lock(mtx); // Bloqueo para acceso seguro a la lista de punteros
        size_t id = next_id++; // Genera un ID autogenerado único
        pointers.emplace_back(id, myPtr.ptr); // Almacena el ID y el puntero
        return id;
    }

    // Obtiene el conteo de punteros registrados
    size_t GetPointerCount() {
        std::lock_guard<std::mutex> lock(mtx); // Bloqueo para acceso seguro
        return pointers.size();
    }

    // Elimina el MPointer con el ID especificado
    template <typename T>
    void UnregisterMPointer(size_t id) {
        std::lock_guard<std::mutex> lock(mtx); // Bloqueo para acceso seguro
        pointers.remove_if([id](const auto& pair) { return pair.first == id; }); // Elimina el puntero con el ID correspondiente
    }

    // Recolecta la memoria no utilizada
    void GarbageCollect() {
        std::lock_guard<std::mutex> lock(mtx); // Bloqueo para acceso seguro
        for (auto it = pointers.begin(); it != pointers.end();) {
            if (it->second == nullptr) { // Si el puntero es nulo
                it = pointers.erase(it); // Elimina el puntero de la lista
            } else {
                ++it;
            }
        }
    }

private:
    MPointerGC() : next_id(0) {
        // Hilo que ejecuta la recolección de basura periódicamente
        gc_thread = std::thread([this]() {
            while (running) {
                std::this_thread::sleep_for(std::chrono::seconds(1)); // Espera de 1 segundo
                GarbageCollect(); // Ejecuta la recolección de basura
            }
        });
    }

    ~MPointerGC() {
        running = false; // Detiene el hilo de recolección de basura
        if (gc_thread.joinable()) {
            gc_thread.join(); // Espera a que el hilo termine
        }
    }

    std::list<std::pair<size_t, void*>> pointers; // Lista enlazada para almacenar las direcciones de memoria y sus IDs
    size_t next_id; // ID autogenerado para los punteros
    std::mutex mtx; // Mutex para proteger el acceso a la lista de punteros
    std::thread gc_thread; // Hilo para ejecutar la recolección de basura
    bool running = true; // Bandera para el estado del hilo de recolección
};

// Clase template MPointer
template <typename T>
class MPointer {
public:
    // Constructor por defecto
    MPointer() : ptr(nullptr), id(0), ref_count(new size_t(1)) {}

    // Constructor que acepta nullptr
    MPointer(std::nullptr_t) : ptr(nullptr), id(0), ref_count(new size_t(1)) {}

    // Constructor de copia
    MPointer(const MPointer<T>& other) 
        : ptr(other.ptr), id(other.id), ref_count(other.ref_count) {
        if (ref_count) {
            ++(*ref_count); // Incrementa el contador de referencias
        }
    }

    // Crea un nuevo MPointer y lo inicializa
    static MPointer<T> New() {
        MPointer<T> myPtr;
        myPtr.ptr = new T(); // Reserva memoria para un nuevo objeto de tipo T
        *(myPtr.ref_count) = 1; // Inicializa el contador de referencias a 1
        myPtr.id = MPointerGC::Instance().RegisterMPointer(myPtr); // Registra el puntero en el recolector de basura
        return myPtr;
    }

    // Destructor
    ~MPointer() {
        if (ref_count && --(*ref_count) == 0) {
            free(ptr); // Libera la memoria del objeto de tipo T
            delete ref_count; // Libera la memoria del contador de referencias
            MPointerGC::Instance().UnregisterMPointer<T>(id); // Desregistra el puntero del recolector de basura
        }
    }

    // Operador * para acceder al valor en el puntero
    MPointer<T>& operator*() {
        return *this;
    }

    // Operador -> para acceder a los miembros del objeto al que apunta
    T* operator->() {
        return ptr;
    }

    // Operador de asignación para copiar otro MPointer
    MPointer<T>& operator=(const MPointer<T>& other) {
        if (this != &other) {
            if (ref_count && --(*ref_count) == 0) {
                free(ptr);
                delete ref_count;
                MPointerGC::Instance().UnregisterMPointer<T>(id);
            }
            ptr = other.ptr;
            ref_count = other.ref_count;
            id = other.id;
            if (ref_count) {
                ++(*ref_count);
            }
        }
        return *this;
    }

    // Operador de asignación para asignar un valor al puntero
    MPointer<T>& operator=(T value) {
        if (ptr) {
            *ptr = value;
        }
        return *this;
    }

    // Operador & para obtener el valor almacenado en el puntero
    T& operator&() {
        return *ptr;
    }

    // Método para obtener la dirección de memoria del valor almacenado
    T* GetAddress() {
        return ptr;
    }

    // Method to get the current reference count
    size_t GetRefCount() const {
        return *ref_count; // Retorna estado actual de contador de referencias
    }

    // Operador ! para verificar si el puntero es nulo
    bool operator!() const {
        return ptr == nullptr;
    }

    // Operador == para comparar dos MPointers
    bool operator==(const MPointer<T>& other) const {
        return ptr == other.ptr;
    }

    // Operador != para comparar dos MPointers
    bool operator!=(const MPointer<T>& other) const {
        return ptr != other.ptr;
    }

    // Conversión implícita a bool para verificar si el puntero es válido
    operator bool() const {
        return ptr != nullptr;
    }

private:
    T* ptr; // Puntero al objeto de tipo T
    size_t id; // ID del puntero registrado en el recolector de basura
    size_t* ref_count; // Contador de referencias para el puntero

    friend class MPointerGC; // Permite que MPointerGC acceda a los miembros privados
};
