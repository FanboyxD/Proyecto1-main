// DoublyLinkedList.h
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "MPointer.h" // Incluye la definición de MPointer para manejar punteros inteligentes
#include <iostream> // Incluye la biblioteca para operaciones de entrada/salida

// Clase template para los nodos de la lista doblemente enlazada
template <typename T>
class Node {
public:
    MPointer<T> data; // Puntero inteligente al dato del nodo
    MPointer<Node<T>> next; // Puntero inteligente al siguiente nodo
    MPointer<Node<T>> prev; // Puntero inteligente al nodo previo

    // Constructor por defecto
    Node() : data(MPointer<T>::New()), next(nullptr), prev(nullptr) {}

    // Constructor que inicializa el dato del nodo con un valor específico
    Node(T value) : data(MPointer<T>::New()), next(nullptr), prev(nullptr) {
        *data = value; // Almacena el valor en el puntero de datos
    }
};

// Clase template para la lista doblemente enlazada
template <typename T>
class DoublyLinkedList {
public:
    MPointer<Node<T>> head; // Puntero inteligente al primer nodo de la lista
    MPointer<Node<T>> tail; // Puntero inteligente al último nodo de la lista

    // Constructor por defecto
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Método para añadir un nuevo nodo con un valor específico al final de la lista
    void append(T value) {
        MPointer<Node<T>> newNode = MPointer<Node<T>>::New(); // Crea un nuevo nodo
        newNode->data = MPointer<T>::New(); // Crea un nuevo puntero de datos para el nuevo nodo
        *(newNode->data) = value; // Almacena el valor en el puntero de datos del nuevo nodo
        std::cout << "Agregando nuevo valor: " << value << std::endl;
        std::cout << "Direccion de nuevo nodo: " << newNode.GetAddress() << std::endl;
        if (!head) { // Si la lista está vacía
            head = newNode; // El nuevo nodo es tanto el head como el tail
            tail = newNode;
            std::cout << "Lista vacia, el nuevo nodo es head y tail." << std::endl; // Print para debug
        std::cout << "direccion del head: " << head.GetAddress() << std::endl; // Print para debug
        std::cout << "direccion del tail: " << tail.GetAddress() << std::endl; // Print para debug
        } else { // Si la lista no está vacía
            std::cout << "direccion del head: " << head.GetAddress() << std::endl; // Print para debug
            std::cout << "direccion del tail: " << tail.GetAddress() << std::endl; // Print para debug
            tail->next = newNode; // Enlaza el nuevo nodo al final de la lista
            std::cout << "tail->next asignado al nuevo nodo." << std::endl; // Print para debug
            newNode->prev = tail; // Establece el puntero prev del nuevo nodo al antiguo tail
            std::cout << "newNode->prev asignado al tail." << std::endl;
            tail = newNode; // Actualiza el tail para que sea el nuevo nodo
            std::cout << "tail actualizado a nuevo nodo." << std::endl;
        }
    }

    // Método para imprimir todos los valores de los nodos en la lista
    void printList() const {
        MPointer<Node<T>> temp = head; // Comienza desde el head de la lista
        while (temp != nullptr) { // Mientras no se llegue al final de la lista
            std::cout << &(temp->data) << " "; // Imprime el valor del nodo actual
            temp = temp->next; // Avanza al siguiente nodo
        }
        std::cout << std::endl; // Imprime un salto de línea al final
    }
};

#endif // DOUBLYLINKEDLIST_H
