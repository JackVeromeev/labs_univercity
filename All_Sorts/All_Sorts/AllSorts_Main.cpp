#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<locale.h>
#include<conio.h>

void bubbles(int*,int);
void selection(int*, int);
void insert(int*,int);
void shaker(int*,int);
void shell(int*,int);
void hoare(int*,int,int);

void main()
{
	int *m,n,i;
	n=20;
	m=(int*)malloc(n*sizeof(int));
	if(!m) return;
	for(i=0; i<n;i++)
		m[i]=-50+rand()%101;
	for(i=1;i<n;i++)
		printf("%4d", m[i]);
	puts("\n");
	shaker(m,n);
	for(i=1;i<n;i++)
		printf("%4d", m[i]);
	_getch();
	return;
}

void bubbles(int *m, int n)
{
	int i,j,var;
	 for (i = n - 1; i > 0; i--)
	   for (j = 0; j < i; j++)
	      if (m[j] > m[j + 1])
		  {
			  var=m[j];
			  m[j]=m[j+1];
			  m[j+1]=var;
		  }
	return;
}

void selection(int *m, int n)
{
	int i,j,i1,var;
	for(i=0;i<n-1;i++)
	{
		i1=i;
		for(j=i+1;j<n;j++) 
			if(m[j]<m[i1])i1=j;
		if(i!=i1)
		{
			var=m[i];
			m[i]=m[i1];
			m[i1]=var;
		}

	}
	return;
}

void insert(int *m, int n)
{
	int i,j,var;
	for (i=1;i<n;i++)
	{
		var=m[i];
		for(j=i-1;j>=0 && m[j]>var; j--)
			m[j+1]=m[j];
		m[j+1]=var;
	}
	return;
}

void shaker(int *m, int n)
{
	int i,left=0,right=n-1,b=-1,var;
	while (b!=0)
	{
		b=0;
		for(i=left;i<right;i++)
			if(m[i]>m[i+1])
			{
				var=m[i];
				m[i]=m[i+1];
				m[i+1]=var;
				b=i;
			}
		right=b;
		for(i=right;i>left;i--)
			if(m[i-1]>m[i])
			{
				var=m[i];
				m[i]=m[i-1];
				m[i-1]=var;
				b=i;
			}
		left=b;
	}
}

void shell(int* m, int n)
{
	int var;
	for(int dp=(n+1)/2;dp>0;dp/=2)
		for(int i=dp;i<n;i++)
			for(int j=i-dp ; j>0 && m[j]>m[j+dp]; j-=dp)
			{
				var=m[j];
				m[j]=m[j+dp];
				m[j+dp]=var;
			}
}

void hoare(int*m,int l,int r)
{
	int i=l,j=r,av=m[(l+r+1)/2], var;
	do
	{
		while(m[i]<av)i++;
		while(m[j]>av)j--;
		if(i<=j)
		{
			var=m[i];
			m[i]=m[j];
			m[j]=var;
			i++; j--;
		}
	} while (i<=j);
	if (i<r) hoare(m,i,r);
	if (j>l) hoare(m,l,j);
	return;
}