#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>

#define n 3

enum Type {Row, Column};

void replace(double** matrix, int size, int type, int num1, int num2)
{
	int index;
	double buffer;
	switch (type)
	{
	case Row:
		for (index = 0 ; index < size ; index ++ )
		{
			buffer = matrix[num1][index];
			matrix[num1][index]=matrix[num2][index];
			matrix[num2][index]=buffer;
		}
	case Column:
		for (index = 0 ; index < size ; index ++ )
		{
			buffer = matrix[index][num1];
			matrix[index][num2]=matrix[index][num2];
			matrix[index][num2]=buffer;
		} 

	}

	return;
}


double determinant(double** matrix, int size)
{
	if (size==1) return matrix[0][0]; // if the matrix contain only one element

	if (matrix[size-1][size-1]==0)
	{
		int index=0;
		while (matrix[size-1][index++]==0 && index<size);
		if (index == size) return 0.;	// if the whole string contain only zeros
		else 
		{
			index--;
			replace(matrix, size, Row, index, size-1);
		}
	}

	double coefficient;
	for (int row_index=0; row_index <= (size - 2); row_index ++ )
	{
		coefficient= - matrix[row_index][size-1] / matrix[size-1][size-1];

		for (int column_index = 0; column_index < size; column_index ++)
			matrix[row_index][column_index] += coefficient*matrix[size-1][column_index];

	}
	return matrix[size-1][size-1]*determinant(matrix, size-1);
}

int main()
{
	double **m;
	m=(double**)malloc(n*sizeof(double*));
	for(int i=0;i<n;i++)
		m[i]=(double*)malloc(n*sizeof(double));
	for(int i=0;i<n;i++)
	{
		puts("\n");
		for(int j=0;j<n;j++)
		{
			m[i][j]=(double)(rand()%101-50);
			printf("%05.2lf  ", m[i][j]);
		}
	}
	puts("\n\n");

	double d=determinant(m,n);
	printf("\n%lf",d);
	
	_getch();
	return 0;
}