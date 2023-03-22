#include "tp1.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Determina si un número es primo.
 */
bool is_prime(int x) {
  if (x == 0)
    return false;
  if (x == 1)
    return true;
  for (int i = 2; i <= (x / 2); i++) {
    if ((x % i) == 0) {
      return false;
    }
  }
  return true;
}

/*
 * Dado el volumen de un deposito D y el volumen de un producto V
 * la función calcula cuantos productos entran en el depósito.
 */
int storage_capacity(float d, float v) {
  if (d < v) {
    return 0;
  }
  float result = d / v;
  return (int)result;
}

/*
 * Intercambia dos valores de enteros.
 */
void swap(int *x, int *y) {
  if (x != NULL || y != NULL) {
    int aux = *x;
    *x = *y;
    *y = aux;
  }
  return;
}

/*
 * Devuelve el máximo de un arreglo de enteros.
 */
int array_max(const int *array, int length) {
  if (length != 0 || array != NULL) {
    int max = array[0];
    if (length != 1) {
      for (int i = 1; i < length; i++) {
        if (array[i] > max) {
          max = array[i];
        }
      }
    }
    return max;
  }
  return -1;
}

/*
 * Aplica la función a cada elemento de un arreglo de enteros.
 */
void array_map(int *array, int length, int f(int)) {
  if (f == NULL) {
    return;
  }
  if (length != 0) {
    for (int i = 0; i < length; i++) {
      int aux = f(array[i]);
      array[i] = aux;
    }
  }
  return;
}

/*
 * Copia un arreglo de enteros en memoria dinámica.
 * Si el arreglo es NULL devuelve NULL.
 */
int *copy_array(const int *array, int length) {
  if (array == NULL) {
    return NULL;
  }
  int *array2 = (int *)malloc(length * sizeof(int));
  if (array2 == NULL) {
    return NULL;
  }
  for (int i = 0; i < length; i++) {
    array2[i] = array[i];
  }
  return array2;
}

/*
 * Hace bubble sort sobre un arreglo de enteros ascendentemente.
 * Si el arreglo es NULL, no hace nada.
 */
void bubble_sort(int *array, int length) {
  if (length == 0 || array == NULL) {
    return;
  }
  for (int i = 0; i < length - 1; i++)
    for (int j = 0; j < length - i - 1; j++)
      if (array[j] > array[j + 1])
        swap(&array[j], &array[j + 1]);
  return;
}

/*
 * Determina si dos arreglos de enteros son identicamente iguales.
 * En el caso de que alguno sea NULL solo devuelve true si el otro tambien lo
 * es.
 */
bool array_equal(const int *array1, int length1, const int *array2,
                 int length2) {
  if (length1 != length2) {
    return false;
  }
  if (array1 == NULL || array2 == NULL) {
    return array1 == array2;
  }
  for (int i = 0; i < length1; i++) {
    if (array1[i] != array2[i]) {
      return false;
    }
  }
  return true;
}

/*
 * Determina si dos arrays de enteros son análogos a un anagrama para textos (en
 * algun orden particular, son el mismo arreglo). Si alguno es NULL devuelve
 * false.
 */
bool integer_anagrams(const int *array1, int length1, const int *array2,
                      int length2) {
  /*aunque la comparacion de largos ya se hace en array_equal() al hacerla al
   *principio de esta funcion se puede evitar los bubble sort si los largos son
   *distintos
   */
  if (length1 != length2) {
    return false;
  }
  /*array equal puede devolver true si los dos arrays son NULL, por lo que es
   * necesario compararlos
   */
  if (array1 == NULL || array2 == NULL) {
    return false;
  }

  bubble_sort((int *)array1, length1);
  bubble_sort((int *)array2, length2);
  return array_equal(array1, length1, array2, length2);
}

/*
 * Copia un arreglo de arreglos de enteros en memoria dinámica.
 * Si alguno de ellos en NULL, continua siendo NULL.
 * Si el arreglo de arreglos es NULL, devuelve NULL.
 *
 * array_of_arrays: un arreglo de punteros a arreglos de enteros
 * array_lenghts: un arreglo con los largos de cada arreglo en array_of_arrays
 * array_amount: la cantidad de arreglos
 */
int **copy_array_of_arrays(const int **array_of_arrays,
                           const int *array_lenghts, int array_amount) {
  if (array_of_arrays == NULL) {
    return NULL;
  }
  int **array_of_arrays2 = (int **)malloc(array_amount * sizeof(int *));
  if (array_of_arrays2 == NULL) {
    return NULL;
  }
  int *array_lenghts2 = copy_array(array_lenghts, array_amount);
  if (array_lenghts2 == NULL) {
    return NULL;
  }
  for (int i = 0; i < array_amount; i++) {
    if (array_of_arrays[i] == NULL) {
      array_of_arrays2[i] = NULL;
      continue;
    }
    int *aux = copy_array(array_of_arrays[i], array_lenghts[i]);
    if (aux == NULL) {
      free_array_of_arrays(array_of_arrays2, array_lenghts2, i + 1);
      return NULL;
    }
    array_of_arrays2[i] = aux;
  }
  free(array_lenghts2);
  return array_of_arrays2;
}

/*
 * Libera toda la memoria asociada a un arreglo de arreglos.
 *
 * array_of_arrays: un arreglo de punteros a arreglos de enteros
 * array_lenghts: un arreglo con los largos de cada arreglo en array_of_arrays
 * array_amount: la cantidad de arreglos
 */
void free_array_of_arrays(int **array_of_arrays, int *array_lenghts,
                          int array_amount) {
  if (array_of_arrays == NULL || array_lenghts == NULL) {
    return;
  }
  for (int i = 0; i < array_amount; i++) {
    free(array_of_arrays[i]);
  }
  free(array_of_arrays);
  free(array_lenghts);
}