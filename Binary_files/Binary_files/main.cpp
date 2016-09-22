//здесь все просто. в бинарник кидаем массив и сортируем его не вынимая

#define _CRT_SECURE_NO_WARNINGS
#define sint sizeof(int)

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int swap(FILE *f, int i1, int i2) // меняет местами два интовых числа на местах i1 и i2 в бинарном файле
{
	if(!f) return 1;
	rewind(f);
	int ch1,ch2;

	fseek(f, i1*sint, 0);
	fread(&ch1, sint, 1,f);		// считываем 1-е число
	fseek(f, i2*sint, 0);	
	fread(&ch2, sint, 1,f);		// считываем 2-е число
	fseek(f, i1*sint, 0);
	fwrite(&ch2, sint, 1,f);	// записываем 2-е число на место 1-го
	fseek(f, i2*sint, 0);	
	fwrite(&ch1, sint, 1,f);	// записываем 1-е число на место 2-го
	rewind(f);

	return 0;
}


int main()
{
	FILE *f;
	int arr[]={-6, 7, -4, 8, -3, 0, 7, 10, 3};

	if ( !( f=fopen("sort.dat", "w+b") ) )
	{
		printf("FATAL ERROR IN FILE CREATING");
		_getch();
		return 0;
	}

	fwrite(arr, sint, sizeof(arr)/sint, f);
	rewind(f);

// Блок первоначального вывода

	int i,j;
	puts("sourse file");
	for (i = 0; i < sizeof(arr)/sint && !feof(f); i++)
	{
		fread(&j, sint, 1, f);
		printf("%d  ", j);
	}
	rewind(f);

// Сортировка отбором

	int  min, num, i1;
	for ( i = 0; i < sizeof(arr)/sint-1; i++)
	{
		i1=i;
		fseek(f,i*sint,0);
		fread(&min, sint, 1, f);			// перемещаемся на первый элемент итерации и считываем его
		while (true)
		{
			fread(&num, sint, 1, f);		
			if (feof(f)) break;				// считываем следующий элемент с проверкой выхода из файла
			if(num<=min)					// если следующее число больше максимума
			{
				i1=ftell(f)/sint-1;			// запоминаем его местоположение
				min=num;					// меняем максимум
			}
		}
		rewind(f);
		if (i1!=i)							// если новый максимум находится не там, где первый элемент итерации
			if(swap(f, i, i1))
			{
				printf("FATAL ERROR IN TRANSFERING FILE TO FUNCTION");
				_getch();
			}
	}

// сортировка пузырьком

	//int n1, n2;
	//for (i = 0; i < sizeof(arr)/sint-1; i++)
	//	for (j = sizeof(arr)/sint-1; j > i; j--)
	//	{
	//		fseek(f, (j-1)*sint, 0);
	//		fread(&n1, sint, 1, f);
	//		fread(&n2, sint, 1, f);
	//		if (n1>n2)
	//			if(swap(f, j-1, j))
	//			{
	//				printf("FATAL ERROR IN TRANSFERING FILE TO FUNCTION");
	//				_getch();
	//			}
	//	}


// Блок вывода
	rewind(f);
	puts("\nsorted sourse file");
	for (i = 0; i < sizeof(arr)/sint && !feof(f); i++)
	{
		fread(&j, sint, 1, f);
		printf("%d  ", j);
	}


	fclose(f);
	_getch();
	return 0;

}
