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
	fgets(element->inf, 50, stdin);
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
	if(!pointer)					// if the ring is emty
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
	puts(element->inf);			// output of the information
	element = element->next;	// move to the next element
	if(element != pointer)		// while element didn't come back to pointer(start element)
		seering(pointer);		// we call the function

	if(flag)					// if flag is not 0 we make it 0 for correct calling of this function(or other that uses tis flag) next time
		flag = 0;
	return;
}

void del(ring **deleted)
{
	static ring *element1;
	static int flag1;
	if(!flag1)					// first call of the function
	{
		element1 = *deleted;
		flag1 = 1;				// flag1 == 1 means searching the previous element state
	}
	if(element1->next == *deleted && flag1 == 1)	// if it was found 
	{
		element1->next = (*deleted)->next;		// we change the pointer to next elenents excluding deleted element from the ring
		free(*deleted);							// and free memory allocated for thes element
		flag1 = 2;								// flag1 == 2 means quiting the recursion state
	}
	if (flag1 == 1)								// if function is still in searching state
	{
		element1 = element1->next;				// element moves to next element of the ring
		del(deleted);							// and we call function
	}
	if(flag1)									// in the state of quiting we make flag zero
		flag1 = 0;
	return;
}

void search(ring **pointer)
{
	if(!(*pointer))
	{
		puts("The ring is empty");
		return;
	}
	static int flag;
	static ring *element;
	static char string[50];
	if(!flag)						// flag == 0 points to the first enter the recursion
	{
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

		char choice = 0;
		fflush(stdin);
		while( (choice = _getch()) != 'y' && choice != 'n' && choice != 'Y' && choice != 'N')
		{
			printf("%c\n", choice);
			puts("Incorrect command.");
			fflush(stdin);
		}
		printf("%c", choice);
		if(choice == 'y' || choice == 'Y')
			del(&element);
		flag = 2;							// flag == 2 means the quiting the recursion state because element was found (and probably deleted)
	}
	if(element->next == *pointer && flag == 1)
		flag = 3;							// flag == 3 means the quiting the recursion state because such element isn't found
	if(flag == 1)
	{
		element = element->next;
		search(pointer);
	}
	if(flag == 3)
	{
		puts("Element is not found");
	}
	if(flag)
		flag = 0;
	return;
}

int main()
{
	ring *pointer;
	pointer = nullptr;
	char c = 0;
	while(c != '0')
	{
		system("CLS");
		puts("1) add\n2) see\n3) search&del\n0) esc\n");					// main menu
		while( (c = _getch()) != '1' && c != '2' && c != '3' && c != '0')	// entering choise with check
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