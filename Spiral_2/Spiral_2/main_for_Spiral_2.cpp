#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<Windows.h>
#include"header_for_Spiral_2.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int *arin, **arout, i, j, f=true;
	int m, n;

// ���� M, N
	puts("matrix M x N. M="); scanf_s("%d", &m);
	puts("N="); scanf_s("%d", &n);
// ��������� ������ ��� �������
	arin=(int*)malloc(m*n*sizeof(int));
	arout=(int**)malloc(m*sizeof(int*));
	if(!arin || !arout) 
	{
		puts("FUCK!!!");
		_getch();
		return 0;
	}

	for(i=0; i<m && f; i++)
	{
		arout[i]=(int*)malloc(n*sizeof(int));
		if(!arout[i]) f=!f;
	}

	if(!f)
	{
		for(i; i>=0; i--) free(arout[i]);
		free(arout);
		free(arin);
		puts("FUCK!!!");
		_getch();
		return 0;
	}

// ���� �������� ������

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("array[%d][%d]=", i, j);
			scanf_s("%d", arin+i*n+j);
		}
	}
// ����� ��� ��������
	puts("\n\n\n\n��������:\n");

	for(i=0; i<m; i++)
	{
		puts("\n");
		for(j=0; j<n; j++)
			printf("%3d", *(arin+i*n+j) );
	}
// �������� �������� ������� � ���������
	sort(arin, m*n);
// ��� ���� ����� ��� ��������
	puts("\n\n��������������� ���������:\n");

	for(i=0; i<m; i++)
	{
		puts("\n");
		for(j=0; j<n; j++)
			printf("%3d", *(arin+i*n+j) );
	}
// ������ �������
	Spiral(arin, arout, m, n);

// �������� ������ ��������

	puts("\n\nAS THE RESULT:\n");

	for(i=0; i<m; i++)
	{
		puts("\n");
		for(j=0; j<n; j++)
			printf("%3d", arout[i][j] );
	}

	_getch();
	return 0;
}