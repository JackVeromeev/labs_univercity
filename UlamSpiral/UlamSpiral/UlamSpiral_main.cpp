#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<Windows.h>

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int *arin, **arout, i, j, f=true, var, imax;
	int m, n;

// ббнд M, N
	puts("matrix M x N. M="); scanf_s("%d", &m);
	puts("N="); scanf_s("%d", &n);
// бшдекемхе оюлърх онд люяяхбш
	arin=(int*)malloc(m*n*sizeof(int));
	arout=(int**)malloc(m*sizeof(int*));
	if(!arin || !arout) 
	{
		puts("error");
		_getch();
		return 0;
	}

	for(i=0; i<m && f; i++)
	{
		arout[i]=(int*)malloc(n*sizeof(int));
		if(!arout[i]) f=!f;
	}

	if(!f)
	{
		for(i; i>=0; i--) free(arout[i]);
		free(arout);
		free(arin);
		puts("error");
		_getch();
		return 0;
	}

// ббнд хяундмшу дюммшу

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			//printf("array[%d][%d]=", i, j);
			//scanf_s("%d", arin+i*n+j);
			arin[i*n+j]=(-50+rand()%101);
		}
	}
// бшбнд дкъ опнбепйх
	puts("\n\n\n\nхЯУНДМХЙ:\n");

	for(i=0; i<m; i++)
	{
		puts("\n");
		for(j=0; j<n; j++)
			printf("%3d", *(arin+i*n+j) );
	}
// янпрхпнбйю ндмнлепмнцн люяяхбю люяяхбю лернднл нранпю

	for (i=0; i<m*n; i++)
	{
		imax=i;
		for(j=i; j<m*n; j++)
			if (arin[j]>arin[imax]) imax=j;
		if (imax!=i)
		{
			var=arin[imax];
			arin[imax]=arin[i];
			arin[i]=var;
		}

	}

// оепеохяэ ндмнлепмнцн люяяхбю б люрпхжс он яохпюкх

	 i=j=0; int k=0, md=m, nr=n, mu=1, nl=0;		// m_down, n_right, m_up, n_left
	
	while(k<m*n)
	{		
		for(i,j; j<nr; j++)  
		{
			arout[i][j]=arin[k];
			if(k==(m*n-2)) printf("arout[%d][%d]=arin[%d]=%d", i,j,k,arout[i][j]);
			k++;			
		}
		j--;
		i++;
		nr--;

		for(i,j; i<md; i++) 
		{
			arout[i][j]=arin[k];
			if(k==(m*n-2)) printf("arout[%d][%d]=arin[%d]=%d", i,j,k,arout[i][j]);
			k++;
		}
		i--;
		j--;
		md--;

		for(i,j; j>=nl; j--)
		{
			arout[i][j]=arin[k];
			if(k==(m*n-2)) printf("arout[%d][%d]=arin[%d]=%d", i,j,k,arout[i][j]);
			k++;
		}
		j++;
		i--;
		nl++;

		for(i,j; i>=mu; i--)
		{
			arout[i][j]=arin[k];
			if(k==(m*n-2)) printf("arout[%d][%d]=arin[%d]=%d", i,j,k,arout[i][j]);
			k++;
		}
		i++;
		j++;
		mu++;
	}



	puts("\n\nAS THE RESULT:\n");

	for(i=0; i<m; i++)
	{
		puts("\n\n\n");
		for(j=0; j<n; j++)
			printf("%-8d", arout[i][j] );
	}
	_getch();
	return 0;
}