#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	setlocale(0,"rus");
	int i=_getch();
	printf("%d", i);
	//char m[40];
	//fflush(stdin);
	//fgets(m,40,stdin);
	//for (int i = 0; i < 40 && m[i-1]; i++)
	//{
	//	if(m[i])
	//		printf("%c",m[i]);
	//	else
	//		printf("\\0");
	//}
	_getch();
	_getch();
	return 0;
}
