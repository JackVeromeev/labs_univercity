#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

char *zvezda(const char *implicant1,const char *implicant2, int length)
{
	char *result;
	int i, counter = 0;
	result=(char*)calloc(length,sizeof(char));
	for (i = 0; i < length; i++)
	{
		if((implicant1[i] == '0' && implicant2[i] == '0') || (implicant1[i] == '0' && implicant2[i] == 'x') || (implicant1[i] == 'x' && implicant2[i] == '0'))
		{
			result[i] = '0';
			continue;
		}
		if((implicant1[i] == '0' && implicant2[i] == '1') || (implicant1[i] == '1' && implicant2[i] == '0'))
		{
			result[i] = 'y';
			counter ++;
			continue;
		}
		if((implicant1[i] == '1' && implicant2[i] == '1') || (implicant1[i] == '1' && implicant2[i] == 'x') || (implicant1[i] == 'x' && implicant2[i] == '1'))
		{
			result[i] = '1';
			continue;
		}
		if(implicant1[i] == 'x' && implicant2[i] == 'x')
		{
			result[i] = 'x';
			continue;
		}
	}
	result[length]='\0';
	return (counter == 0 || counter == 1) ? result : "NULL" ; 
}

int main()
{
	struct element
	{
		char *imp;
		char index;
	} *nabor; 

	int number, length, i, j, number_of_unused;
	char *result;
	printf("number = ");
	scanf("%d", &number);
	printf("size = ");
	scanf("%d", &length);
	number_of_unused = number;
	nabor = (element*)malloc(number*sizeof(element));
	for(i = 0; i < number; i ++)
	{
		((nabor+i)->imp) = (char*) malloc(length*sizeof(char));
		printf("implicant[%0d] = ", i+1);
		fflush(stdin);
		gets( (nabor+i)->imp );
		(nabor+i)->index = 0;
	}
	printf("\n");
	for(i = 0; i < number-1; i ++)
		for(j = i+1; j < number; j ++)
		{
			result = zvezda((nabor+i)->imp, (nabor+j)->imp, length);
			if(result != "NULL")
			{

				printf("%s * %s = ", (nabor+i)->imp, (nabor+j)->imp);
				puts(result);
				if( (nabor+i)->index == 0 )
				{
					(nabor+i)->index = 1;		
					number_of_unused --;
				}
				if( (nabor+j)->index == 0 )
				{
					(nabor+j)->index = 1;		
					number_of_unused --;
				}
			}
		}
	if(number_of_unused)
	{
		puts("\nUnused implicants:");
		for(i = 0; i < number; i++)
			if( (nabor+i)->index == 0 )
				puts( (nabor+i)->imp );
	}
	else
		puts("\nAll implicants have been used");
	char c=0;
	while (c!=27)
		c=_getch();
	return 0;
}