#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<Windows.h>

// ���������� ����������� ������� �������
void sort(int *input_array, int length);

// ������� ��������� ����������� ������� � ��������� ������ �� ������� �� ��������� � ������
//�����! ���������� ��������� � �������� ������ ���������
void Spiral(int *input_array, int **output_array, int row_number, int column_number);