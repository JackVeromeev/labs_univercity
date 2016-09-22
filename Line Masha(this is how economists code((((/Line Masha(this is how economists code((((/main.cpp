/*Задан целочисленный одномерный массив a из n элементов. Поместить в очередь четные элементы и найти их сумму. Содержимое очереди выдать на экран.*/
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
	printf("Введите размер массива ->");
	scanf("%d", &size);
	printf("\nМеню:\n");
	QueueNodePtr headPtr = nullptr;
	QueueNodePtr tailPtr = nullptr;
	int choice;


	menu();
	printf("\nВаш выбор --> ");
	scanf("%d", &choice);
	while (choice != 6)
	{
		switch (choice)
		{
		case 1:
			printf("Массив :\n");
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
				printf("Элемент %d удален\n", elem);
			}
			else printf("Очередь пуста.\n");
			break;
		case 3:

			print(headPtr);
			break;
		case 4:
			printf("Найдем сумму цифр, обозначающих десятки \n");
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
			printf("Сумма цифр, обозначающих десятки --> %d\n", sum);
			break;
		case 5:
			Free(&headPtr);
			sum = 0;
			break;
		default:
			printf("Введите корректно пунк меню.\n\n");
			menu();
			break;
		}
		printf("\n\n\n****************************************************\n\nВаш выбор? ->");
		scanf("%d", &choice);
	}
	printf("Выход из программы.\n");
	return 0;
}


void menu(void)
{
	printf("1. Добавить элемент в очередь\n"
		"2. Удалить элемент из очереди\n"
		"3. Печать очереди \n"
		"4. Выполнить задание\n"
		"5. Очистить очередь\n"
		"6. Выход\n");
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
		printf("Число %d не добавлено. Нет доступной памяти.\n", value);
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
	printf("Очередь очищена.\n");

}



void print(QueueNodePtr currentPtr)
{

	if (currentPtr == nullptr)
		printf("Очередь пуста.\n");
	else
	{
		printf("Очередь:\n");
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