
 // ordenamiento parcial (QuickSelect)
 // Autor: Myrka Santiago Lopez A01735601
 // fecha: 2025-08-29

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
 //param pivotIndex - indice del pivote seleccionado
 
int particionar(vector<int>& arr, int left, int right, int pivotIndex) {
    int valorPivote = arr[pivotIndex]; // almacenar el valor del pivote para comparaciones
    
    swap(arr[pivotIndex], arr[right]); // para el pivote al final 

    // indice para seguir la posición donde colocar elementos menores
    int indiceAlmacenamiento = left;
    
    // comparar todos los números con el pivote
    for (int i = left; i < right; i++) {
        if (arr[i] < valorPivote) {
            // Mover números menores a la izquierda
            swap(arr[i], arr[indiceAlmacenamiento]);
            indiceAlmacenamiento++;
        }
    }
    
    // Poner el pivote en su posición correcta (entre menores y mayores)
    swap(arr[right], arr[indiceAlmacenamiento]);
    
    // Devolver la posición final del pivote
    return indiceAlmacenamiento;
}

