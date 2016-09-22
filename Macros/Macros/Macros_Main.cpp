// функция с переменным числом параметров находит суммы целых и нецелых чисел в раздичных введенных массивах
// порядок запрси параметров: кол-во_массивов, кол-во эл-тов первого массива, их тип, элементы массива... и т.д. с остальными массивами через запятую
// типы можно описывать как 0 или Int для целых и 1 или Float для дробных 
// функция описана с использованием макросов

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
#include <conio.h>

enum Type{Int, Float};

float *sum(int,...);

int main()
{
	float *s;
	s=sum(3, 3,0, -1,2,1,  3,1, 5.67,1.998,2.6,  5,0, 56,-60,0,6,0);  
	printf("%05d", (int)s[0]);
	printf("\n%02.3f", s[1]);
	_getch();
	return 0;
}

float* sum(int kl,...)
{
	va_list p;
	va_start(p, kl);
	int t, n;
	float *s;
	s=(float*)malloc(2*sizeof(float)); s[0]=s[1]=0;
	while (kl--)
	{
		n=va_arg(p, int);
		t=va_arg(p, int);
		switch (t)
		{
		case Int:
			{
				while(n--)
				{
					s[0]+=(float)va_arg(p,int);
				}
				break;
			}
		case Float:
			{
				while(n--)
				{
					s[1]+=(float)va_arg(p,double);
				}
				break;
			}
		}
	}
	return s;
}