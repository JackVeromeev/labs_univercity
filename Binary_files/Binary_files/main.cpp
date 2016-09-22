//����� ��� ������. � �������� ������ ������ � ��������� ��� �� �������

#define _CRT_SECURE_NO_WARNINGS
#define sint sizeof(int)

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int swap(FILE *f, int i1, int i2) // ������ ������� ��� ������� ����� �� ������ i1 � i2 � �������� �����
{
	if(!f) return 1;
	rewind(f);
	int ch1,ch2;

	fseek(f, i1*sint, 0);
	fread(&ch1, sint, 1,f);		// ��������� 1-� �����
	fseek(f, i2*sint, 0);	
	fread(&ch2, sint, 1,f);		// ��������� 2-� �����
	fseek(f, i1*sint, 0);
	fwrite(&ch2, sint, 1,f);	// ���������� 2-� ����� �� ����� 1-��
	fseek(f, i2*sint, 0);	
	fwrite(&ch1, sint, 1,f);	// ���������� 1-� ����� �� ����� 2-��
	rewind(f);

	return 0;
}


int main()
{
	FILE *f;
	int arr[]={-6, 7, -4, 8, -3, 0, 7, 10, 3};

	if ( !( f=fopen("sort.dat", "w+b") ) )
	{
		printf("FATAL ERROR IN FILE CREATING");
		_getch();
		return 0;
	}

	fwrite(arr, sint, sizeof(arr)/sint, f);
	rewind(f);

// ���� ��������������� ������

	int i,j;
	puts("sourse file");
	for (i = 0; i < sizeof(arr)/sint && !feof(f); i++)
	{
		fread(&j, sint, 1, f);
		printf("%d  ", j);
	}
	rewind(f);

// ���������� �������

	int  min, num, i1;
	for ( i = 0; i < sizeof(arr)/sint-1; i++)
	{
		i1=i;
		fseek(f,i*sint,0);
		fread(&min, sint, 1, f);			// ������������ �� ������ ������� �������� � ��������� ���
		while (true)
		{
			fread(&num, sint, 1, f);		
			if (feof(f)) break;				// ��������� ��������� ������� � ��������� ������ �� �����
			if(num<=min)					// ���� ��������� ����� ������ ���������
			{
				i1=ftell(f)/sint-1;			// ���������� ��� ��������������
				min=num;					// ������ ��������
			}
		}
		rewind(f);
		if (i1!=i)							// ���� ����� �������� ��������� �� ���, ��� ������ ������� ��������
			if(swap(f, i, i1))
			{
				printf("FATAL ERROR IN TRANSFERING FILE TO FUNCTION");
				_getch();
			}
	}

// ���������� ���������

	//int n1, n2;
	//for (i = 0; i < sizeof(arr)/sint-1; i++)
	//	for (j = sizeof(arr)/sint-1; j > i; j--)
	//	{
	//		fseek(f, (j-1)*sint, 0);
	//		fread(&n1, sint, 1, f);
	//		fread(&n2, sint, 1, f);
	//		if (n1>n2)
	//			if(swap(f, j-1, j))
	//			{
	//				printf("FATAL ERROR IN TRANSFERING FILE TO FUNCTION");
	//				_getch();
	//			}
	//	}


// ���� ������
	rewind(f);
	puts("\nsorted sourse file");
	for (i = 0; i < sizeof(arr)/sint && !feof(f); i++)
	{
		fread(&j, sint, 1, f);
		printf("%d  ", j);
	}


	fclose(f);
	_getch();
	return 0;

}
