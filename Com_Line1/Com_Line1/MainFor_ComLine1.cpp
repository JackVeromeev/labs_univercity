// В этой проге я смотрел, какие аргументы принимает функция main
// Аргументы задаются в Debug -> %Project_name% Properties 
// во вкладке Configuratiom Properties -> Debugging в графе Commanf Arguments


#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(int number_of_strings, char *input_string[], char *sys_directory[])
{
	setlocale(LC_ALL,"russian");
	printf("\nwe entered %d strings\n", number_of_strings);
	printf("input strings:\n");
	for (int i = 0; input_string[i] ; i++)
	{
		puts(input_string[i]);
	}

	printf("\nATTANCION:\n");
	for (int i = 0; sys_directory[i] ; i++)
	{
		printf("\nsys_directory[ %d ] = \"", i);
		printf(sys_directory[i]);
		printf("\"\n");
	}

	_getch();
	return 0;
}