#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/Templates/DoublyLinkedList.h" // Incluye la definición de DoublyLinkedList

// Función de partición para el algoritmo QuickSort
template <typename T>
MPointer<Node<T>> partition(MPointer<Node<T>> low, MPointer<Node<T>> high) {
    if (!low || !high || !high->data) return low; // Verifica que los punteros sean válidos

    T pivot = &(high->data); // Elige el último elemento como pivote
    MPointer<Node<T>> i = low->prev; // Nodo antes del primer elemento en la partición

    // Recorre la lista desde low hasta high
    for (MPointer<Node<T>> j = low; j != high && j != nullptr; j = j->next) {
        if (j->data && &(j->data) <= pivot) { // Si el elemento es menor o igual al pivote
            i = (i == nullptr) ? low : i->next; // Avanza i
            if (i && i->data && j->data) {
                std::swap(&(i->data), &(j->data)); // Intercambia los datos de i y j
            }
        }
    }
    i = (i == nullptr) ? low : i->next; // Avanza i para el pivote
    if (i && i->data && high->data) {
        std::swap(&(i->data), &(high->data)); // Intercambia el pivote con el dato en i
    }
    return i; // Devuelve el nodo de partición
}

// Función de ordenamiento QuickSort
template <typename T>
void quicksort(MPointer<Node<T>> low, MPointer<Node<T>> high) {
    if (!low || !high || low == high || low == high->next) return; // Casos base

    MPointer<Node<T>> p = partition(low, high); // Divide la lista en dos particiones
    if (p && p->prev && p->prev != low) {
        quicksort(low, p->prev); // Ordena la partición izquierda
    }
    if (p && p->next && p->next != high) {
        quicksort(p->next, high); // Ordena la partición derecha
    }
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

    quicksort(list.head, list.tail); // Ordena la lista con QuickSort

    std::cout << "Lista ordenada con Quicksort: ";
    list.printList(); // Imprime la lista ordenada

    return 0; // Finaliza el programa
}
#endif

/* 
Compilar con: 
    clang++ -std=c++17 -g /home/fabricio/Documents/Prueba\ C/Proyecto1-main/AlgoritmosOrdenamiento/QuickSortPtr.cpp -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/QuickSortPtr

Ejecutar con: 
            /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/QuickSortPtr
*/
