#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct	human
{
	char fam[40];				//фамилия
	int birthday;				//год рождения
	char where;					//флажок для места жительства

	union constlivplc						//объединение для разных мест жительства
	{
		struct in_city					//структура города
		{
			char cityname[40];			//название города
			char streetname[40];		//улица
			int housenum;				//дом
		}city;

		struct in_country				//структура для села
		{
			char regionname[40];		//название района
			char countryname[40];		//название поселка
			int housenum;				//дом
		}country;

		struct in_abroadcity			//структура заграничных
		{
			char strana[40];			//название страны
			struct in_city city;		//город в другой стране
		}abroad;
		
	}pmg;
};

struct strin
{
	struct human *spisok;
	int n;
};

enum Where{City='1', Country, Abroad};

struct strin vvod(struct human*, int); // ввод БД

int vvod_human(struct human*, int); // заполнения одной записи БД

void show_db(struct human*, int);  // вывод всей БД на экран

void show_human(struct human*, int);

/*int**/void search_db(struct human* spisok ,int n); // 



int main() 
{
	setlocale(0, "rus");
	char db_opened=false;
	char firstask=0;
	int n=0; // кол-во людей
	char Choose=0;
	struct human *spisok=nullptr;
	puts("Добро пожаловать!\n");
	_getch();
	while (true)
	{
			if(!firstask)
			{
				strin a=vvod(spisok,n);
				spisok=a.spisok;
				n=a.n;
				firstask=1;
			}

			system("CLS");
			printf("В базе данных %d записей", n);
			if(db_opened)
				show_db(spisok,n);
			
			printf("\nВыберите действие для работы с базой данных:\n");

			if(db_opened)
				printf("\n[1]   - Скрыть базу данных");
			else
				printf("\n[1]   - Показать базу данных");

			printf("\n[2]   - Заполнение базы данных");
			printf("\n[2]   - Поиск по базе данных");
			printf("\n[3]   - Поиск и редакция по базе данных");
			printf("\n[4]   - Поиск и удаление из базы данных");
			printf("\n[ESC] - выйти");

			while( ( Choose=_getch() ) !=27 && (Choose<'1' || Choose>'5'))
			{
				printf("\nОшибка ввода\nПожалуйста, повторите команду в соответствии с инструкцией");
				fflush(stdin);
			}

			if(Choose-27) // если клавиша не ESC
			{
				switch (Choose)
				{
				case '1':
					if(db_opened) 
						db_opened=false;
					else 
						db_opened=true;
					break;
				case '2': search_db(spisok,n);
					
					break;

				}
			}
			else
			{
				printf("\nВы точно хотите выйти? Y/N");
				if( (Choose=_getch() )=='Y' || Choose=='y'||Choose=='Н'||Choose=='н')
				{
					free(spisok);
					printf("\nДо свидания.\nНажмите на любую клавишу для выхода");	
					_getch();
					break;
				}
				else
				{
					if(Choose!='N' || Choose!='n' || Choose!='т' || Choose!='т') printf("\nВы нажали на что-то не то, но в целях сохраненности данных\nэто расценивается как нет.");
					printf("\nНажмите любую клавишу для перехода в главное меню");
					_getch();
					
				}
			}
	}
	return 0;

}

struct strin vvod(human *spisok, int n)
{
	system("CLS");
	show_db(spisok,n);
	int i=0;
	//if (!n)
	//{
		printf("\nЗаполнение пустой базы данных.\nКоличество человек:");
		while(!scanf_s("%d", &n) || n<=0)
		{
			printf("Ошибка ввода. Повторите, пожалуйста\n");
			fflush(stdin);
		}
		spisok=(human*)malloc(n*sizeof(human));
	//}
	//else
	//{
	//	printf("Заполнение базы данных");
	//	printf("\nСохранять предыдущие записи? Y/N");
	//	char choose=_getch();
	//	if(choose=='n'||choose=='N'||choose=='т'||choose=='Т')
	//	{
	//		free(spisok);
	//		printf("\nЗаполнение пустой базы данных.\nКоличество человек:");
	//		while(!scanf_s("%d", &n) || n<=0)
	//		{
	//			printf("Ошибка ввода. Повторите, пожалуйста\n");
	//			fflush(stdin);
	//		}
	//		spisok=(human*)malloc(n*sizeof(human));
	//	}
	//	else
	//	{
	//		if(choose!='Y' && choose!='y' && choose!='Н' && choose!='н')
	//			printf("\nВы нажали на что-то не то, но в целях сохраненности данных это расценивается как да.");
	//		printf("\nВведите количество дополнительных записей");
	//		int add_n;
	//		while(!scanf_s("%d", &add_n) || add_n<0)
	//		{
	//			printf("\nОшибка ввода. Повторите, пожалуйста");
	//			fflush(stdin);
	//		}
	//		i=n;printf("n было %d",n);
	//		n=n+add_n;printf("стало %d",n);
	//		spisok=(human*)realloc(spisok,n+1);	
	//	}
	//}
	for (; i < n; i++)
		//if(
			vvod_human(spisok,i);
		//  )
		//{
		//	n=i+1;
		//	spisok=(human*)realloc(spisok,n+1);	//мы переформировываем массив
		//	break;								//и заканчиваем ввод
		//}
	printf("\nНажмите любую клавишу для перехода в главное меню");
	_getch();
	struct strin a;
	a.spisok=spisok;
	a.n=n;
	return a;
}

int vvod_human(human* spisok, int i)
{
	printf("\nЯчейка № %d. Фамилия: " ,(i+1));
	fflush(stdin);
	gets_s((spisok+i)->fam);
	if(!strcmp((spisok+i)->fam,""))
	{
		printf("Введена пустая строка. Заполнение прекращено.");
		return 1;
	}
	printf("Год рождения: ");
	scanf_s("%d", &((spisok+i)->birthday));
	printf("Где проживает житель?\n[1]-в городе\n[2]-в деревне\n[3]-в другой стране\n");
	while (    ( ((spisok+i)->where) = _getch() ) < '1' || ((spisok+i)->where) > '3'   )
	{
		printf("Неправильная команда. Попробуйте еще раз\n");
		fflush(stdin);
	}
	
	switch((spisok+i)->where)
	{
	case City:
		printf("Город: ");
		fflush(stdin);
		gets_s((spisok+i)->pmg.city.cityname);
		printf("Улица: ");
		fflush(stdin);
		gets_s((spisok+i)->pmg.city.streetname);
		printf("Дом № ");
		scanf_s("%d", &((spisok+i)->pmg.city.housenum));
		printf("\n");
		break;

	case Country:

		printf("Район: ");
		fflush(stdin);
		gets_s((spisok+i)->pmg.country.regionname);
		fflush(stdin);
		printf("Поселок: ");
		gets_s((spisok+i)->pmg.country.countryname);

		printf("Дом № ");
		scanf_s("%d", &((spisok+i)->pmg.country.housenum));
		printf("\n");

		break;

	case Abroad:
		
		printf("Страна: ");
		fflush(stdin);
		gets_s((spisok+i)->pmg.abroad.strana);
		fflush(stdin);
		printf("Город: ");
		gets_s((spisok+i)->pmg.abroad.city.cityname);
		fflush(stdin);
		printf("Улица: ");
		gets_s((spisok+i)->pmg.abroad.city.streetname);
		fflush(stdin);
		printf("Дом № ");
		scanf_s("%d", &((spisok+i)->pmg.abroad.city.housenum));
		printf("\n");

		break;
	}
	return 0;
}

void show_db(struct human *spisok, int n)
{
	if(!spisok || !n)
	{
		printf("База данных пуста\n\n");
		return;
	}
	for (int i = 0; i < n; i++)
		show_human(spisok,i);

}

void show_human(human* spisok, int i)
{
	printf("\nЗапись № %d.\n  Фамилия: ", i+1);
	puts( (spisok+i)->fam);
	printf("  Год рождения: %d", ((spisok+i)->birthday));	
    switch ((spisok+i)->where)
	{
	case City:
		printf("\n  Город: ");
		puts((spisok+i)->pmg.city.cityname);
		printf("  Улица: ");
		puts((spisok+i)->pmg.city.streetname);
		printf("  Дом № %d\n",((spisok+i)->pmg.city.housenum));
		break;

	case Country:
		printf("\n  Район: ");
		puts((spisok+i)->pmg.country.regionname);
		printf("  Поселок: ");
		puts((spisok+i)->pmg.country.countryname);
		printf("  Дом № %d\n",(spisok+i)->pmg.country.housenum);
		break;

	case Abroad:	
		printf("\n  Страна: ");
		puts((spisok+i)->pmg.abroad.strana);
		printf("  Город: ");
		puts((spisok+i)->pmg.abroad.city.cityname);
		printf("  Улица: ");
		puts((spisok+i)->pmg.abroad.city.streetname);
		printf("  Дом № %d\n",(spisok+i)->pmg.abroad.city.housenum);
		break;
	}
	return;
}



// O F F I C I A L
//void search_db(human *spisok,int n)
//{
//	system("CLS");
//	printf("\nПоиск по базе данных\nУкажите записи, которые необходимо вывести\n[1]-жители городов\n[2]-жители деревень\n[3]-жители городов за границей");
//	char  choose=_getch();
//	for (int i = 0; i < n; i++)
//		if (choose==(spisok+i)->where)
//			show_human(spisok,i);
//	_getch();
//	return;
//}

/* int* */void search_db(human* spisok,int n)
{
	struct human tosearch={};
	tosearch.fam[0]='\0';
	char flag[7]={false, false, false, false, false, false, false};// флаги учета каждого критерия. 0-имя,1-год рожд, 2-пмж, 3,4,5-строки пмж, 6-число
	char c=0;
	while (c!=13)
	{
		system("cls");
		printf("\nПоиск по базе данных\nВыберите необходимые критерии поиска и нажмите ENTER\n");
		
		printf("[1] - Фамилия         ");
		(flag[0]) ? printf("\tвыбрано\n") : printf("\tне выбрано\n");

		printf("[2] - Год рождения    ");
		(flag[1]) ? printf("\tвыбрано\n") : printf("\tне выбрано\n");
		
		printf("[3] - Место жительства");
		(flag[2]) ? printf("\tвыбрано\n") : printf("\tне выбрано\n");

		while( ( (c=_getch()) < '1' || c > '3' )&&c!=13)
		{
			printf("Неправильная команда. Попробуйте еще раз\n");
			fflush(stdin);
		}
		switch (c)
		{
			case '1':
				flag[0]=(!flag[0]);
				break;
			case '2':
				flag[1]=(!flag[1]);
				break;

			case '3':
				flag[2]=(!flag[2]);
				break;
			default:
				break;
		}
	}
	puts("");
	if(flag[0])
	{
		printf("\nВведите фамилию для поиска: "); fflush(stdin); fgets(tosearch.fam, 40, stdin);
	}
	if(flag[1])
	{
		printf("\nВведите год рождения для поиска: "); scanf_s("%d", &(tosearch.birthday));
	}
	if(flag[2])
	{
		printf("Где проживает житель?\n[1]-в городе\n[2]-в деревне\n[3]-в другой стране\n");
		while( (c=_getch()) < '1' || c > '3')
		{
			printf("Неправильная команда. Попробуйте еще раз\n");
			fflush(stdin);
		}
		switch(c)
		{
		case City:
			c=0;
			while(c!=13)
			{
				system("cls");
				printf("\nПоиск городского жителя по базе данных\nВыберите необходимые критерии поиска и нажмите ENTER\n");
		
				printf("[1] - Название города");
				(flag[4])?printf("\tвыбрано\n"):printf("\tне выбрано\n");

				printf("[2] - Название улицы ");
				(flag[5])?printf("\tвыбрано\n"):printf("\tне выбрано\n");
		
				printf("[3] - Номер дома	 ");
				(flag[6])?printf("\tвыбрано\n"):printf("\tне выбрано\n");

				while( ((c=_getch()) < '1' || c > '3') && c!=13)
				{
					printf("Неправильная команда. Попробуйте еще раз\n");
					fflush(stdin);
				}
				switch (c)
				{
					case '1':
						flag[4]=(!flag[4]);
						break;
					case '2':
						flag[5]=(!flag[5]);
						break;

					case '3':
						flag[6]=(!flag[6]);
						break;
					default:
						break;
				}
			}
			if(flag[4])
			{
				printf("Название города: "); gets(tosearch.pmg.city.cityname);
			}
			if(flag[5])
			{
				printf("Название улицы: "); gets(tosearch.pmg.city.cityname);
			}
			if(flag[6])
			{
				printf("Номер дома: "); scanf("%d", &(tosearch.pmg.city.housenum));
			}
			break;
	
		case Country:
			c=0;
			while(c!=13)
			{
				system("cls");
				printf("\nПоиск сельского жителя по базе данных\nВыберите необходимые критерии поиска и нажмите ENTER\n");
		
				printf("[1] - Название района ");
				(flag[4])?printf("\tвыбрано\n"):printf("\tне выбрано\n");

				printf("[2] - Название деревни");
				(flag[5])?printf("\tвыбрано\n"):printf("\tне выбрано\n");
		
				printf("[3] - Номер дома	  ");
				(flag[6])?printf("\tвыбрано\n"):printf("\tне выбрано\n");
				while( ((c=_getch()) < '1' || c > '3') && c!=13)
				{
					printf("Неправильная команда. Попробуйте еще раз\n");
					fflush(stdin);
				}
				switch (c)
				{
					case '1':
						flag[4]=(!flag[4]);
						break;
					case '2':
						flag[5]=(!flag[5]);
						break;

					case '3':
						flag[6]=(!flag[6]);
						break;
					default:
						break;
				}
			}
			if(flag[4])
			{
				printf("Название района: "); fflush(stdin); fgets(tosearch.pmg.city.cityname, 40, stdin); fflush(stdin);
			}
			if(flag[5])
			{
				printf("Название деревни: "); gets(tosearch.pmg.city.cityname);
			}
			if(flag[6])
			{
				printf("Номер дома: "); scanf("%d", &(tosearch.pmg.city.housenum));
			}
			break;
	
		case Abroad:
			while(c!=13)
			{
				system("cls");
				printf("\nПоиск иностранного жителя по базе данных\nВыберите необходимые критерии поиска и нажмите ENTER\n");
		
				printf("[1] - Название страны");
				(flag[3])?printf("\tвыбрано\n"):printf("\tне выбрано\n");

				printf("[2] - Название города");
				(flag[4])?printf("\tвыбрано\n"):printf("\tне выбрано\n");
		
				printf("[3] - Название улицы ");
				(flag[5])?printf("\tвыбрано\n"):printf("\tне выбрано\n");

				printf("[4] - Номер дома	 ");
				(flag[6])?printf("\tвыбрано\n"):printf("\tне выбрано\n");

				while( ((c=_getch()) < '1' || c > '3') && c!=13)
				{
					printf("Неправильная команда. Попробуйте еще раз\n");
					fflush(stdin);
				}
				switch (c)
				{
					case '1':
						flag[3]=(!flag[3]);
						break;
					case '2':
						flag[4]=(!flag[4]);
						break;
					case '3':
						flag[5]=(!flag[5]);
						break;
					case '4':
						flag[6]=(!flag[6]);
						break;
					default:
						break;
				}
			}
			if(flag[3])
			{
				printf("Название страны: "); gets(tosearch.pmg.abroad.strana);
			}
			if(flag[4])
			{
				printf("Название города: "); gets(tosearch.pmg.abroad.city.cityname);
			}
			if(flag[5])
			{
				printf("Название улицы: "); gets(tosearch.pmg.abroad.city.streetname);
			}
			if(flag[6])
			{
				printf("Номер дома: "); scanf("%d", &(tosearch.pmg.abroad.city.housenum));
			}
			break;
		}
	}
	char flsum = flag[0] + flag[1] + flag[2] + flag[3] + flag[4] + flag[5] + flag[6], flsearchsum;
	int i, j=1, *SearchArray;
	SearchArray=(int*)malloc((n+1)*sizeof(int));
	SearchArray[0]=1;
	for(i=0;i<n;i++)
	{
		flsearchsum=0;
		if((flag[0]) && (!strcmp(tosearch.fam,(spisok+i)->fam))) 
			flsearchsum++;
		if((flag[1])&&(tosearch.birthday == (spisok+i)->birthday))
			flsearchsum++;
		if((flag[2])&&(tosearch.where == (spisok+i)->where))
			flsearchsum++;
		switch (tosearch.where)
		{
		case'1':
			if((flag[4])&&(!strcmp(tosearch.pmg.city.cityname,(spisok+i)->pmg.city.cityname)))
				flsearchsum++;
			if((flag[5])&&(!strcmp(tosearch.pmg.city.streetname,(spisok+i)->pmg.city.streetname)))
				flsearchsum++;
			if((flag[6])&&(tosearch.pmg.city.housenum==(spisok+i)->pmg.city.housenum))
				flsearchsum++;
			break;
		case'2':
			if((flag[4])&&(!strcmp(tosearch.pmg.country.regionname,(spisok+i)->pmg.country.regionname)))
				flsearchsum++;
			if((flag[5])&&(!strcmp(tosearch.pmg.country.countryname,(spisok+i)->pmg.country.countryname)))
				flsearchsum++;
			if((flag[6])&&(tosearch.pmg.country.housenum==(spisok+i)->pmg.country.housenum))
				flsearchsum++;
			break;
		case'3':
			if((flag[3])&&(!strcmp(tosearch.pmg.abroad.strana,(spisok+i)->pmg.abroad.strana)))
				flsearchsum++;
			if((flag[4])&&(!strcmp(tosearch.pmg.abroad.city.cityname,(spisok+i)->pmg.abroad.city.cityname)))
				flsearchsum++;
			if( (flag[5]) && (!strcmp(tosearch.pmg.abroad.city.streetname,(spisok+i)->pmg.abroad.city.streetname)) )
				flsearchsum++;
			if( (flag[6]) && (tosearch.pmg.abroad.city.housenum == (spisok+i) -> pmg.abroad.city.housenum) )
				flsearchsum++;
			break;

		default:
			break;
		}
		if(flsearchsum==flsum)
		{
			SearchArray[j++] = i;
			show_human(spisok, i);
		}
	}
	_getch();
	return;
}