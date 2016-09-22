/* СОРТИРОВКА МАТРИЦЫ ЗМЕЙКОЙ ВДОЛЬ РЯДОВ
MAX - зафиксирован в нижней правой ячейке. минимум может быть как вверху слева, так и вверху справа        */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<Windows.h>

// Сортировка всего массива от минимума к максимуму пузырьком
void sort(int *mas, int n);

// Переворот нечетных строчек при счете их снизу
void per(int *mas, int m, int n);

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int *mas, m, n, i, j;

	// Ввод размеров матрицы
	puts("Введите размер матрицы\nm=");
	while (!scanf_s("%d", &m))
	{
		puts("Некорректный ввод. Повторите попытку\nm=");
		fflush(stdin);
	}

	puts("\nn=");
	while (!scanf_s("%d", &n))
	{
		puts("Некорректный ввод. Повторите попытку\nn=");
		fflush(stdin);
	}

	// Выделение памяти под массив и ввод его с проверкой
	mas=(int*)malloc(n*m*sizeof(int));

	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
		{
			printf("mas[%d][%d]=", i, j);
			if(!scanf_s("%d", (mas+n*i+j)))
			{
				fflush(stdin);
				puts("Некорректный ввод. Повторите попытку\n");
				j--;
			}

		}

	// Вывод исходного массива
	system("CLS"); 
	for(i=0; i<m; i++)
	{
		puts("\n");
		for(j=0; j<n; j++)
			printf("%4d", *(mas+i*n+j));
	}

	sort(mas, m*n);

	per(mas, m, n);		

	// Вывод конечного массива
	puts("\n\n\n");
	for(i=0; i<m; i++)
	{
		puts("\n");
		for(j=0; j<n; j++)
			printf("%4d", *(mas+i*n+j));
	}

	_getch();
	return 0;
}



// Сортировка всего массива от минимума к максимуму пузырьком
void sort(int *mas, int n)
{
	int c, i, j;
	for (i=0; i<n; i++)
		for (j=0; j<n-1; j++)
			if(*(mas+j)<*(mas+j+1))
			{
				c=*(mas+j);
				*(mas+j)=*(mas+j+1);
				*(mas+j+1)=c;
			}
}


// Переворот нечетных строчек при счете их снизу
void per(int *mas, int m, int n)
{
	int c, i, j;
	for (i=m-1; i>=0; i--)			
	if( i%2!=(m-1)%2 )			
	// если номер последней строки нечетный, то переворачиваются четные строки, и наоборот, если четная, то переворачиваются нечетные строки
		for (j=0; j<n/2; j++)
		{
			c=*(mas+n*i+j);
			*(mas+n*i+j)=*(mas+n*i+n-1-j);
			*(mas+n*i+n-1-j)=c;
		}

}
