#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<iostream>
#include<windows.h>
#include<time.h>
#include <locale.h>

/*Дан целочисленный массив, содержащий n элементов.
С использованием модели стека найти сумму элементов,
кратных 3 или 5, предварительно поместив их в стек.*/

struct node
{
	int num;
	node *next;
};
typedef struct node Node;
typedef Node * NodePtr;
void menu();

void push(NodePtr *, int);
int pop(NodePtr *);
int display(NodePtr);
void clear(NodePtr*);
int sum(int*, int i);
int r, n = 0, ch;
int value;
int h;
int i = 0;


int main()
{
	setlocale(0, "rus");
//	SetConsoleCP(1251);					не работают что-то твои сет-консоли
//	SetConsoleOutputCP(1251);
	NodePtr top = nullptr;
	int s;
	printf("Введите размер стека --> ");
	scanf("%d", &r);
	int *arr = (int*)malloc(r*sizeof(int));
	menu();
	printf("\n*************************************************************\nВаш выбор --> ");
	scanf("%d", &ch);
	while (ch != 7)
	{

		switch (ch)

		{
		case 1:
			if (i == 0){
				while (i == 0)
				{

					printf("Введите элемент стека -->");
					fflush(stdin);
					scanf("%d", &value);

					if (value % 3 == 0 || value % 5 == 0)
					{
						push(&top, value);
						arr[i] = value;
						i++;
					}

					break;
				}
			}
			else
			{
				if (i < r)
				{
					printf("Введите элемент стека -->");
					fflush(stdin);
					scanf("%d", &value);
					if (value % 3 == 0 || value % 5 == 0)
					{
						push(&top, value);
						arr[i] = value;
						i++;
						break;
					}
				}
				else printf("нет доступной памяти\n");
			}

			break;
		case 2: if (i == 0)
		{
					printf("Стек пуст\n"); break;
		}
				else { display(top); break; }
		case 3:
			s = sum(arr, i);
			printf("Сумма элементов равна %d ", s);


			break;
		case 4: if (i == 0){
					printf("Стек пуст\n"); break;
		}
				else {
					pop(&top); i--; printf("Удаление прошло успешно!\n"); break;
				}
		case 5: if (i == 0){
					printf("Стек пуст\n"); break;
		}
				else {
					clear(&top); i = 0; printf("Удаление прошло успешно!\n");  break;
				}
		case 6: printf("Выход из программы.\n"); return 0;
		default: printf("Введите корректно номер пункта меню\n");
			menu();
			break;
		}
		printf("\n\n\n\n*************************************************************\n\nВаш выбор --> ");
		scanf("%d", &ch);
	}

	_getch();
	return 0;
}

void menu()
{

	printf("\n   Меню: \n");
	printf("1. Создание первого узла и добавление узлов \n");
	printf("2. Вывод стека на экран\n");
	printf("3. Найти сумму элементов стека\n");
	printf("4. Удаление верхнего элемента стека\n");
	printf("5. Удаление всех элементов стека\n");
	printf("6. Выход\n");

}

void push(NodePtr *top, int value)
{
	NodePtr p;
	p = new node;
	if (p != NULL)
	{

		p->num = value;

		p->next = *top;
		*top = p;
	}
	else printf("нет доступной памяти\n");

}

int pop(NodePtr *top){

	NodePtr p;
	int pv;
	if (top == NULL){
		printf("Стек пуст\n");
		_getch();
		return 1;
	}

	p = *top;
	pv = (*top)->num;
	*top = (*top)->next;
	free(p);



	return 0;
}

int display(NodePtr p)
{
	

	printf("Данные стека\n");
	while (p != NULL)
	{
		printf("%d\n", p->num);
		p = p->next;

	}
	printf("\n");
	_getch();
	return 0;
	

}



void clear(NodePtr *top)
{
	
	while ( (*top) != nullptr)
	{
		pop(top);
	}
	(*top) = nullptr;
	return;
}
/*{
Node *p = top;

if (top == NULL)
{
printf("В стеке нет элементов\n");
_getch();
return 1;
}

else
{
top = top->next;
free(p);
return 0;
}
}*/

int sum(int* arr, int i)
{
	int s=0;
	for (int h = 0; h < i; h++)
		s = s + arr[h];

	return s;
}