## Proyecto1 MPointer

Autor: Fabricio Mena Mejia
Profesor: Luis Alonso Barboza Artavia
Curso: Datos II



# Requisitos
* Extensiones necesarias: clandg, CodeLLDB, Makefile Tools, C/C++, C/C++Extension Pack, CMake, CMake Tools.
* Sistema operativo: Ubuntu 24.04.1 LTS
* Editor de codigo: Visual Studio Code
* Este codigo fue desarrollado en ubuntu por ende es recomendable utilizar este sistema operativo para compilar el proyecto.
* Es recomendable primero crear los archivos de googletest en el proyecto para que a partir de ellos se pueda trabajar en los demas codigos; para ello hay que instalar
las dependencias necesarias, en la terminal del proyecto se deben correr los siguientes comandos: 
~sudo apt-get update
~sudo apt-get install build-essential cmake 
Luego para instalar la libreria de googletest se utiliza el siguiente comando:
~sudo apt-get install libgtest-dev
Y para compilar el codigo fuente se necesitan correr los siguientes comandos:
~cd /usr/src/gtest
~sudo cmake CMakeLists.txt
~sudo make
~sudo cp lib/libgtest*.a /usr/lib
Una vez realizado esto va a ser necesario crear un directorio de compilacion para realizar las pruebas, para esto hay que dirigirse al directorio donde estaran las pruebas unitarias y crearlo con los siguientes comandos:
~mkdir build
~cd build
~cmake ..
~make
Una vez se crea este directorio dentro de nuestra carpeta con pruebas unitarias hay que modificar o crear el archivo CMakeLists.txt, donde se ingresan las configuraciones para que las pruebas corran, donde lo principal a modificar es:
Configuración de Google Test
add_subdirectory(${PROJECT_SOURCE_DIR}/PruebasUnitarias) // reemplazar PruebasUnitarias por el nombre del subdirectorio donde estan las pruebas unitarias

Agregar los archivos de prueba
add_executable(test_quick_sort ${PROJECT_SOURCE_DIR}/PruebasUnitarias/test_quick_sort.cpp) // reemplazar test_quick_sort.cpp por el nombre del programa con las pruebas unitarias

Enlazar con Google Test
target_link_libraries(test_quick_sort gtest gtest_main pthread) // reemplazar test_quick_sort por el nombre del programa con las pruebas unitarias

* El compilador utilizado es clangd, asi que es necesario agregar dicha extension al vs code al igual que la extension de CodeLLDB.
Ademas es recomendable instalarlo desde la terminal mediante el uso del comando ~sudo apt-get install clangd-12.
Despues de descargar esto es necesario deshabilitar las extensiones de c++, ya que es necesario para cambiar de compilador; al realizar este cambio
tambien se deshabilitaran las extensiones de CMake y CMake Tools, pero a pesar de esta si se van a poder ejecutar las pruebas unitarias de GTest.
La eleccion de clangd se dee a que su integracion con linux es muy buena, asi evita ciertos errores a la hora de ejecutar el codigo, pero una desventaja 
es que  hay que compilar y ejecutar el codigo desde la consola, asi que hay que tener bien ubicado el path donde esta el proyecto, para que se pueda 
encontrar el codigo target.

# Compilacion y Ejecucion
Cada codigo tiene un comentario al final donde se indica la version de clangd en la que corren, la ruta de la ubicacion del programa (debe reemplazar esta ruta con su propia ruta donde descargo el proyecto) y el nombre de este.
Primero se abre una terminal desde la ubicacion principal del proyecto, luego se copia y se pega el comando que esta debajo del comentario que dice 
"Compilar con: " en la terminal y se da enter, una vez compilado el programa se ejecuta con el comando que indica la ubicacion del programa (debe reemplazar esta ubicacion con la ruta donde se encuentra descargado el archivo del proyecto que desea ejecutar) seguido de su nombre, el cual se encuentra debajo del comentario de "Ejecutar con:", los resultados de su ejecucion se muestran en el output de la terminal.
