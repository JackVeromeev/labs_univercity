/* to read the string, remove all but english letters and write it*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct list
{
	char symbol;
	struct list *next;
};

void Push(struct list**, char);

char Pop(struct list**);

int main()
{
	char string[100];
	list *SymbolStack = NULL;
	puts("Enter a string");
	gets(string);
	int index = strlen(string);
	for(; index >= 0; index --)																					// travel through the string from the last symbol to the first
		if( (string[index] >= 'A'  && string[index] <= 'Z') || (string[index] >= 'a' && string[index] <= 'z') ) // if symbol is latin letter
			Push(&SymbolStack, string[index]);																	// we push it into the stack
	puts("\n");
	while(SymbolStack)
		putchar(Pop(&SymbolStack));																				// and after that we pop them out on the screen
	_getch();
	return 0;
}

void Push(list ** Stack, char Symbol)
{
	struct list *StackElement = *Stack;									// StackElement remembers the previous stack element
	if( !( *Stack = (struct list *) calloc(1, sizeof(struct list)) ) )	// we allocate memory for new first stack element with allocation check
	{
		puts("Memory can not be allocated");
		return;
	}
	(*Stack)->symbol = Symbol;											// after that fill new element with symbol
	(*Stack)->next = StackElement;										// and the pointer to tne  next stack element
	return;
}

char Pop(struct list **Stack)
{
	struct list *StackElement = *Stack;									// We remember first stack element to another variable
	char symbol = (*Stack)->symbol;										// also we remember the symbol that it carryed
	*Stack = (*Stack)->next;											// after that we move the pointer to the first elemetn to the next
	free(StackElement);													// and free the memory allocated for the first element
	return symbol;														// The function returns a symbol that was in the "poped" element
}
