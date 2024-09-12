// test_bubble_sort.cpp
#define RUNNING_TESTS
#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/Templates/DoublyLinkedList.h" // Incluye la implementación de la lista doblemente enlazada
#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/AlgoritmosOrdenamiento/BubbleSortPtr.cpp" // Incluye la implementación del algoritmo de BubbleSort
#include <gtest/gtest.h> // Incluye Google Test para pruebas unitarias

// Prueba para el algoritmo de BubbleSort en una lista con varios elementos desordenados
TEST(BubbleSortTest, BasicSorting) {
    DoublyLinkedList<int> list;
    list.append(4);
    list.append(2);
    list.append(9);
    list.append(1);
    list.append(6);

    bubbleSort(list); // Llama a la función de ordenamiento

    std::vector<int> expected = {1, 2, 4, 6, 9}; // Lista esperada después de ordenar
    MPointer<Node<int>> current = list.head;
    for (int val : expected) {
        ASSERT_EQ(&(current->data), val); // Verifica que los valores sean correctos
        current = current->next; // Avanza al siguiente nodo
    }
}

// Prueba para el caso de una lista vacía
TEST(BubbleSortTest, EmptyList) {
    DoublyLinkedList<int> list;

    bubbleSort(list); // Llama a la función de ordenamiento

    ASSERT_EQ(list.head, nullptr); // Verifica que el head sea nullptr
    ASSERT_EQ(list.tail, nullptr); // Verifica que el tail sea nullptr
}

// Prueba para una lista con un solo elemento
TEST(BubbleSortTest, SingleElementList) {
    DoublyLinkedList<int> list;
    list.append(5);

    bubbleSort(list); // Llama a la función de ordenamiento

    ASSERT_NE(list.head, nullptr); // Verifica que el head no sea nullptr
    ASSERT_NE(list.tail, nullptr); // Verifica que el tail no sea nullptr
    ASSERT_EQ(&(list.head->data), 5); // Verifica que el valor del head sea el esperado
    ASSERT_EQ(&(list.tail->data), 5); // Verifica que el valor del tail sea el esperado
}

// Prueba para una lista que ya está ordenada
TEST(BubbleSortTest, AlreadySortedList) {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    bubbleSort(list); // Llama a la función de ordenamiento

    std::vector<int> expected = {1, 2, 3, 4, 5}; // Lista esperada después de ordenar
    MPointer<Node<int>> current = list.head;
    for (int val : expected) {
        ASSERT_EQ(&(current->data), val); // Verifica que los valores sean correctos
        current = current->next; // Avanza al siguiente nodo
    }
}

// Prueba para una lista en orden inverso
TEST(BubbleSortTest, ReversedList) {
    DoublyLinkedList<int> list;
    list.append(5);
    list.append(4);
    list.append(3);
    list.append(2);
    list.append(1);

    bubbleSort(list); // Llama a la función de ordenamiento

    std::vector<int> expected = {1, 2, 3, 4, 5}; // Lista esperada después de ordenar
    MPointer<Node<int>> current = list.head;
    for (int val : expected) {
        ASSERT_EQ(&(current->data), val); // Verifica que los valores sean correctos
        current = current->next; // Avanza al siguiente nodo
    }
}

// Función principal para ejecutar todas las pruebas unitarias
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa Google Test
    return RUN_ALL_TESTS(); // Ejecuta todas las pruebas definidas
}

/* 
Compilar con: 
    clang++ -std=c++14 -g -isystem /usr/include/gtest -pthread /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_bubblesort.cpp -lgtest -lgtest_main -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_bubblesort

Ejecutar con: 
            /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_bubblesort
*/
