// создать файл ввод из массива  и ввод руками написать функцию просмотра файла void fun(FILE*f) rewind(f) отображение и снова rewind(f) return;
// поменять местами чётный и нечётный элементы т.е. номера 
// нашли максимум его удалили из файла и вывели файл

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <locale.h>
//#include <conio.h>
//#include <io.h>
//#include <Windows.h>
//
//void print_file(FILE*);
//void change_numbers(FILE*);
//void search_max(FILE*);
//
//int main()
//{
//	setlocale(0, "rus");
//	FILE *f;
//	int m[] = {6, 2,3, 4},i;// number;
//
//	if (!(f = fopen("workfile_task1.txt", "w+")))
//	{
//		printf("Файл не удалось открыть!");
//		return 0;
//	}
//
//	for (i = 0; i < sizeof(m)/sizeof(int); i++)
//		fprintf(f, "%d ", m[i]);
//
//	//while (scanf("%d",&number) != '27')
//	//{
//	//fprintf(f, "%c", number);
//	//printf("%c", number);
//	//}
//
//	//print_file(f);
//	rewind(f);
//	//change_numbers(f);
//	int contain1,contain2;
//	long pos1;
//	fscanf(f, "%d", &contain1);
//	fscanf(f, "%d", &contain2);
//
//	while (!feof(f))
//	{
//		//fgetpos(f, &pos1);
//		fseek(f, -3, 1);
//		fprintf(f, "%1d %1d ", contain2, contain1);
//		fscanf(f, "%d", &contain1);
//		fscanf(f, "%d", &contain2);
//	}
//
//	//search_max(f);
//	return 0;
//}
//
//void print_file(FILE* f)
//{
//	int i;
//	long j=ftell(f);
//	rewind(f);
//	while (1)
//	{
//		
//		fscanf(f, "%d", &i);
//		if (!feof(f))
//		printf("%d ", i);
//		else break;
//	}
//	rewind(f);
//	fseek(f,j,0);
//	return;
//}
//
//void change_numbers(FILE* f)
//{
//	int contain1,contain2;
//	long pos1;
//	fscanf(f, "%d", &contain1);
//	fscanf(f, "%d", &contain2);
//
//	while (!feof(f))
//	{
//		//fgetpos(f, &pos1);
//		fseek(f, -3, 1);
//		fprintf(f, "%1d %1d ", contain2, contain1);
//		//fprintf(f, "%d ", contain1);
//		fscanf(f, "%d", &contain1);
//		fscanf(f, "%d", &contain2);
//	}
////	print_file(f);
//	return;
//}
//
//void search_max(FILE *f)
//{
//	int i, max, maxpos, n;
//	rewind(f);
//	fscanf(f, "%d", &max); 
//	i = max;	
//
//	while (!feof(f))
//	{
//		if (i>max)				
//		{
//			max = i;				
//			maxpos = ftell(f);	
//		}
//		fscanf(f, "%d", &i);		
//	}
//
//	maxpos++;					
//	rewind(f);					
//	fseek(f, maxpos, 0);			
//	fscanf(f, "%d", &i);		
//
//	while (!feof(f))				
//	{
//		fseek(f, -3, 1);			
//		fprintf(f, "%d ", i);	
//		fseek(f, 2, 1);			
//		fscanf(f, "%d", &i);	
//	}
//
//	fseek(f, 0, 2);				
//	n = ftell(f);					
//	n -= 2;						
//	_chsize(_fileno(f), n);
//	print_file(f);
//	return;
//}





#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <io.h>
#include <Windows.h>

int main()
{
	FILE *f;
	if(! (f = fopen("Text1.txt", "w+")) )
	{
		printf("ERROR"); 
		_getch();
		return 0;
	}
	int m[]={5, 8, 3, 4, 2, 1, 7, 0, 9, 6};
	for (int i=0; i<10; i++)
		fprintf(f, "%d ", m[i]);
	rewind(f);
	long j=ftell(f);
	int num1, num2;
	fscanf(f,"%d",&num1);
	fscanf(f,"%d",&num2);
	while(!feof(f))
	{
		fseek(f,j,0);
		fprintf(f,"%1d %1d ", num2,num1);
		j=ftell(f);
		fscanf(f,"%d",&num1);
		fscanf(f,"%d",&num2);

	}
	fclose(f);
	return 0;
}