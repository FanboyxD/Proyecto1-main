#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/Templates/DoublyLinkedList.h" // Incluye la definición de DoublyLinkedList

// Implementación del algoritmo de ordenamiento Bubble Sort
template <typename T>
void bubbleSort(DoublyLinkedList<T>& list) {
    if (!list.head) return; // Si la lista está vacía, no hacer nada

    bool swapped; // Bandera para verificar si hubo intercambio
    MPointer<Node<T>> current; // Puntero para recorrer la lista
    MPointer<Node<T>> lastSorted = nullptr; // Nodo hasta donde ya está ordenado

    do {
        swapped = false; // Inicialmente no se han hecho intercambios
        current = list.head; // Comienza desde el inicio de la lista

        // Recorre la lista hasta el nodo que ya está ordenado
        while (current->next != lastSorted) {
            if (&(current->data) > &(current->next->data)) { // Si los elementos están en el orden incorrecto
                std::swap(&(current->data), &(current->next->data)); // Intercambia los elementos
                swapped = true; // Marca que se hizo un intercambio
            }
            current = current->next; // Avanza al siguiente nodo
        }
        lastSorted = current; // Marca el último nodo que está ordenado
    } while (swapped); // Repite mientras haya intercambios
}

#ifndef RUNNING_TESTS
int main() {
    DoublyLinkedList<int> list; // Crea una lista doblemente enlazada de enteros
    list.append(4);
    list.append(2);
    list.append(9);
    list.append(1);
    list.append(6);
    std::cout << "Lista original: ";
    list.printList(); // Imprime la lista original

    bubbleSort(list); // Ordena la lista con Bubble Sort

    std::cout << "Lista ordenada con Bubble Sort: ";
    list.printList(); // Imprime la lista ordenada

    return 0; // Finaliza el programa
}
#endif

/* 
Compilar con: 
    clang++ -std=c++17 -g /home/fabricio/Documents/Prueba\ C/Proyecto1-main/AlgoritmosOrdenamiento/BubbleSortPtr.cpp -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/BubbleSortPtr

Ejecutar con: 
            /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/BubbleSortPtr
*/
