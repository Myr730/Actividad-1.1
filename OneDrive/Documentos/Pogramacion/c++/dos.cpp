
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

 
int quickSelect(vector<int>& arr, int left, int right, int k) {
    while (true) {
        //cuando el subarreglo tiene un solo elemento
        if (left == right) {
            return arr[left];
        }
        
        // agarrar pivote aleatorio
        int pivotIndex = left + rand() % (right - left + 1);
        
        // partir el arreglo y obtener la nueva posición del pivote
        pivotIndex = particionar(arr, left, right, pivotIndex);
        
        if (k == pivotIndex) {
            return arr[k];
        }
        // si k está en la parte izquierda del pivote
        else if (k < pivotIndex) {
            right = pivotIndex - 1; // se descarta la parte derecha
        }
        // si k está en la parte derecha del pivote
        else {
            left = pivotIndex + 1; //se descarta la parte izquierda
        }
    }
}

int calcularMedianaQuickSelect(vector<int>& datos) {
    int n = datos.size();
    
    if (n % 2 == 1) {
        //para tamaño impar
        return quickSelect(datos, 0, n - 1, n / 2);
    } else {
        //para tamaño par
        int primero = quickSelect(datos, 0, n - 1, n / 2 - 1);
        int segundo = quickSelect(datos, 0, n - 1, n / 2);
        return (primero + segundo) / 2;
    }
}

vector<int> generarDatosAleatorios(int tamaño, int valorMaximo) {
    vector<int> datos(tamaño);
    for (int i = 0; i < tamaño; i++) {
        datos[i] = rand() % valorMaximo;
    }
    return datos;
}

