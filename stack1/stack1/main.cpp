#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

// �������� ������, ���������� ���������� �� ��������.
// ��������� ����� ����������� ����� ����������� � ����������� ������

struct list
{
	struct list *next;
};

void push(struct list **);
int pop(struct list **);

int main()
{
	setlocale(0,"rus");
	list *ParanthesisStack = nullptr;
	char *string, symbol;
	int length=40, ParanthesisOpen=0, ParanthesisClose=0, index = 0;
	puts("������� ������:\n");
	string = (char*) malloc(length*sizeof(char));
	fflush(stdin);
	fgets(string, 40, stdin);
	while(string[index])
		switch (string[index++])
		{
		case '(' :
			push(&ParanthesisStack);
			break;
		case ')' :
			ParanthesisOpen += pop(&ParanthesisStack);
			break;
		default:
			break;
		}

	while(ParanthesisStack)
	{
		ParanthesisClose ++;
		pop(&ParanthesisStack);
	}

	if( !(ParanthesisOpen + ParanthesisClose + BracketOpen + BracketClose) )
		printf("\n������� ���������� ��������� �� ��������");
	else
	{
		printf("� ��������� �� �������:\n");
		if(ParanthesisOpen)
			printf("\t%d ����������� ������� ������\n", ParanthesisOpen);
		if(ParanthesisClose)
			printf("\t%d ����������� ������� ������\n", ParanthesisClose);
	}

	_getch();
	return 0;
}

void push(struct list** stack)
{
	struct list *stackel = *stack ;
	if(! ( *stack = (list*)calloc(1,sizeof(list)) ) )
	{
		puts("��� ��������� ������");
		return;
	}

	(*stack)->next = stackel;

	return;
}

int pop(struct list **stack)
{
	if ( (*stack) == NULL ) 
		return 1;
	struct list* stackel = *stack ;
	stackel = *stack;
	(*stack)=(*stack) -> next;
	free(stackel);
	return 0;
}