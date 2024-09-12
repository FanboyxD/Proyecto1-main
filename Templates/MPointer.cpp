#include "MPointer.h"

int main() {
    // Crear un nuevo MPointer que recibe un entero
    MPointer<int> myPtr = MPointer<int>::New(); // ref_count = 1
    *myPtr = 5; // guarda el valor de 5
    int valor = &myPtr;
    // Imprime valor, direccion de memoria y numero de referencias a myPtr
    std::cout << "Valor en myPtr: " << valor << ", Contador de referencias: " << myPtr.GetRefCount() << "- Dirección de myPtr: "<< myPtr.GetAddress() <<std::endl; 

    // Crear un nuevo MPointer que recibe un entero
    MPointer<int> myPtr2 = MPointer<int>::New();

    // Se apunta el myPtr2 a la misma direccion que myPtr
    myPtr2 = myPtr;

    // Imprime valor, direccion de memoria y numero de referencias a myPtr2
    std::cout << "Valor en myPtr2: " << &myPtr2 << ", Contador de referencias: " << myPtr2.GetRefCount() << "- Dirección de myPtr2: "<< myPtr2.GetAddress() << std::endl; 

    // Se cambia el valor de myPtr a otro tipo entero
    myPtr = 6;
    // Imprime valor, direccion de memoria y numero de referencias a myPtr2
    std::cout << "Nuevo valor en myPtr: " << &myPtr << ", Contador de referencias: " << myPtr.GetRefCount() << "- Dirección de myPtr: "<< myPtr.GetAddress() << std::endl; 

    // Crear un nuevo MPointer que recibe un entero
    MPointer<int> myPtr3 = MPointer<int>::New();
    *myPtr3 = 14;

    // Imprime valor, direccion de memoria y numero de referencias a myPtr3
    std::cout << "Valor en myPtr3: " << &myPtr3 << ", Contador de referencias: " << myPtr3.GetRefCount() << " - Dirección de myPtr3: "<< myPtr3.GetAddress() << std::endl;

    // Crear un nuevo MPointer que recibe un entero
    MPointer<int> myPtr4 = MPointer<int>::New();

    // Se apunta el myPtr4 a la misma direccion que myPtr2
    myPtr4 = myPtr2;
    // Imprime valor, direccion de memoria y numero de referencias a myPtr4
    std::cout << "Valor en myPtr4: " << &myPtr4 << ", Contador de referencias: " << myPtr4.GetRefCount() << " - Dirección de myPtr4: "<< myPtr4.GetAddress() << std::endl;


    return 0;
}




/* Compilar con: 
    clang++ -std=c++17 -g /home/fabricio/Documents/Prueba\ C/Proyecto1-main/Templates/MPointer.cpp -o /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/MPointer
    
   Ejecutar con: 
                /home/fabricio/Documents/Prueba\ C/Proyecto1-main/build/MPointer
*/
