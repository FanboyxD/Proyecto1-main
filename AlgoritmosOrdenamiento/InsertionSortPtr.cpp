#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/Templates/DoublyLinkedList.h" // Incluye la definición de DoublyLinkedList

// Implementación del algoritmo de ordenamiento por inserción
template <typename T>
void insertionSort(DoublyLinkedList<T>& list) {
    if (!list.head) return; // Si la lista está vacía, no hacer nada

    MPointer<Node<T>> sorted = nullptr; // Lista ordenada inicialmente vacía
    MPointer<Node<T>> current = list.head; // Nodo actual para procesar

    // Recorre todos los nodos de la lista
    while (current != nullptr) {
        MPointer<Node<T>> next = current->next; // Guarda el siguiente nodo

        // Inserta el nodo actual en la lista ordenada
        if (!sorted || &(sorted->data) >= &(current->data)) {
            current->next = sorted; // Inserta al principio de la lista ordenada
            if (sorted) sorted->prev = current; // Actualiza el puntero previo del antiguo primer nodo
            sorted = current; // Actualiza la cabeza de la lista ordenada
            sorted->prev = nullptr; // El nuevo primer nodo no tiene predecesor
        } else {
            MPointer<Node<T>> temp = sorted;
            // Encuentra la posición correcta para insertar el nodo actual
            while (temp->next != nullptr && &(temp->next->data) < &(current->data)) {
                temp = temp->next;
            }

            // Inserta el nodo actual en la posición correcta
            current->next = temp->next; // Actualiza el puntero al siguiente nodo
            if (temp->next != nullptr) {
                temp->next->prev = current; // Actualiza el puntero previo del siguiente nodo
            }
            temp->next = current; // Inserta el nodo actual
            current->prev = temp; // Actualiza el puntero previo del nodo actual
        }
        current = next; // Avanza al siguiente nodo
    }

    list.head = sorted; // Actualiza la cabeza de la lista original

    // Actualiza el tail de la lista
    list.tail = list.head;
    while (list.tail->next != nullptr) {
        list.tail = list.tail->next; // Avanza hasta el último nodo
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

    insertionSort(list); // Ordena la lista con Insertion Sort

    std::cout << "Lista ordenada con Insertion Sort: ";
    list.printList(); // Imprime la lista ordenada

    return 0; // Finaliza el programa
}
#endif

/* 
Compilar con: 
    clang++ -std=c++17 -g /home/fabricio/Documents/Prueba\ C/Proyecto1-main/AlgoritmosOrdenamiento/InsertionSortPtr.cpp -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/InsertionSortPtr

Ejecutar con: 
            /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/InsertionSortPtr
*/
