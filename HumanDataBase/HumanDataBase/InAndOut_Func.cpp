#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>
#include"InAndOutHead.h"



//void safe_input(enum Type k,int border,...)
//{
//	va_list p;
//	va_start(p,border);
//	switch (k)
//
//
//	{// I N T E G E R
//	case Int:
//		int var;
//		if(border==-1)								// var can take values form -INF to HighLim 
//		{
//			int HighLim=va_arg(p,int);
//			while (!scanf_s("%d",&var) || var>HighLim)
//			{
//				printf("Неверный ввод. Побробуйте еще раз\n");
//				fflush(stdin);
//			}
//			return (void)var;
//			break;
//		}
//		if(border==0)
//		{
//			int LowLim=va_arg(p,int);
//			int HighLim=va_arg(p,int);
//			if(LowLim<=HighLim)					//var can take values form LowLim to HighLim 
//			{
//				while (!scanf_s("%d",&var) ||var<LowLim || var>HighLim)
//				{
//					printf("Неверный ввод. Побробуйте еще раз\n");
//					fflush(stdin);
//				}
//				return (void)var;
//				break;
//			}
//			if(LowLim>HighLim)					//var can take ANY value excluding values from LowLim to HighLim
//			{
//				while (!scanf_s("%d",&var)||(var>=LowLim && var<=HighLim))
//				{
//					printf("Неверный ввод. Побробуйте еще раз\n");
//					fflush(stdin);
//				}
//				return (void)var;
//				break;
//			}
//		}
//		if(border==1)								// var can take values form LowLim to +INF 
//		{
//			int LowLim=va_arg(p,int);
//			while (!scanf_s("%d",&var) || var<LowLim)
//			{
//				printf("Неверный ввод. Побробуйте еще раз\n");
//				fflush(stdin);
//			}
//			return (void)var;
//			break;
//		}
//		if(border==2)								// var can take ANY integer value
//		{
//			while (!scanf_s("%d",&var))
//			{
//				printf("Неверный ввод. Побробуйте еще раз\n");
//				fflush(stdin);
//			}
//			return (void)var;
//			break;
//		}	break;
//
//
//
//	// F L O A T
//	case Float:
//		float var;
//		if(border==-1)								// var can take values form -INF to HighLim 
//		{
//			float HighLim=va_arg(p,float);
//			while (!scanf_s("%f",&var) || var>HighLim)
//			{
//				printf("Неверный ввод. Побробуйте еще раз\n");
//				fflush(stdin);
//			}
//			return (void)var;
//			break;
//		}
//		if(border==0)
//		{
//			float LowLim=va_arg(p,float);
//			float HighLim=va_arg(p,float);
//			if(LowLim<=HighLim)					//var can take values form LowLim to HighLim 
//			{
//				while (!scanf_s("%f",&var) ||var<LowLim || var>HighLim)
//				{
//					printf("Неверный ввод. Побробуйте еще раз\n");
//					fflush(stdin);
//				}
//				return (void)var;
//				break;
//			}
//			if(LowLim>HighLim)					//var can take ANY value excluding values from LowLim to HighLim
//			{
//				while (!scanf_s("%f",&var)||(var>=LowLim && var<=HighLim))
//				{
//					printf("Неверный ввод. Побробуйте еще раз\n");
//					fflush(stdin);
//				}
//				return (void)var;
//				break;
//			}
//		}
//		if(border==1)								// var can take values form LowLim to +inf 
//		{
//			float LowLim=va_arg(p,float);
//			while (!scanf_s("%f",&var) || var<LowLim)
//			{
//				printf("Неверный ввод. Побробуйте еще раз\n");
//				fflush(stdin);
//			}
//			return (void)var;
//			break;
//		}
//		if(border==2)								// var can take ANY float value
//		{
//			while (!scanf_s("%f",&var))
//			{
//				printf("Неверный ввод. Побробуйте еще раз\n");
//				fflush(stdin);
//			}
//			return (void)var;
//			break;
//		}	break;
//
//
//
//		// D O U B L E
//	case Double:
//		double var;
//		if(border==-1)								// var can take values form -INF to HighLim 
//		{
//			double HighLim=va_arg(p,double);
//			while (!scanf_s("%lf",&var) || var>HighLim)
//			{
//				printf("Неверный ввод. Побробуйте еще раз\n");
//				fflush(stdin);
//			}
//			return (void)var;
//			break;
//		}
//		if(border==0)
//		{
//			double LowLim=va_arg(p,double);
//			double HighLim=va_arg(p,double);
//			if(LowLim<=HighLim)					//var can take values form LowLim to HighLim 
//			{
//				while (!scanf_s("%lf",&var) ||var<LowLim || var>HighLim)
//				{
//					printf("Неверный ввод. Побробуйте еще раз\n");
//					fflush(stdin);
//				}
//				return (void)var;
//				break;
//			}
//			if(LowLim>HighLim)					//var can take ANY value excluding values from LowLim to HighLim
//			{
//				while (!scanf_s("%lf",&var)||(var>=LowLim && var<=HighLim))
//				{
//					printf("Неверный ввод. Побробуйте еще раз\n");
//					fflush(stdin);
//				}
//				return (void)var;
//				break;
//			}
//		}
//		if(border==1)								// var can take values form LowLim to +inf 
//		{
//			double LowLim=va_arg(p,double);
//			while (!scanf_s("%lf",&var) || var<LowLim)
//			{
//				printf("Неверный ввод. Побробуйте еще раз\n");
//				fflush(stdin);
//			}
//			return (void)var;
//			break;
//		}
//		if(border==2)								// var can take ANY double value
//		{
//			while (!scanf_s("%lf",&var))
//			{
//				printf("Неверный ввод. Побробуйте еще раз\n");
//				fflush(stdin);
//			}
//			return (void)var;
//			break;
//		}	break;
//
//	default:
//	}
//	
//}
