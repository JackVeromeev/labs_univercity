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
		{"������", {3, 4, 6}},
		{"������", {7,8,5}},
		{"�������", {6,4,7}},
		{"������", {9,8,9}},
		{"��������", {6,3,7}}
					 } ;

	int i,j,fond, dolg, stf, av_m;
	fond=0;								// ����� �����
	puts("����������� ���� ������");
	for (i=0;i<n;i++)
	{
		printf("%10s%5d%5d%5d", group[n].fam, group[n].m[1], group[n].m[2], group[n].m[3]);
	}
	printf ("\n\n����������:\n");

	for ( i=0;i<n;i++)
	{
		av_m=0; // ������� ���� ��������
		dolg=0; // ������, ������� �� �������, 0 ���� ��, 1 ���� ��� 
		stf=0;  // ������, �������� �� ������� ���������, 0 ���� ��������, 1 ���� �� ��������

		for(j=0;j<3;j++)
		{
			if( ((group+i)->m[j]) < 4 ) dolg=1; // �������� �� �������������
			if( ((group+i)->m[j]) < 5 ) stf=1;  // �������� �� ������� ��������� 
			av_m += (group+i)->m[j];			// ������� ����� �����
		}

		av_m /= 3;	// ����� ������ ������� �� �� ����������, ���������� ������� ����

		if(dolg) puts ( (group+i)->fam ); // ���� ������� ���������, ��� ������� ��������� �� �����

		if(!stf)  //���� � �������� ���� ���������, �� �������� ������������ � �����
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
	printf("\n����������� ���� ����� %d ������", fond);
	_getch();
	return 0;
}