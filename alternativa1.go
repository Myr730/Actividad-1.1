package main

import (
	"fmt"
	"math"
	"math/rand"
)

func mergeSort(array []int) []int {
	if len(array) <= 1 {
		return array
	}
	mitad := len(array) / 2
	izquierda := mergeSort(array[:mitad])
	derecha := mergeSort(array[mitad:])
	return merge(izquierda, derecha)
}

func merge(izquierda, derecha []int) []int {
	result := make([]int, 0, len(izquierda)+len(derecha))
	i, j := 0, 0
	for i < len(izquierda) && j < len(derecha) {
		if izquierda[i] < derecha[j] {
			result = append(result, izquierda[i])
			i++
		} else {
			result = append(result, derecha[j])
			j++
		}
	}
	result = append(result, izquierda[i:]...)
	result = append(result, derecha[j:]...)
	return result
}

func reordenar(size int) []int {
	data := make([]int, size)
	for i := 0; i < size; i++ {
		data[i] = i
	}
	rand.Shuffle(size, func(i, j int) {
		data[i], data[j] = data[j], data[i]
	})
	return data
}

func calculaMediana(sorted []int) float64 {
	n := len(sorted)
	if n%2 == 0 {
		return float64(sorted[n/2-1]+sorted[n/2]) / 2.0
	}
	return float64(sorted[n/2])
}

func main() {
	exponente := 20
	size := int(math.Pow(2, float64(exponente)))
	data := reordenar(size)
	sorted := mergeSort(data)
	mediana := calculaMediana(sorted)
	fmt.Println(mediana)
}
