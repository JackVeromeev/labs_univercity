#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include<math.h>

//struct bitchar
//{
//	unsigned int i1:1, i2:1, i3:1, i4:1, i5:1, i6:1, i7:1, i8:1;
//};

struct delenie_na4
{
	unsigned int i:2;
};

struct delenie_na2
{
	unsigned int i:1;
};

union delenie
{
	int n;
	delenie_na2 i2;
	delenie_na4 i4;
};

struct bitint
{
	unsigned i1:1, i2:1, i3:1, i4:1, i5:1, i6:1, i7:1, i8:1, i9:1, i10:1, i11:1, i12:1, i13:1, i14:1, i15:1, i16:1, i17:1, i18:1, i19:1, i20:1, i21:1, i22:1, i23:1, i24:1, i25:1, i26:1, i27:1, i28:1, i29:1, i30:1, i31:1, i32:1;
};



int main()
{
	setlocale(0, "rus");

// ÇÀÄÀ×À 1 ÄÂÎÈ×ÍÛÉ AÑÊÈ-ÊÎÄ ÑÈÌÂÎËÀ

	//unsigned char c;
	//bitchar *b;
	//b=(bitchar*)&c;
	//puts("Ââåäèòå áóêâó");
	//c=getchar();
	//b=(bitchar*)&c;
	//printf("\nÑèìâîë: %c, åãî ASCII-êîä: %d, Áèòîâàÿ èíòåðïðèòàöèÿ: %d%d%d%d%d%d%d%d", c, c, b->i8, b->i7, b->i6, b->i5 , b->i4, b->i3, b->i2, b->i1);
	
// ÇÀÄÀ×À 2 ÄÅËÅÍÈÅ ÍÀ 2 È 4

	//int a;
	//puts("ââåäèòå ÷èñëî");
	//scanf_s("%d", &a);
	//delenie_na4 *x;
	//delenie_na2 *y;
	//x=(delenie_na4*)&a;
	//y=(delenie_na2*)&a;
	//printf("\nîñòàòîê îò äåëåíèÿ íà 4=%d", x->i);
	//printf("\nîñòàòîê îò äåëåíèÿ íà 2=%d", y->i);

// ÇÀÄÀ×À 3 ÒÎ ÆÅ ÑÀÌÎÅ, ÍÎ ÇÀ 1 ÏÅÐÅÌÅÍÍÓÞ

	//delenie a;
	//puts("ââåäèòå ÷èñëî");
	//scanf_s("%d", &(a.n));
	//printf("\nîñòàòîê îò äåëåíèÿ íà 4=%d", a.i4.i);
	//printf("\nîñòàòîê îò äåëåíèÿ íà 2=%d", a.i2.i);

	int i;
	bitint *a;
	scanf_s("%d", &i);
	a=(bitint*)&i;
	int b=i;
	printf("\n\n%-d\n%d %d %d %d  %d %d %d %d  %d %d %d %d  %d %d %d %d  %d %d %d %d   %d %d %d %d  %d %d %d %d  %d %d %d %d",i, a->i32, a->i31, a->i30, a->i29, a->i28, a->i27, a->i26, a->i25, a->i24, a->i23, a->i22, a->i21, a->i20, a->i19, a->i18, a->i17, a->i16, a->i15, a->i14, a->i13, a->i12, a->i11, a->i10, a->i9, a->i8, a->i7, a->i6, a->i5, a->i4, a->i3, a->i2, a->i1);
	if(a->i32)
	{
		a->i32=0;
		i=(int)pow(2.,31)-i;
	}
	printf("\n\n%+d\n%d %d %d %d  %d %d %d %d  %d %d %d %d  %d %d %d %d  %d %d %d %d   %d %d %d %d  %d %d %d %d  %d %d %d %d",i, a->i32, a->i31, a->i30, a->i29, a->i28, a->i27, a->i26, a->i25, a->i24, a->i23, a->i22, a->i21, a->i20, a->i19, a->i18, a->i17, a->i16, a->i15, a->i14, a->i13, a->i12, a->i11, a->i10, a->i9, a->i8, a->i7, a->i6, a->i5, a->i4, a->i3, a->i2, a->i1);
	_getch();
	return 0;
}

