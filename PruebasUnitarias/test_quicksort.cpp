#define RUNNING_TESTS
#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/Templates/DoublyLinkedList.h" // Incluye la definición de DoublyLinkedList
#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/AlgoritmosOrdenamiento/QuickSortPtr.cpp" // Incluye la implementación de QuickSort
#include <gtest/gtest.h> // Incluye Google Test para pruebas unitarias

// Caso de prueba para el algoritmo QuickSort con una lista básica
TEST(QuickSortTest, BasicSorting) {
    DoublyLinkedList<int> list; // Crea una lista doblemente enlazada de enteros
    list.append(4);
    list.append(2);
    list.append(9);
    list.append(1);
    list.append(6);

    quicksort(list.head, list.tail); // Llama a quicksort para ordenar la lista

    std::vector<int> expected = {1, 2, 4, 6, 9}; // Lista esperada después de la ordenación
    MPointer<Node<int>> current = list.head; // Iterador para recorrer la lista
    for (int val : expected) {
        ASSERT_EQ(&(current->data), val); // Verifica que cada valor en la lista ordenada coincida con el valor esperado
        current = current->next; // Avanza al siguiente nodo
    }
}

// Caso de prueba para QuickSort con una lista vacía
TEST(QuickSortTest, EmptyList) {
    DoublyLinkedList<int> list; // Crea una lista vacía

    quicksort(list.head, list.tail); // Llama a quicksort (no debería cambiar nada)

    ASSERT_EQ(list.head, nullptr); // Verifica que la lista sigue vacía
    ASSERT_EQ(list.tail, nullptr);
}

// Caso de prueba para QuickSort con una lista de un solo elemento
TEST(QuickSortTest, SingleElementList) {
    DoublyLinkedList<int> list; // Crea una lista de enteros
    list.append(5); // Añade un solo elemento

    quicksort(list.head, list.tail); // Llama a quicksort (no debería cambiar nada)

    ASSERT_NE(list.head, nullptr); // Verifica que el nodo existe
    ASSERT_NE(list.tail, nullptr);
    ASSERT_EQ(&(list.head->data), 5); // Verifica que el valor del nodo es 5
    ASSERT_EQ(&(list.tail->data), 5); // Verifica que el valor del tail también es 5
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa Google Test
    return RUN_ALL_TESTS(); // Ejecuta todas las pruebas definidas
}

/* 
Compilar con: 
    clang++ -std=c++14 -g -isystem /usr/include/gtest -pthread /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_quicksort.cpp -lgtest -lgtest_main -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_quicksort

Ejecutar con: 
            /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_quicksort
*/
