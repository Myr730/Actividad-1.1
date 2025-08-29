
 // ordenamiento parcial (QuickSelect)
 // Autor: Myrka Santiago Lopez A01735601
 // fecha: 2023-11-15

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <algorithm>
#include <cmath>
using namespace std;
using namespace std::chrono;


 //primero se reorganiza el arreglo colocando los elementos menores al pivote a la izquierda y los mayores a la derecha
 //param arr - arreglo de números enteros
 //param left - indice izquierdo del subarreglo
 //param right - indice derecho del subarreglo  
