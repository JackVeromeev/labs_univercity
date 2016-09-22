#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void copy_stud(struct student*, struct student*);


struct student
	{
		char *fam;
		int m[3];
		int stip;
	};

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int n;

	//n=5;
	//student group[5]={
	//	{"Иванов", {3, 6, 6}},
	//	{"Петров", {7,8,5}},
	//	{"Сидоров", {2,3,7}},
	//	{"Жиглович", {9,3,3}},
	//	{"Сапроненко", {6,3,5}}
	//				 };
	student *group;
	int i,j,fond, dolg, stf; float av_m;

	puts("Сколько студентов?");
	scanf_s("%d", &n);				// n - кол-во студентов
	group=(student*)malloc(n*sizeof(student));

	for (i = 0; i < n; i++)			// мы вводим данные о студентах: фамилию и 3 оценки
	{
		printf("\nСтудент №%d\nФамилия:");
		fflush(stdin);
		fgets((group+i)->fam,100,stdin);
		if (!strcmp((group+i)->fam, "")) // если введена пустая фамилия
		{
			n=i+1;
			group=(student*)realloc(group,n);	//мы переформировываем массив
			break;								//и заканчиваем ввод
		}

		for (j = 0; j < 3; j++)
		{
			printf("оценка %d:", (j+1));
			scanf_s("%d", &((group+i)->m[j]));
		}
	}


	fond=0;								// сумма фонда
	puts("Изначальная база данных");
	for (i=0;i<n;i++)
	{
		puts( (group+i)->fam );
		printf("%5d%5d%5d\n", (group+i)->m[0], (group+i)->m[1], (group+i)->m[2] );
	}

	printf ("\n\nЗадолжники:\n");

	for ( i=0;i<n;i++)
	{
		av_m=0.; // средний балл студента
		dolg=0; // флажок, должник ли студент, 0 если нет, иначе говорит о кол-ве задолженностей 
		stf=0;  // флажок, получает ли студент стипендию, 0 если получает, 1 если не получает

		for(j=0;j<3;j++)
		{
			if( ((group+i)->m[j]) < 4 ) dolg=1; // проверка на задолженности
			if( ((group+i)->m[j]) < 5 ) stf=1;  // проверка на наличие стипендии 
			av_m +=(float)( (group+i)->m[j]);			// подсчет суммы балов
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




	for ( i = 0; i < n; i++)	
	{
		dolg=0;
		for(j=0;j<3;j++)
		{
			if( ((group+i)->m[j]) < 4 ) dolg=dolg+1; // проверка на задолженности
		}

		if (dolg>1)
		{
			for(j=i;j<n-1;j++)
				copy_stud((group+j),(group+j+1));
			i--;
			n--;
		}
		
	}

	puts("\n\nИзмененная база данных");
	for (i=0;i<n;i++)
	{
		puts( (group+i)->fam );
		printf("%5d%5d%5d\n", (group+i)->m[0], (group+i)->m[1], (group+i)->m[2] );
	}

	printf("\n\nЕжемесячный фонд равен %d рублей", fond);
	_getch();
	return 0;
}

void copy_stud(struct student *s1, struct student *s2)   // s1 = s2;
{
	s1->fam=s2->fam;
	for(int i = 0; i<3; i++)
		s1->m[i]=s2->m[i];
	s1->stip=s2->stip;
}