cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Proyecto1)

# Configuración de Google Test
add_subdirectory(${PROJECT_SOURCE_DIR}/PruebasUnitarias)

include_directories(${PROJECT_SOURCE_DIR}/googletest/googletest/include)

# Agregar los archivos de prueba
add_executable(test_quick_sort ${PROJECT_SOURCE_DIR}/PruebasUnitarias/test_quick_sort.cpp)
add_executable(test_insertion_sort ${PROJECT_SOURCE_DIR}/PruebasUnitarias/test_insertion_sort.cpp)
add_executable(test_bubble_sort ${PROJECT_SOURCE_DIR}/PruebasUnitarias/test_bubble_sort.cpp)
add_executable(test_doubly_linked_list ${PROJECT_SOURCE_DIR}/PruebasUnitarias/test_doubly_linked_list.cpp)
add_executable(test_mpointer ${PROJECT_SOURCE_DIR}/PruebasUnitarias/test_mpointer.cpp)



# Enlazar con Google Test
target_link_libraries(test_quick_sort gtest gtest_main pthread)
target_link_libraries(test_insertion_sort gtest gtest_main pthread)
target_link_libraries(test_bubble_sort gtest gtest_main pthread)
target_link_libraries(test_doubly_linked_list gtest gtest_main pthread)
target_link_libraries(test_mpointer gtest gtest_main pthread)