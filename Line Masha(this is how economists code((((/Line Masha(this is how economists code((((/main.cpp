/*����� ������������� ���������� ������ a �� n ���������. ��������� � ������� ������ �������� � ����� �� �����. ���������� ������� ������ �� �����.*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<iostream>
#include<malloc.h>
#include<time.h>
#include<windows.h>
#include<locale.h>

struct queueNode {
	int data;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

int a[100], n = 0, size, sum = 0, i = 0, elem, b[100];

void menu(void);

int add(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value);

int del_first(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);

void Free(QueueNodePtr *currentPtr);

void print(QueueNodePtr currentPtr);

int isEmpty(QueueNodePtr headPtr);

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
	printf("������� ������ ������� ->");
	scanf("%d", &size);
	printf("\n����:\n");
	QueueNodePtr headPtr = nullptr;
	QueueNodePtr tailPtr = nullptr;
	int choice;


	menu();
	printf("\n��� ����� --> ");
	scanf("%d", &choice);
	while (choice != 6)
	{
		switch (choice)
		{
		case 1:
			printf("������ :\n");
			for (i = 0; i < size; i++)
			{

				scanf("%d", &a[i]);
				b[i] = a[i];
				while (b[i]>10 || b[i] < -10)
				{
					b[i] = b[i] / 10;
				}
				if (b[i] == a[i] % 10 && a[i]>10) add(&headPtr, &tailPtr, a[i]);

			}
			printf("%d ", a[i]);


			break;
		case 2:
			if (!isEmpty(headPtr))
			{

				elem = del_first(&headPtr, &tailPtr);
				printf("������� %d ������\n", elem);
			}
			else printf("������� �����.\n");
			break;
		case 3:

			print(headPtr);
			break;
		case 4:
			printf("������ ����� ����, ������������ ������� \n");
			for (i = 0; i < size; i++)
			{
				{
					b[i] = a[i];
					while (b[i]>10 || b[i]<-10)
					{
						b[i] = b[i] / 10;
					}
					if (b[i] == a[i] % 10)
					{
						if (a[i] < 0)
						{
							a[i] = a[i] * -1;
							sum = sum + (a[i] / 100) % 10;
						}
							
						else sum = sum + (a[i] % 100) / 10;
					}
				}
			}
			printf("����� ����, ������������ ������� --> %d\n", sum);
			break;
		case 5:
			Free(&headPtr);
			sum = 0;
			break;
		default:
			printf("������� ��������� ���� ����.\n\n");
			menu();
			break;
		}
		printf("\n\n\n****************************************************\n\n��� �����? ->");
		scanf("%d", &choice);
	}
	printf("����� �� ���������.\n");
	return 0;
}


void menu(void)
{
	printf("1. �������� ������� � �������\n"
		"2. ������� ������� �� �������\n"
		"3. ������ ������� \n"
		"4. ��������� �������\n"
		"5. �������� �������\n"
		"6. �����\n");
}


int add(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value)
{
	QueueNodePtr newPtr;
	newPtr = (QueueNodePtr)malloc(sizeof(QueueNode));
	if (newPtr != nullptr)
	{
		newPtr->data = value;
		newPtr->nextPtr = nullptr;
		if (isEmpty(*headPtr))
		{
			*headPtr = newPtr;
		}
		else
		{
			(*tailPtr)->nextPtr = newPtr;
		}
		*tailPtr = newPtr;
	}
	else
	{
		printf("����� %d �� ���������. ��� ��������� ������.\n", value);
	}
	return sum;
}



void Free(QueueNodePtr *currentPtr)
{
	QueueNodePtr t;
	while ( (*currentPtr) != nullptr)
	{
		t = *currentPtr;
		(*currentPtr) = (*currentPtr)->nextPtr;
		free(t);
	}
	(*currentPtr) = nullptr;
	printf("������� �������.\n");

}



void print(QueueNodePtr currentPtr)
{

	if (currentPtr == nullptr)
		printf("������� �����.\n");
	else
	{
		printf("�������:\n");
		while (currentPtr != nullptr)
		{
			printf("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;

		}


		printf("\n");
	}

}

int isEmpty(QueueNodePtr headPtr)
{
	return headPtr == nullptr;
}

int del_first(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{

	QueueNodePtr temp;
	int value;
	value = (*headPtr)->data;
	temp = *headPtr;
	*headPtr = (*headPtr)->nextPtr;
	if (*headPtr == nullptr) *tailPtr = nullptr;
	free(temp);
	return value;
}