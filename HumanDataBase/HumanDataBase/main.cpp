#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct	human
{
	char fam[40];				//�������
	int birthday;				//��� ��������
	char where;					//������ ��� ����� ����������

	union constlivplc						//����������� ��� ������ ���� ����������
	{
		struct in_city					//��������� ������
		{
			char cityname[40];			//�������� ������
			char streetname[40];		//�����
			int housenum;				//���
		}city;

		struct in_country				//��������� ��� ����
		{
			char regionname[40];		//�������� ������
			char countryname[40];		//�������� �������
			int housenum;				//���
		}country;

		struct in_abroadcity			//��������� �����������
		{
			char strana[40];			//�������� ������
			struct in_city city;		//����� � ������ ������
		}abroad;
		
	}pmg;
};

struct strin
{
	struct human *spisok;
	int n;
};

enum Where{City='1', Country, Abroad};

struct strin vvod(struct human*, int); // ���� ��

int vvod_human(struct human*, int); // ���������� ����� ������ ��

void show_db(struct human*, int);  // ����� ���� �� �� �����

void show_human(struct human*, int);

/*int**/void search_db(struct human* spisok ,int n); // 



int main() 
{
	setlocale(0, "rus");
	char db_opened=false;
	char firstask=0;
	int n=0; // ���-�� �����
	char Choose=0;
	struct human *spisok=nullptr;
	puts("����� ����������!\n");
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
			printf("� ���� ������ %d �������", n);
			if(db_opened)
				show_db(spisok,n);
			
			printf("\n�������� �������� ��� ������ � ����� ������:\n");

			if(db_opened)
				printf("\n[1]   - ������ ���� ������");
			else
				printf("\n[1]   - �������� ���� ������");

			printf("\n[2]   - ���������� ���� ������");
			printf("\n[2]   - ����� �� ���� ������");
			printf("\n[3]   - ����� � �������� �� ���� ������");
			printf("\n[4]   - ����� � �������� �� ���� ������");
			printf("\n[ESC] - �����");

			while( ( Choose=_getch() ) !=27 && (Choose<'1' || Choose>'5'))
			{
				printf("\n������ �����\n����������, ��������� ������� � ������������ � �����������");
				fflush(stdin);
			}

			if(Choose-27) // ���� ������� �� ESC
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
				printf("\n�� ����� ������ �����? Y/N");
				if( (Choose=_getch() )=='Y' || Choose=='y'||Choose=='�'||Choose=='�')
				{
					free(spisok);
					printf("\n�� ��������.\n������� �� ����� ������� ��� ������");	
					_getch();
					break;
				}
				else
				{
					if(Choose!='N' || Choose!='n' || Choose!='�' || Choose!='�') printf("\n�� ������ �� ���-�� �� ��, �� � ����� ������������� ������\n��� ������������� ��� ���.");
					printf("\n������� ����� ������� ��� �������� � ������� ����");
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
		printf("\n���������� ������ ���� ������.\n���������� �������:");
		while(!scanf_s("%d", &n) || n<=0)
		{
			printf("������ �����. ���������, ����������\n");
			fflush(stdin);
		}
		spisok=(human*)malloc(n*sizeof(human));
	//}
	//else
	//{
	//	printf("���������� ���� ������");
	//	printf("\n��������� ���������� ������? Y/N");
	//	char choose=_getch();
	//	if(choose=='n'||choose=='N'||choose=='�'||choose=='�')
	//	{
	//		free(spisok);
	//		printf("\n���������� ������ ���� ������.\n���������� �������:");
	//		while(!scanf_s("%d", &n) || n<=0)
	//		{
	//			printf("������ �����. ���������, ����������\n");
	//			fflush(stdin);
	//		}
	//		spisok=(human*)malloc(n*sizeof(human));
	//	}
	//	else
	//	{
	//		if(choose!='Y' && choose!='y' && choose!='�' && choose!='�')
	//			printf("\n�� ������ �� ���-�� �� ��, �� � ����� ������������� ������ ��� ������������� ��� ��.");
	//		printf("\n������� ���������� �������������� �������");
	//		int add_n;
	//		while(!scanf_s("%d", &add_n) || add_n<0)
	//		{
	//			printf("\n������ �����. ���������, ����������");
	//			fflush(stdin);
	//		}
	//		i=n;printf("n ���� %d",n);
	//		n=n+add_n;printf("����� %d",n);
	//		spisok=(human*)realloc(spisok,n+1);	
	//	}
	//}
	for (; i < n; i++)
		//if(
			vvod_human(spisok,i);
		//  )
		//{
		//	n=i+1;
		//	spisok=(human*)realloc(spisok,n+1);	//�� ����������������� ������
		//	break;								//� ����������� ����
		//}
	printf("\n������� ����� ������� ��� �������� � ������� ����");
	_getch();
	struct strin a;
	a.spisok=spisok;
	a.n=n;
	return a;
}

int vvod_human(human* spisok, int i)
{
	printf("\n������ � %d. �������: " ,(i+1));
	fflush(stdin);
	gets_s((spisok+i)->fam);
	if(!strcmp((spisok+i)->fam,""))
	{
		printf("������� ������ ������. ���������� ����������.");
		return 1;
	}
	printf("��� ��������: ");
	scanf_s("%d", &((spisok+i)->birthday));
	printf("��� ��������� ������?\n[1]-� ������\n[2]-� �������\n[3]-� ������ ������\n");
	while (    ( ((spisok+i)->where) = _getch() ) < '1' || ((spisok+i)->where) > '3'   )
	{
		printf("������������ �������. ���������� ��� ���\n");
		fflush(stdin);
	}
	
	switch((spisok+i)->where)
	{
	case City:
		printf("�����: ");
		fflush(stdin);
		gets_s((spisok+i)->pmg.city.cityname);
		printf("�����: ");
		fflush(stdin);
		gets_s((spisok+i)->pmg.city.streetname);
		printf("��� � ");
		scanf_s("%d", &((spisok+i)->pmg.city.housenum));
		printf("\n");
		break;

	case Country:

		printf("�����: ");
		fflush(stdin);
		gets_s((spisok+i)->pmg.country.regionname);
		fflush(stdin);
		printf("�������: ");
		gets_s((spisok+i)->pmg.country.countryname);

		printf("��� � ");
		scanf_s("%d", &((spisok+i)->pmg.country.housenum));
		printf("\n");

		break;

	case Abroad:
		
		printf("������: ");
		fflush(stdin);
		gets_s((spisok+i)->pmg.abroad.strana);
		fflush(stdin);
		printf("�����: ");
		gets_s((spisok+i)->pmg.abroad.city.cityname);
		fflush(stdin);
		printf("�����: ");
		gets_s((spisok+i)->pmg.abroad.city.streetname);
		fflush(stdin);
		printf("��� � ");
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
		printf("���� ������ �����\n\n");
		return;
	}
	for (int i = 0; i < n; i++)
		show_human(spisok,i);

}

void show_human(human* spisok, int i)
{
	printf("\n������ � %d.\n  �������: ", i+1);
	puts( (spisok+i)->fam);
	printf("  ��� ��������: %d", ((spisok+i)->birthday));	
    switch ((spisok+i)->where)
	{
	case City:
		printf("\n  �����: ");
		puts((spisok+i)->pmg.city.cityname);
		printf("  �����: ");
		puts((spisok+i)->pmg.city.streetname);
		printf("  ��� � %d\n",((spisok+i)->pmg.city.housenum));
		break;

	case Country:
		printf("\n  �����: ");
		puts((spisok+i)->pmg.country.regionname);
		printf("  �������: ");
		puts((spisok+i)->pmg.country.countryname);
		printf("  ��� � %d\n",(spisok+i)->pmg.country.housenum);
		break;

	case Abroad:	
		printf("\n  ������: ");
		puts((spisok+i)->pmg.abroad.strana);
		printf("  �����: ");
		puts((spisok+i)->pmg.abroad.city.cityname);
		printf("  �����: ");
		puts((spisok+i)->pmg.abroad.city.streetname);
		printf("  ��� � %d\n",(spisok+i)->pmg.abroad.city.housenum);
		break;
	}
	return;
}



// O F F I C I A L
//void search_db(human *spisok,int n)
//{
//	system("CLS");
//	printf("\n����� �� ���� ������\n������� ������, ������� ���������� �������\n[1]-������ �������\n[2]-������ ��������\n[3]-������ ������� �� ��������");
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
	char flag[7]={false, false, false, false, false, false, false};// ����� ����� ������� ��������. 0-���,1-��� ����, 2-���, 3,4,5-������ ���, 6-�����
	char c=0;
	while (c!=13)
	{
		system("cls");
		printf("\n����� �� ���� ������\n�������� ����������� �������� ������ � ������� ENTER\n");
		
		printf("[1] - �������         ");
		(flag[0]) ? printf("\t�������\n") : printf("\t�� �������\n");

		printf("[2] - ��� ��������    ");
		(flag[1]) ? printf("\t�������\n") : printf("\t�� �������\n");
		
		printf("[3] - ����� ����������");
		(flag[2]) ? printf("\t�������\n") : printf("\t�� �������\n");

		while( ( (c=_getch()) < '1' || c > '3' )&&c!=13)
		{
			printf("������������ �������. ���������� ��� ���\n");
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
		printf("\n������� ������� ��� ������: "); fflush(stdin); fgets(tosearch.fam, 40, stdin);
	}
	if(flag[1])
	{
		printf("\n������� ��� �������� ��� ������: "); scanf_s("%d", &(tosearch.birthday));
	}
	if(flag[2])
	{
		printf("��� ��������� ������?\n[1]-� ������\n[2]-� �������\n[3]-� ������ ������\n");
		while( (c=_getch()) < '1' || c > '3')
		{
			printf("������������ �������. ���������� ��� ���\n");
			fflush(stdin);
		}
		switch(c)
		{
		case City:
			c=0;
			while(c!=13)
			{
				system("cls");
				printf("\n����� ���������� ������ �� ���� ������\n�������� ����������� �������� ������ � ������� ENTER\n");
		
				printf("[1] - �������� ������");
				(flag[4])?printf("\t�������\n"):printf("\t�� �������\n");

				printf("[2] - �������� ����� ");
				(flag[5])?printf("\t�������\n"):printf("\t�� �������\n");
		
				printf("[3] - ����� ����	 ");
				(flag[6])?printf("\t�������\n"):printf("\t�� �������\n");

				while( ((c=_getch()) < '1' || c > '3') && c!=13)
				{
					printf("������������ �������. ���������� ��� ���\n");
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
				printf("�������� ������: "); gets(tosearch.pmg.city.cityname);
			}
			if(flag[5])
			{
				printf("�������� �����: "); gets(tosearch.pmg.city.cityname);
			}
			if(flag[6])
			{
				printf("����� ����: "); scanf("%d", &(tosearch.pmg.city.housenum));
			}
			break;
	
		case Country:
			c=0;
			while(c!=13)
			{
				system("cls");
				printf("\n����� ��������� ������ �� ���� ������\n�������� ����������� �������� ������ � ������� ENTER\n");
		
				printf("[1] - �������� ������ ");
				(flag[4])?printf("\t�������\n"):printf("\t�� �������\n");

				printf("[2] - �������� �������");
				(flag[5])?printf("\t�������\n"):printf("\t�� �������\n");
		
				printf("[3] - ����� ����	  ");
				(flag[6])?printf("\t�������\n"):printf("\t�� �������\n");
				while( ((c=_getch()) < '1' || c > '3') && c!=13)
				{
					printf("������������ �������. ���������� ��� ���\n");
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
				printf("�������� ������: "); fflush(stdin); fgets(tosearch.pmg.city.cityname, 40, stdin); fflush(stdin);
			}
			if(flag[5])
			{
				printf("�������� �������: "); gets(tosearch.pmg.city.cityname);
			}
			if(flag[6])
			{
				printf("����� ����: "); scanf("%d", &(tosearch.pmg.city.housenum));
			}
			break;
	
		case Abroad:
			while(c!=13)
			{
				system("cls");
				printf("\n����� ������������ ������ �� ���� ������\n�������� ����������� �������� ������ � ������� ENTER\n");
		
				printf("[1] - �������� ������");
				(flag[3])?printf("\t�������\n"):printf("\t�� �������\n");

				printf("[2] - �������� ������");
				(flag[4])?printf("\t�������\n"):printf("\t�� �������\n");
		
				printf("[3] - �������� ����� ");
				(flag[5])?printf("\t�������\n"):printf("\t�� �������\n");

				printf("[4] - ����� ����	 ");
				(flag[6])?printf("\t�������\n"):printf("\t�� �������\n");

				while( ((c=_getch()) < '1' || c > '3') && c!=13)
				{
					printf("������������ �������. ���������� ��� ���\n");
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
				printf("�������� ������: "); gets(tosearch.pmg.abroad.strana);
			}
			if(flag[4])
			{
				printf("�������� ������: "); gets(tosearch.pmg.abroad.city.cityname);
			}
			if(flag[5])
			{
				printf("�������� �����: "); gets(tosearch.pmg.abroad.city.streetname);
			}
			if(flag[6])
			{
				printf("����� ����: "); scanf("%d", &(tosearch.pmg.abroad.city.housenum));
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