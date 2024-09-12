#include "gtest/gtest.h" // Incluye Google Test para pruebas unitarias
#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/Templates/DoublyLinkedList.h" // Incluye la implementación de DoublyLinkedList

// Caso de prueba para verificar la creación de un nodo vacío
TEST(NodeTest, DefaultConstructor) {
    Node<int> node; // Crea un nodo sin valor

    // Verifica que el puntero de datos es válido y apunta a nullptr (ya que no se ha asignado un valor)
    ASSERT_NE(node.data, nullptr);

    // Verifica que los punteros next y prev son nullptr
    ASSERT_EQ(node.next, nullptr);
    ASSERT_EQ(node.prev, nullptr);
}

// Caso de prueba para verificar la creación de un nodo con un valor específico
TEST(NodeTest, ValueConstructor) {
    Node<int> node(42); // Crea un nodo con el valor 42

    // Verifica que el puntero de datos no es nullptr
    ASSERT_NE(node.data, nullptr);

    // Verifica que el valor dentro del puntero de datos es 42
    ASSERT_EQ(&node.data, 42);

    // Verifica que los punteros next y prev son nullptr
    ASSERT_EQ(node.next, nullptr);
    ASSERT_EQ(node.prev, nullptr);
}

// Caso de prueba para asignar valores a los punteros next y prev
TEST(NodeTest, PointerAssignment) {
    Node<int> node1(1); // Crea un nodo con el valor 1
    Node<int> node2(2); // Crea otro nodo con el valor 2

    // Asigna node2 como siguiente de node1
    node1.next = MPointer<Node<int>>::New();
    *node1.next = node2;

    // Verifica que el puntero next de node1 apunta a node2
    ASSERT_NE(node1.next, nullptr);
    ASSERT_EQ(&node1.next->data, 2);

    // Asigna node1 como previo de node2
    node2.prev = MPointer<Node<int>>::New();
    *node2.prev = node1;

    // Verifica que el puntero prev de node2 apunta a node1
    ASSERT_NE(node2.prev, nullptr);
    ASSERT_EQ(&node2.prev->data, 1);
}

// Función principal para ejecutar todas las pruebas unitarias
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa Google Test
    return RUN_ALL_TESTS(); // Ejecuta todas las pruebas definidas
}

/* 
Compilar con: 
    clang++ -std=c++14 -g -isystem /usr/include/gtest -pthread /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_node.cpp -lgtest -lgtest_main -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_node

Ejecutar con: 
    /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_node
*/
