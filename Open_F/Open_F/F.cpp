#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


// минимальное произведение будет 
// 1) при умножении максимального отрицательного на максимальный положительный(maxotr*maxpol),
// 2) 2 мин. положительных(min1*min2)
// 3) 2 макс. отрицательных(max1*max2)
// флажком выбора будет наличие отрицательных и положительных чисел, т.е. maxotr<0 && maxpol>0  =>  тогда 1 вариант.
// если все положительные, т.е. maxotr == 0 то 2 вариант
// если все положительные, т.е else от обоих вероятностей, то 3 вариант
// все 3 числа желательно найти за 1 проход по массиву
// не будем придираться к словам "максимальный" и "минимальный"


int main()
{
	int *a, n, i, maxotr=0, maxpol=0, min1, min2, max1, max2, imin1, imax1;
	long long proiz;
	scanf("%d", &n);
	a = (int*) malloc(n*sizeof(int));

	for(i = 0; i < n; i ++)
	{
		scanf("%d", a+i);

		if( !i ) 
		{
			min1=max1=a[i];
			imax1=imin1=i;
		}



		if( a[i] < maxotr ) maxotr = a[i];
		if( a[i] > maxpol ) maxpol = a[i];
		
		if( a[i] >= 0 && a[i] < min1 )
		{
			min1 = a[i];
			imin1 = i;
		}

		if( a[i] <= 0 && a[i] > max1)
		{
			max1 = a[i];
			imax1 = i;
		}
	}

	if ( !imin1 ) min2 = a[1];
	else min2 = a[0];

	if ( !imax1 ) max2 = a[1];
	else max2 = a[0];
	
	for(i = 0; i < n; i ++ )
	{
		if( imin1 != i && a[i] < min2 && a[i] >= 0) min2 = a[i];
		if( imax1 != i && a[i] > max2 && a[i] <= 0) max2 = a[i];
	}

	if( maxotr < 0 && maxpol > 0 ) proiz = ( (long long)maxotr ) * ( (long long)maxpol );	// 1)
	else
	{
		if( !maxotr ) proiz = ( (long long)min1 ) * ( (long long)min2 );					// 2)
		else proiz = ( (long long)max1 ) * ( (long long)max2 );								// 3)
	}
	printf("%d", proiz);
	return 0;
}