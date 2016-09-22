#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<Windows.h>

// Сортировка одномерного массива отбором
void sort(int *input_array, int length);

// Перенос элементов одномерного массива в двумерный массив по спирали от переферии к центру
//Важно! Количество элементов в матрицах должно совпадать
void Spiral(int *input_array, int **output_array, int row_number, int column_number);