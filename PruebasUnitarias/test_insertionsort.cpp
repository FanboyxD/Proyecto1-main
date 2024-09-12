#define RUNNING_TESTS
#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/Templates/DoublyLinkedList.h" // Incluye la implementación de la lista doblemente enlazada
#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/AlgoritmosOrdenamiento/InsertionSortPtr.cpp" // Incluye la implementación del algoritmo de ordenamiento por inserción
#include <gtest/gtest.h> // Incluye Google Test para pruebas unitarias

// Test para el algoritmo de ordenamiento por inserción
TEST(InsertionSortTest, BasicSorting) {
    DoublyLinkedList<int> list;
    list.append(4); // Añade el elemento 4
    list.append(2); // Añade el elemento 2
    list.append(9); // Añade el elemento 9
    list.append(1); // Añade el elemento 1
    list.append(6); // Añade el elemento 6

    insertionSort(list); // Ordena la lista usando el algoritmo de ordenamiento por inserción

    // Define el resultado esperado
    std::vector<int> expected = {1, 2, 4, 6, 9};
    MPointer<Node<int>> current = list.head;
    for (int val : expected) {
        // Verifica que los elementos estén en el orden correcto
        ASSERT_EQ(&(current->data), val);
        current = current->next;
    }
}

// Test para el caso de una lista vacía
TEST(InsertionSortTest, EmptyList) {
    DoublyLinkedList<int> list;

    insertionSort(list); // Ordena la lista vacía

    // Verifica que la lista vacía siga siendo vacía
    ASSERT_EQ(list.head, nullptr);
    ASSERT_EQ(list.tail, nullptr);
}

// Test para una lista con un solo elemento
TEST(InsertionSortTest, SingleElementList) {
    DoublyLinkedList<int> list;
    list.append(5); // Añade el elemento 5

    insertionSort(list); // Ordena la lista con un solo elemento

    // Verifica que el único elemento sigue siendo 5
    ASSERT_NE(list.head, nullptr);
    ASSERT_NE(list.tail, nullptr);
    ASSERT_EQ(&(list.head->data), 5);
    ASSERT_EQ(&(list.tail->data), 5);
}

// Test para una lista ya ordenada
TEST(InsertionSortTest, AlreadySortedList) {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    insertionSort(list); // Ordena la lista ya ordenada

    // Define el resultado esperado
    std::vector<int> expected = {1, 2, 3, 4, 5};
    MPointer<Node<int>> current = list.head;
    for (int val : expected) {
        // Verifica que los elementos están en el orden correcto
        ASSERT_EQ(&(current->data), val);
        current = current->next;
    }
}

// Test para una lista en orden inverso
TEST(InsertionSortTest, ReversedList) {
    DoublyLinkedList<int> list;
    list.append(5);
    list.append(4);
    list.append(3);
    list.append(2);
    list.append(1);

    insertionSort(list); // Ordena la lista en orden inverso

    // Define el resultado esperado
    std::vector<int> expected = {1, 2, 3, 4, 5};
    MPointer<Node<int>> current = list.head;
    for (int val : expected) {
        // Verifica que los elementos estén en el orden correcto
        ASSERT_EQ(&(current->data), val);
        current = current->next;
    }
}

// Función principal para ejecutar todas las pruebas unitarias
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa Google Test
    return RUN_ALL_TESTS(); // Ejecuta todas las pruebas definidas
}

/* 
Compilar con: 
    clang++ -std=c++14 -g -isystem /usr/include/gtest -pthread /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_insertionsort.cpp -lgtest -lgtest_main -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_insertionsort

Ejecutar con: 
            /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_insertionsort
*/
