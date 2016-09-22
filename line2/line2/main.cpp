#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>

struct line
{
	int number;
	struct line *prev;
	struct line *next;
};

void add(line **head, line **tail, int number)
{	
	line *element;
	if(! (*head) )
	{
		if(! ( *head = (line*) calloc(1, sizeof(line)) ) )
		{
			printf("memory allocation error");
			_getch();
			return;
		}
		*tail = *head;
		(*head)->number = number;
	}
	else
	{
		if(! ( element = (line*) calloc(1, sizeof(line)) ) )
		{
			printf("memory allocation error");
			_getch();
			return;
		}
		(*tail)->next = element;
		(*tail)->next->prev = (*tail);
		(*tail) = element;
		(*tail)->next = nullptr;
	}
}
// Delete an element wich number is in interval [n1, n2] 
void DeleteFromLine(line **head, line **tail, int n1, int n2)
{
	if(!(*head))
	{
		puts("null line");
		return;
	}
	if( (*head) == (*tail) && (*head)->number >= n1 && (*head)->number <= n2)
	{
		free(*head);
		head = tail = nullptr;
		return;
	}
	if( (*head)->number >= n1 && (*head)->number <= n2)
	{
		(*head) = (*head)->next;
		free( (*head)->prev );
		(*head)->prev = nullptr;
		return;
	}
	line *element;
	for (element = (*head); element != nullptr && !( element->number >= n1 && element->number <= n2 ); element = element->next);
	if(!element)
	{
		puts("elements not found");
		return;
	}
	if(element->next)
	{
		element->next->prev = element->prev;
		element->prev->next = element->next;
		free(element);
	}
	else
	{
		(*tail) = (*tail)->prev;
		free( (*tail)->next );
		(*tail)->next = nullptr;
	}
	return;
}
// Convert Line to Ring
void LtoR(line *head, line *tail)
{
	head->prev = tail;
	tail->next = head;
}