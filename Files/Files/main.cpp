#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <Windows.h>


// ������� 1: ������� ������������ ����� �� �����. ��� ����� �����������
//int main()
//{
//	FILE *f;
//	int m[]={6,1,9,4,7,1,8,2,3,0}, n=10,max,i;
//	fpos_t maxpos;
//	f=fopen("workfile_task1.txt", "w+");
//	for (int i = 0; i < n; i++)
//		fprintf(f,"%d ", m[i]); // ��������� ���� ������� �������
//	rewind(f);
//	fscanf(f,"%d",&max); i=max;	// ��������� ������ �����. ��� ��������� � �� �������������� ��������, � �� ������ �����
//	while(!feof(f))
//	{
//		if(i>max)				// ���� ����� ����� ������ ���������
//		{
//			max=i;				// �� ��������� ��� �� ��������
//			maxpos=ftell(f);	// maxpos ��������� �� ��������� ������ ����� ���������
//		}
//		fscanf(f,"%d",&i);		// ��������� ��������� ����� ��� ���������
//	}
//	maxpos++;					// ������ maxpos ����� ����� ��������� ������
//	rewind(f);					// ���������� ��������� ����� �����
//	fseek(f,maxpos,0);			// ��������� ���� � �����, ���������� �� ����������
//	fscanf_s(f,"%d",&i);		// ��������� ���
//
//	while(!feof(f))				// ���� �� �� �������� ����� �����
//	{
//		fseek(f,-3,1);			// ��������� ���� �� ���������� �����
//		fprintf_s(f,"%d ",i);	// ����� ������ ���� ��������� �����
//		fseek(f,2,1);			// ��������� ���� �� ����� ����� ���� ����
//		fscanf_s(f,"%d",&i);	// ��������� ���
//	}							
//	fseek(f,0,2);				// ��� ��������� ����� �-�� ��������� ���� � �����
//	n=ftell(f);					// ��������� ��� ��������
//	n-=2;						// ��������� �� 2
//	_chsize(_fileno(f),n);		// �������� �����
//	return 0;
//}


// ������� 2 : ����������� ������ ����� � �����
// ������ ��� �� ��������???
//int main()
//{
//	setlocale(0,"rus");
//	FILE *f;
//	char c,c1;
//	fpos_t maxpos;
//	f=fopen("�����", "w+");
//	while((c=(char)_getch())!=27)
//	{
//		fprintf(f,"%c",c);
//		printf("%c",c);
//	}
//	rewind(f);
//	fscanf(f,"%c",&c1);			// ���������� � �1 ������ ������
//	fscanf(f,"%c",&c);			// ��������� ��������� �� ��� ������ - ������ ����� ��������, ������� ���������� ��������
//	for(;!feof(f);)				// ���� �� �� �������� ����� �����
//	{
//		fseek(f,-2,1);			// ��������� ���� �� ���������� ������
//		fprintf(f,"%�",c);	// ����� ������ ���� ��������� �� ���
//		fseek(f,1,1);			// ��������� ���� �� ����� ����� ���� ����
//		fscanf(f,"%c",&c);	// ��������� ���
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