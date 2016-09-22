#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

struct ring
{
	char inf[50];
	ring *next;
};

ring *add(ring *pointer)
{
	system("CLS");
	puts("Adding a ring");
	ring *element;
	if(! (element = (ring*) calloc(1,sizeof(ring))) )		// allocaton check
	{
		puts("Memory allocation error!\nPress any kay to back to menu");
		_getch();
		return pointer;
	}
	printf("Information: ");								// entering information
	gets(element->inf);
	if(!pointer)
	{
		pointer = element;
		pointer->next = pointer;
		return pointer;
	}
	element->next = pointer;
	while (pointer->next != element->next)
		pointer = pointer->next;			// cycle of searching the last element of the ring
	pointer->next = element;				// now new element is the last one
	pointer = element->next;
	return pointer;
}

void seering(ring *pointer)
{
	if(!pointer)
	{
		puts("The ring is empty");
		return;
	}
	static ring *element;
	static int flag;
	if(!flag)			// first function call
	{
		system("CLS");
		element = pointer;
		flag = 1;
	}
	puts(element->inf);
	element = element->next;
	if(element != pointer)
		seering(pointer);
	if(flag)
		flag = 0;
	return;
}

void del(ring **deleted)
{
	static ring *element1;
	static int flag1;
	if(!flag1)
	{
		element1 = *deleted;
		flag1 = 1;
	}
	if(element1->next == *deleted && flag1 == 1)
	{
		element1->next = (*deleted)->next;
		free(*deleted);
		flag1 = 2;
	}
	if (flag1 == 1)
	{
		element1 = element1->next;
		del(deleted);
	}
	return;
}

//function search returns 1 if element's not found
void search(ring **pointer)
{
	static int flag;
	static ring *element;
	static char string[50];
	if(!flag)						// flag == 0 points to the first enter the recursion
	{
		if(!pointer)
		{
			puts("The ring is empty");
			return;
		}
		printf("\nEnter the information to search: ");
		fgets(string, 50, stdin);
		element = *pointer;
		flag = 1;
	}

	if(!strcmp(element->inf, string) && flag == 1)		// flag == 1 means searching state
	{
		if((*pointer)->next == (*pointer))				// if found element is in the pointer and there is only one in the ring
		{
			flag = 2;
			free(*pointer);
			*pointer = nullptr;
			return;
		}

		if(*pointer == element)				// if serched element is in the pointer we need to change it
			*pointer = (*pointer)->next;

		puts("Element is found.\nDelete?");	// user has a choice wether delete found element or not
		char c = 0;
		while( (c = _getch()) != 'y' && c != 'n' && c != 'Y' && c != 'N')
		{
			printf("%c\n", c);
			puts("Incorrect command.");
			fflush(stdin);
		}

		printf("%c", c);
		if(c == 'y' || c == 'Y')
			del(&element);

		flag = 2;							// flag == 2 means the quiting the recursion state because element was found (and probably deleted)
	}
	if(element->next == *pointer && flag == 3)
		flag = 1;							// flag == 1 means the quiting the recursion state because such element isn't found or the ring is empty
	if(flag == 3)
	{
		element = element->next;
		search(pointer, string);
	}
	return flag;
}

int main()
{
	ring *pointer;
	pointer = nullptr;
	char c = 0;
	while(c != '0')
	{
		system("CLS");
		puts("1) add\n2) see\n3) search&del\n0) esc\n");
		while( (c = _getch()) != '1' && c != '2' && c != '3' && c != '0')
		{
			printf("%c\n", c);
			puts("Incorrect command");
			fflush(stdin);
		}
		switch (c)
		{
		case '1': 
			pointer = add(pointer);
			break;
		case '2':
			seering(pointer);
			_getch();
			break;
		case '3':
			search(&pointer);
			_getch();
			break;
		}
	}
	puts("Good bye");
	_getch();
	return 0;
}