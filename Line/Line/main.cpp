#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>

// structure to work with stack
struct list
{
	int item;
	struct list *next;
};
// structure to work with line
struct line
{
	int number;				// number of the shop
	struct list *stuff;		// stack of the stuff
	struct line *next;		// pointer of the next
};
//
// functions to work with stack

// add an element to stack
void Push(list ** Stack, int Item)
{
	struct list *StackElement = *Stack;									// StackElement remembers the previous stack element
	if( !( *Stack = (struct list *) calloc(1, sizeof(struct list)) ) )	// we allocate memory for new first stack element with allocation check
	{
		puts("Memory can not be allocated");
		return;
	}
	(*Stack)->item = Item;											// after that fill new element with item
	(*Stack)->next = StackElement;										// and the pointer to tne  next stack element
	return;
}
// remove an element from stack
int Pop(struct list **Stack)
{
	struct list *StackElement = *Stack;									// We remember first stack element to another variable
	int Item = (*Stack)->item;										// also we remember the item that it carryed
	*Stack = (*Stack)->next;											// after that we move the pointer to the first elemetn to the next
	free(StackElement);													// and free the memory allocated for the first element
	return Item;														// The function returns a item that was in the "poped" element
}

// functions to work with line

// add an alement to line
void add(line **head, line **tail/*, int number, int amount, ...*/)
{
	system("CLS");
	puts("Addition an element to a line");
	line *element;
	if(! (*head) )
	{
		if(! ( *head = (line*) calloc(1, sizeof(line)) ) )
		{
			printf("Memory allocation error.\nPress any key to return to menu\n");
			_getch();
			return;
		}
		*tail = *head;
		(*head)->stuff = (list*) calloc(1,sizeof(list));
		element = *head;
	}
	else
	{
		if(! ( element = (line*) calloc(1, sizeof(line)) ) )
		{
			printf("Memory allocation error.\nPress any key to return to menu\n");
			_getch();
			return;
		}
		(*tail)->next = element;
		(*tail) = element;
		//element->stuff = (list*) calloc(1,sizeof(list));

	}
	char c = 0; int num;
	puts("number = ");
	scanf("%d", &(element->number));
	puts("Do you want to fill the stack? y/n\n");
	c = _getch();
	while(c != 'y' && c != 'í' && c!='n' && c != 'ò') 
	{
		printf("\nIncorrect command");
		c = _getch();
	}
	if(c == 'y' || c == 'í')
		puts("Filling the stack\n");
	while (c == 'y' || c == 'í')
	{
		printf("Stack element = ");
		while(!scanf("%d", &num))
		{
			puts("Incorrect input\nStack element = ");
			fflush(stdin);
		}

		Push(&(element->stuff), num);
		printf("Continue? y/n\n");
		c = _getch();
		while(c != 'y' && c != 'í' && c!='n' && c != 'ò') 
		{
			printf("\nIncorrect command");
			c=_getch();
		}
	}
	return;
}

// remove an element from the line with searched number(renum)
int replace(line **head, line **tail, int renum)
{
	if(*head == nullptr)
	{
		puts("The line's empty.\n");
		_getch();
		return 1;	// if function returns 1 it means that we can not remove another element with such number from the line
	}

	// we have different variants of places of the element that should be deleted
	// 1) there's only 1 line element, so that we have no any other element of line to replace our stack
	if(*head == *tail)
	{
		if( (*head)->number == renum)
			puts("There's only 1 line element. We have no any other element of line to replace our stack.\n");
		else
			puts("Line element not found.\n");
		_getch();
		return 1;
	}

	line *element;

	// 2) if searched element is in the head(we don't need to change the pointers to this element)
	if( (*head)->number == renum ) // if the search element is in the head, we won't need to change the pointer of a previous line element
	{

		list *stackelement;
		for(stackelement = (*head)->stuff; stackelement->next->next != nullptr;  stackelement = stackelement->next);	// we find the last stackelement of removeable line element
		stackelement->next = (*head)->next->stuff;																// than change the pointer to the end of this stack from nullptr to the pointer to the stack of the element
		(*head)->next->stuff = (*head)->stuff;																	// and change the pointer to stack in the next element to pointer to stack removaeble element.
		// so that we made new stack in the next element that consists of two stacks: first of removeable element and second

		element = (*head);				// after cahnges with stack we delete element in head
		(*head) = ( (*head)->next );
		free(element);
		puts("Element is removed from the head.\n");
		_getch();
		return 0; // function returns 0 if there can be any other elements with this number
	}

	line *prevelement;
	element = (*head)->next;
	prevelement = *head;
	while(element->number != renum && element->next != nullptr)
	{
		element = element->next;
		prevelement = prevelement->next;
	}
	// if we haven't found element in the line
	if(element->number != renum && element->next == nullptr)
	{
		puts("Line element not found.\n");
		_getch();
		return 1;
	}

	list *stackelement;
	for(stackelement = element->stuff; stackelement->next->next != nullptr;  stackelement = stackelement->next);	// stackelement points to the end of stack that belongs to found element
	// 3)if searched element is neither in the head nor in the tail
	if(element->next != nullptr)
	{
		stackelement->next = element->next->stuff;
		element->next->stuff = element->stuff;		// we unite stacks such way that next element carrys both stacks of removed element and its one  
		prevelement->next = element->next;			// after that we remove element
		free(element);
		puts("Element is removed from the center.\n");
		_getch();
		return 0;
	}
	// 4)if searched element is in the tail
	else
	{
		stackelement->next = prevelement->stuff;
		prevelement->stuff = element->stuff;		// we unite stacks such way that previous element carrys both stacks of removed element and its one
		free(*tail);
		*tail = prevelement;
		(*tail)->next = nullptr;
		puts("Element is removed from the tail.\n");
		_getch();
		return 1;
	}
}


// see the line
void seeline(line *head, line *tail)
{
	if(head == nullptr)
	{
		puts("The line is empty");
		_getch();
		return;
	}
	list *stackelement;
	while(head != nullptr)
	{
		printf("Shop #%d\n", (head->number));
		printf("Stuff: ");
		if(!(head->stuff)) printf("<empty>");
		for(stackelement = (head->stuff); stackelement->next != nullptr; stackelement = stackelement->next)
			printf("%d ", (stackelement->item));
		printf("\n\n");
		head = head->next;
	}
	_getch();
	return;
}

int main()
{
	line *head, *tail;
	head = tail = nullptr;
	char c, flag = true;
	int renum;
	while (flag)
	{
		system("CLS");
		printf("[1]   add to line\n");
		printf("[2]   delete from line\n");
		printf("[3]   see line\n");
		printf("[ESC] exit\n");
		c = _getch();
		while( c != '1' && c != '2' && c != '3' && c != 27)
		{
			puts("Incorrect command");
			c = _getch();
		}

		switch (c)
		{
		case '1':
			add(&head, &tail);
			break;
		case '2':
			printf("\nEnter number of the shop to delete");
			scanf("%d", &renum);
			replace(&head, &tail, renum);
			break;
		case '3':
			system("CLS");
			seeline(head, tail);
			break;
		case 27:
			flag = false;
			break;
		default:
			break;
		}
	}
	puts("good bye");
	_getch();
	return 0;
}