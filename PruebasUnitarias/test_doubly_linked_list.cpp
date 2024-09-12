#include "gtest/gtest.h" // Incluye Google Test para pruebas unitarias
#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/Templates/DoublyLinkedList.h" // Incluye la implementación de DoublyLinkedList

// Caso de prueba para añadir elementos a la lista
TEST(DoublyLinkedListTest, AppendElements) {
    DoublyLinkedList<int> list;

    list.append(1); // Añade el elemento 1
    list.append(2); // Añade el elemento 2
    list.append(3); // Añade el elemento 3

    // Verifica que el primer nodo tiene el valor 1
    ASSERT_NE(list.head, nullptr);
    ASSERT_EQ(&list.head->data, 1); // Usamos ** para desreferenciar correctamente

    // Verifica que el segundo nodo tiene el valor 2
    ASSERT_NE(list.head->next, nullptr);
    ASSERT_EQ(&list.head->next->data, 2);

    // Verifica que el último nodo tiene el valor 3
    ASSERT_NE(list.tail, nullptr);
    ASSERT_EQ(&list.tail->data, 3);

    // Verifica que el último nodo no tiene un siguiente nodo
    ASSERT_EQ(list.tail->next, nullptr);
}

// Caso de prueba para una lista vacía
TEST(DoublyLinkedListTest, EmptyList) {
    DoublyLinkedList<int> list;

    // Verifica que tanto el head como el tail son nullptr
    ASSERT_EQ(list.head, nullptr);
    ASSERT_EQ(list.tail, nullptr);
}

// Caso de prueba para la impresión de la lista
TEST(DoublyLinkedListTest, PrintList) {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    // Captura la salida estándar durante la impresión de la lista
    testing::internal::CaptureStdout();
    list.printList();
    std::string output = testing::internal::GetCapturedStdout();

    // Verifica que la salida es la esperada
    ASSERT_EQ(output, "1 2 3 \n");
}

// Caso de prueba para una lista con un solo elemento
TEST(DoublyLinkedListTest, SingleElement) {
    DoublyLinkedList<int> list;
    list.append(42); // Añade el elemento 42

    // Verifica que el head no es nullptr y su valor es 42
    ASSERT_NE(list.head, nullptr);
    ASSERT_EQ(&list.head->data, 42); // Usamos ** para desreferenciar correctamente

    // Verifica que head y tail son el mismo nodo
    ASSERT_EQ(list.head, list.tail);
    ASSERT_EQ(list.head->next, nullptr);
    ASSERT_EQ(list.head->prev, nullptr);
}

// Caso de prueba para verificar los enlaces doblemente (prev y next)
TEST(DoublyLinkedListTest, DoublyLinkedNodes) {
    DoublyLinkedList<int> list;
    list.append(10);
    list.append(20);
    list.append(30);

    // Verifica que el primer nodo no tiene un nodo previo
    ASSERT_EQ(list.head->prev, nullptr);
    // Verifica que el segundo nodo tiene el primer nodo como previo
    ASSERT_EQ(list.head->next->prev, list.head);
    // Verifica que el segundo nodo tiene el último nodo como siguiente
    ASSERT_EQ(list.tail->prev->next, list.tail);
    // Verifica que el último nodo no tiene un nodo siguiente
    ASSERT_EQ(list.tail->next, nullptr);
}

// Función principal para ejecutar todas las pruebas unitarias
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa Google Test
    return RUN_ALL_TESTS(); // Ejecuta todas las pruebas definidas
}

/* 
Compilar con: 
    clang++ -std=c++14 -g -isystem /usr/include/gtest -pthread /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_doubly_linked_list.cpp -lgtest -lgtest_main -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_doubly_linked_list

Ejecutar con: 
            /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_doubly_linked_list
*/
