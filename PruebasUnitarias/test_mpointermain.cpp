// test_mpointer.cpp
#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/Templates/MPointer.h" // Incluye la implementación de MPointer
#include <gtest/gtest.h> // Incluye Google Test para pruebas unitarias

// Prueba para el constructor por defecto de MPointer
TEST(MPointerTest, DefaultConstructor) {
    MPointer<int> ptr;
    ASSERT_EQ(ptr.GetAddress(), nullptr); // Verifica que el puntero sea nullptr
    ASSERT_EQ(ptr.GetRefCount(), 1); // Verifica que el contador de referencias sea 1
}

// Prueba para el constructor que acepta nullptr
TEST(MPointerTest, NullptrConstructor) {
    MPointer<int> ptr(nullptr);
    ASSERT_EQ(ptr.GetAddress(), nullptr); // Verifica que el puntero sea nullptr
    ASSERT_EQ(ptr.GetRefCount(), 1); // Verifica que el contador de referencias sea 1
}

// Prueba para el constructor de copia de MPointer
TEST(MPointerTest, CopyConstructor) {
    MPointer<int> ptr1 = MPointer<int>::New();
    &ptr1 = 42;
    MPointer<int> ptr2(ptr1);
    ASSERT_EQ(ptr1.GetAddress(), ptr2.GetAddress()); // Verifica que ambos punteros apunten al mismo objeto
    ASSERT_EQ(ptr1.GetRefCount(), 2); // Verifica que el contador de referencias sea 2
    ASSERT_EQ(ptr2.GetRefCount(), 2); // Verifica que el contador de referencias sea 2
}

// Prueba para el operador de asignación de MPointer
TEST(MPointerTest, AssignmentOperator) {
    MPointer<int> ptr1 = MPointer<int>::New();
    *ptr1 = 42;
    MPointer<int> ptr2;
    ptr2 = ptr1;
    ASSERT_EQ(ptr1.GetAddress(), ptr2.GetAddress()); // Verifica que ambos punteros apunten al mismo objeto
    ASSERT_EQ(ptr1.GetRefCount(), 2); // Verifica que el contador de referencias sea 2
    ASSERT_EQ(ptr2.GetRefCount(), 2); // Verifica que el contador de referencias sea 2
}

// Prueba para el operador * de MPointer
TEST(MPointerTest, DereferenceOperator) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 42;
    ASSERT_EQ(&ptr, 42); // Verifica que el valor almacenado sea 42
}

// Prueba para el operador & de MPointer
TEST(MPointerTest, AddressOfOperator) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 42;
    ASSERT_EQ(ptr.GetAddress(), ptr.GetAddress()); // Verifica que el operador & devuelva la dirección correcta
}

// Función principal para ejecutar todas las pruebas unitarias
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa Google Test
    return RUN_ALL_TESTS(); // Ejecuta todas las pruebas definidas
}

/*
# Compilar con:
    clang++ -std=c++14 -g -isystem /usr/include/gtest -pthread /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_mpointermain.cpp -lgtest -lgtest_main -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_mpointermain

# Ejecutar con:
            /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_mpointermain
*/
