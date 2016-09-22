#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<Windows.h>
#include"header_for_Spiral_2.h"

void sort(int *ar, int l)
{
	int i, j, imax, var;
	for (i=0; i<l; i++)
	{
		imax=i;
		for(j=i; j<l; j++)
			if (ar[j]>ar[imax]) imax=j;
		if (imax!=i)
		{
			var=ar[imax];
			ar[imax]=ar[i];
			ar[i]=var;
		}

	}
}

void Spiral(int *arin, int **arout, int m, int  n)
{
	int i=0, j=0, k=0, md=m, nr=n, mu=1, nl=0;		// m_down, n_right, m_up, n_left
	
	while(k<m*n)
	{		
		for(i,j; j<nr; j++)  
		{
			arout[i][j]=arin[k];
//			printf("\ni=%d, j=%d, k=%d", i, j, k);
			k++;
//			_getch();
		}
		j--;
		i++;
		nr--;
//		printf("\ni=%d, j=%d, k=%d\nend of first cycle\n", i, j, k);
//		_getch();


		for(i,j; i<md; i++) 
		{
			arout[i][j]=arin[k];
//			printf("\ni=%d, j=%d, k=%d", i, j, k);
			k++;
//			_getch();
		}
		i--;
		j--;
		md--;
//		printf("\ni=%d, j=%d, k=%d\nend of second cycle\n", i, j, k);
//		_getch();


		for(i,j; j>=nl; j--)
		{
			arout[i][j]=arin[k];
//			printf("\ni=%d, j=%d, k=%d", i, j, k);
			k++;
//			_getch();
		}
		j++;
		i--;
		nl++;
//		printf("\ni=%d, j=%d, k=%d\nend of third cycle\n", i, j, k);
//		_getch();


		for(i,j; i>=mu; i--)
		{
			arout[i][j]=arin[k];
//			printf("\ni=%d, j=%d, k=%d", i, j, k);
			k++;
//			_getch();
		}
		i++;
		j++;
		mu++;
//		printf("\ni=%d, j=%d, k=%d\nend of forth cycle\n", i, j, k);
//		_getch();
	}
}