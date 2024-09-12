#include "gtest/gtest.h" // Incluye Google Test para pruebas unitarias
#include "/home/fabricio/Documents/Prueba C/Proyecto1-main/Templates/MPointer.h" // Incluye la implementación de MPointer

// Caso de prueba para el constructor por defecto
TEST(MPointerTest, DefaultConstructor) {
    MPointer<int> ptr;
    EXPECT_TRUE(!ptr);  // Verifica que el puntero esté inicialmente nulo
}

// Caso de prueba para la función New
TEST(MPointerTest, NewFunction) {
    MPointer<int> ptr = MPointer<int>::New(); // Crea un nuevo MPointer
    *ptr = 5; // Asigna el valor 5
    EXPECT_EQ(&ptr, 5);  // Espera que el valor sea 5
    EXPECT_FALSE(!ptr);  // Espera que el puntero no sea nulo
}

// Caso de prueba para el constructor de copia
TEST(MPointerTest, CopyConstructor) {
    MPointer<int> ptr1 = MPointer<int>::New(); // Crea un nuevo MPointer
    *ptr1 = 10; // Asigna el valor 10
    MPointer<int> ptr2(ptr1); // Crea un nuevo MPointer usando el constructor de copia
    EXPECT_EQ(&ptr2, 10);  // Espera que el valor sea el mismo que en ptr1
    EXPECT_FALSE(!ptr2);   // Espera que el puntero no sea nulo
}

// Caso de prueba para el operador de asignación
TEST(MPointerTest, AssignmentOperator) {
    MPointer<int> ptr1 = MPointer<int>::New(); // Crea un nuevo MPointer
    *ptr1 = 20; // Asigna el valor 20
    MPointer<int> ptr2 = ptr1; // Asigna ptr1 a ptr2 usando el operador de asignación
    EXPECT_EQ(&ptr2, 20);  // Espera que el valor sea 20
    EXPECT_FALSE(!ptr2);   // Espera que el puntero no sea nulo
}

// Caso de prueba para el operador de acceso al valor
TEST(MPointerTest, DereferenceOperator) {
    MPointer<int> ptr = MPointer<int>::New(); // Crea un nuevo MPointer
    *ptr = 30; // Asigna el valor 30
    EXPECT_EQ(&ptr, 30);  // Espera que el valor sea 30
}

// Caso de prueba para el operador flecha
TEST(MPointerTest, ArrowOperator) {
    struct TestStruct {
        int x;
        int y;
    };
    MPointer<TestStruct> ptr = MPointer<TestStruct>::New(); // Crea un nuevo MPointer para TestStruct
    ptr->x = 40; // Asigna 40 a x
    ptr->y = 50; // Asigna 50 a y
    EXPECT_EQ(ptr->x, 40);  // Espera que el valor de x sea 40
    EXPECT_EQ(ptr->y, 50);  // Espera que el valor de y sea 50
}

// Caso de prueba para el Garbage Collector
TEST(MPointerTest, GarbageCollector) {
    size_t initial_count = MPointerGC::Instance().GetPointerCount(); // Obtiene el número inicial de punteros
    {
        MPointer<int> ptr = MPointer<int>::New(); // Crea un nuevo MPointer
        EXPECT_EQ(MPointerGC::Instance().GetPointerCount(), initial_count + 1); // Verifica que el contador haya aumentado
    }
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Espera a que el Garbage Collector ejecute
    EXPECT_EQ(MPointerGC::Instance().GetPointerCount(), initial_count); // Verifica que el contador vuelva al valor inicial
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa Google Test
    return RUN_ALL_TESTS(); // Ejecuta todas las pruebas definidas
}

/* 
Compilar con: 
    clang++ -std=c++14 -g -isystem /usr/include/gtest -pthread /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_mpointerh.cpp -lgtest -lgtest_main -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_mpointerh

Ejecutar con: 
            /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/test_mpointerh
*/
