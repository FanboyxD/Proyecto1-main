#include "gtest/gtest.h" // Incluye Google Test para pruebas unitarias
#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/Templates/MPointer.h" // Incluye la implementación de MPointer y MPointerGC

// Caso de prueba para verificar el registro de punteros en el Garbage Collector
TEST(MPointerGCTest, RegisterMPointer) {
    size_t initial_count = MPointerGC::Instance().GetPointerCount(); // Obtiene el número inicial de punteros
    MPointer<int> ptr = MPointer<int>::New(); // Crea un nuevo MPointer
    size_t new_count = MPointerGC::Instance().GetPointerCount(); // Obtiene el nuevo número de punteros
    EXPECT_EQ(new_count, initial_count + 1);  // Verifica que el contador haya aumentado en 1
}

// Caso de prueba para verificar la recolección de basura
TEST(MPointerGCTest, GarbageCollect) {
    MPointer<int> ptr = MPointer<int>::New(); // Crea un nuevo MPointer
    size_t initial_count = MPointerGC::Instance().GetPointerCount(); // Obtiene el número inicial de punteros
    ptr = nullptr; // Elimina el MPointer

    // Espera un tiempo para que el recolector de basura se ejecute
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Espera a que el Garbage Collector ejecute
    MPointerGC::Instance().GarbageCollect(); // Fuerza la recolección de basura

    size_t final_count = MPointerGC::Instance().GetPointerCount(); // Obtiene el número final de punteros
    EXPECT_EQ(final_count, initial_count - 1);  // Verifica que el contador haya disminuido en 1
}

// Caso de prueba para verificar la desregistración de un MPointer
TEST(MPointerGCTest, UnregisterMPointer) {
    MPointer<int> ptr = MPointer<int>::New(); // Crea un nuevo MPointer
    size_t id = MPointerGC::Instance().RegisterMPointer(ptr); // Registra el MPointer

    size_t initial_count = MPointerGC::Instance().GetPointerCount(); // Obtiene el número inicial de punteros
    MPointerGC::Instance().UnregisterMPointer<int>(id); // Desregistra el MPointer manualmente

    size_t final_count = MPointerGC::Instance().GetPointerCount(); // Obtiene el número final de punteros
    EXPECT_EQ(final_count, initial_count - 1);  // Verifica que el contador haya disminuido
}

// Caso de prueba para el recolector de basura con múltiples punteros
TEST(MPointerGCTest, MultiplePointers) {
    MPointer<int> ptr1 = MPointer<int>::New(); // Crea un MPointer
    MPointer<int> ptr2 = MPointer<int>::New(); // Crea otro MPointer

    size_t initial_count = MPointerGC::Instance().GetPointerCount(); // Obtiene el número inicial de punteros
    ptr1 = nullptr; // Elimina el primer MPointer

    // Espera un tiempo para que el recolector de basura se ejecute
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Espera a que el Garbage Collector ejecute
    MPointerGC::Instance().GarbageCollect(); // Fuerza la recolección de basura

    size_t final_count = MPointerGC::Instance().GetPointerCount(); // Obtiene el número final de punteros
    EXPECT_EQ(final_count, initial_count - 1);  // Verifica que el contador haya disminuido en 1

    // Verifica que el segundo puntero siga registrado
    EXPECT_FALSE(!ptr2);
}

// Función principal para ejecutar todas las pruebas unitarias
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa Google Test
    return RUN_ALL_TESTS(); // Ejecuta todas las pruebas definidas
}

/* 
Compilar con: 
    clang++ -std=c++14 -g -isystem /usr/include/gtest -pthread /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_mpointergc.cpp -lgtest -lgtest_main -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_mpointergc

Ejecutar con: 
    /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_mpointergc
*/
