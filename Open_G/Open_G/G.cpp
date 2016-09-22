#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned short int m,n, *a, i, j, fl=0;
	int swapn = 0;
	
	a = (unsigned short int*)malloc(n*sizeof(unsigned short int));
	for( i = 0; i < n; i ++ )
	{
		scanf("%d", a+i);
		for( j = 1; (j <= m) && (i-j >= 0); j ++)
			if( a[i] != a[i-j] ) 
				swapn ++;
			else fl=1; 
	}
	if(!swapn || fl) 
		swapn ++;
	printf("%d", swapn);
	return 0;
}