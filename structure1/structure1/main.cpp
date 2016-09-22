#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define n 5

struct student
	{
		char *fam;
		int m[3];
		int stip;
	};


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	student group[n]={
		{"Иванов", {3, 4, 6}},
		{"Петров", {7,8,5}},
		{"Сидоров", {6,4,7}},
		{"Жиглов", {9,8,9}},
		{"Сапронов", {6,3,7}}
					 } ;

	int i,j,fond, dolg, stf, av_m;
	fond=0;								// сумма фонда
	puts("Изначальная база данных");
	for (i=0;i<n;i++)
	{
		printf("%10s%5d%5d%5d", group[n].fam, group[n].m[1], group[n].m[2], group[n].m[3]);
	}
	printf ("\n\nЗадолжники:\n");

	for ( i=0;i<n;i++)
	{
		av_m=0; // средний балл студента
		dolg=0; // флажок, должник ли студент, 0 если да, 1 если нет 
		stf=0;  // флажок, получает ли студент стипендию, 0 если получает, 1 если не получает

		for(j=0;j<3;j++)
		{
			if( ((group+i)->m[j]) < 4 ) dolg=1; // проверка на задолженности
			if( ((group+i)->m[j]) < 5 ) stf=1;  // проверка на наличие стипендии 
			av_m += (group+i)->m[j];			// подсчет суммы балов
		}

		av_m /= 3;	// сумма баллов делится на их количество, получается средний балл

		if(dolg) puts ( (group+i)->fam ); // если студент задолжник, его фамилия выводится на экран

		if(!stf)  //если у студента есть стипендия, ее значение прибавляется к фонду
		{
			if (av_m<=8) 
				{
					(group+i)->stip=517000;
					fond+=517000;
				}	
			if (av_m>8 && av_m<=9) 
				{
					(group+i)->stip=900000;
					fond+=900000;
				}	

			if (av_m>9) 
			{
				(group+i)->stip=1000000;
				fond+=1000000;
			}	

		}
		else (group+i)->stip=0;
			
	}
	printf("\nЕжемесячный фонд равен %d рублей", fond);
	_getch();
	return 0;
}