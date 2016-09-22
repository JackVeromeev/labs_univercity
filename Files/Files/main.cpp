#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <Windows.h>


// задание 1: удалить максимальное число из файла. все числа однозначные
//int main()
//{
//	FILE *f;
//	int m[]={6,1,9,4,7,1,8,2,3,0}, n=10,max,i;
//	fpos_t maxpos;
//	f=fopen("workfile_task1.txt", "w+");
//	for (int i = 0; i < n; i++)
//		fprintf(f,"%d ", m[i]); // заполняем файл числами массива
//	rewind(f);
//	fscanf(f,"%d",&max); i=max;	// считываем первое число. Его принимаем и за первоначальный максимум, и за первое число
//	while(!feof(f))
//	{
//		if(i>max)				// если новое число больше максимума
//		{
//			max=i;				// мы принимаем его за максимум
//			maxpos=ftell(f);	// maxpos указывает на следующий пробел после максимума
//		}
//		fscanf(f,"%d",&i);		// считываем следующее число для срванения
//	}
//	maxpos++;					// теперь maxpos стоит перед следующим числом
//	rewind(f);					// сбрасываем состояние конца файла
//	fseek(f,maxpos,0);			// переводим УТПФ к числу, следующему за максимумом
//	fscanf_s(f,"%d",&i);		// считываем его
//
//	while(!feof(f))				// пока мы не достигли конца файла
//	{
//		fseek(f,-3,1);			// переводим УТПФ на предыдущее число
//		fprintf_s(f,"%d ",i);	// пишем вместо него следующее число
//		fseek(f,2,1);			// переводим УТПФ на число после этих двух
//		fscanf_s(f,"%d",&i);	// считываем его
//	}							
//	fseek(f,0,2);				// для изменения длины ф-ла переводим УТПФ в конец
//	n=ftell(f);					// считываем его значение
//	n-=2;						// уменьшаем на 2
//	_chsize(_fileno(f),n);		// изменяем длину
//	return 0;
//}


// задание 2 : переместить первую букву в конец
// ПОЧЕМУ ОНА НЕ РАБОТАЕТ???
//int main()
//{
//	setlocale(0,"rus");
//	FILE *f;
//	char c,c1;
//	fpos_t maxpos;
//	f=fopen("Мечта", "w+");
//	while((c=(char)_getch())!=27)
//	{
//		fprintf(f,"%c",c);
//		printf("%c",c);
//	}
//	rewind(f);
//	fscanf(f,"%c",&c1);			// запрминаем в с1 первый символ
//	fscanf(f,"%c",&c);			// считываем следующий за ним символ - первый среди сомволов, которые необходимо сдвинуть
//	for(;!feof(f);)				// пока мы не достигли конца файла
//	{
//		fseek(f,-2,1);			// переводим утпф на предыдущий символ
//		fprintf(f,"%с",c);	// пишем вместо него следующий за ним
//		fseek(f,1,1);			// переводим утпф на число после этих двух
//		fscanf(f,"%c",&c);	// считываем его
//	}							
//	fseek(f,-1,2);
//	fprintf(f,"%c",c);
//	fclose(f);
//	return 0;
//}

int main()
{
	setlocale(0, "rus");
	FILE *f;
	if( !(f = fopen("workfile_task3.txt", "r+")) )
	{
		printf("CAN'T OPEN THE FILE\n");
		_getch();
		return 0;
	}
	long begpos, endpos;
	char *s;
	s=(char*)malloc(100*sizeof(char));
	gets(s);
	int i, flag=0;
	char c;
	while (!feof(f) && !flag)
	{
		i=0;
		begpos=ftell(f);
		while(!feof(f) && s[i-1] )
		{
			c=fgetc(f);
			if( c!=s[i]) break;
			i++;
		}

		i--;
		if(c=='\n' && s[i]=='\0')
		{
			flag=1;
			endpos=ftell(f);
		}
		if (flag==0)
			while( (c=fgetc(f))!='\n');
	}
	printf("%d     %d", begpos, endpos);
	fclose(f);
	return 0;
}