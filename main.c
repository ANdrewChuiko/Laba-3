#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

double f(double x);
double Fu(double x);
MethodChord(double x);
int main()
{

    double  x1,x2,x,xi,E,start,finish,sum;
    int Method,V,N,d=0,i=0,T=0;

    setlocale(LC_ALL, "Rus");


    printf("������ ���� �����ii:");
    scanf("%lf",&x1);
    printf("����� ���� �����i�:");
    scanf("%lf",&x2);
    printf("�������: ");
    scanf("%lf",&E);
    printf("��������� �i������i i�����i�:");
    scanf("%d",&N);
    if (f(x1)<0 && f(x2)>0)
    {
    printf("����� ���������� ���������\n\t1|����� ����\n\t2| ����� ����������� �i�����\n\t3|����� ������� ");
    scanf("%d",&Method);

    switch(Method){
        case 1:
        {
                do{
                    start=clock();
                    T+=1;
                    x=(f(x2)*x1-f(x1)*x2)/(f(x2)-f(x1));
                    if(f(x)>0)
                        x1=x;
                    else
                        x2=x;

                    printf("T = %d\n",T);
                    printf("x = %lf\n",x);
                    printf("F(x) = %.2lf\n",f(x));
                     printf("\n            \n",f(x));
                    if(i==N){
                    finish=clock();
                    sum+=(finish-start)/CLK_TCK;
                    getch();
                    }
                }while(fabs(f(x))>E);

            }
        case 2:
            {


                do{
                    start=clock();
                    T+=1;
                    x=(x1+x2)/2;
                    if((f(x)*f(x2))<0)
                        x1=x;
                    else
                        x2=x;

                    printf("T = %d\n",T);
                    printf("x = %2.lf\n",x);
                    printf("F(x) = %.2lf\n",f(x));
                    printf("\n            \n",f(x));
                    if(i==N){
                    finish=clock();
                    sum+=(finish-start)/CLK_TCK;
                    getch();
                    }
                }while((fabs(f(x1)-f(x2)))>E);
            }
        case 3:
            {
               printf("X: ");
      scanf("%lf",&x1);
      printf("�������: ");
      scanf("%lf",&E);
      printf("����i�� �i���i��� i�����i�: ");
      scanf("%d",&N);

      do
      {
       xi = x1 - (Fu(x1)/f(x1));
        if( fabs(Fu(xi))< fabs(Fu(x1)) )
        {
            x1 = xi;
        }
        if(i==N)
        {
            printf("�������� i�����i� ���������\n");
            printf("Press ESC to finish the calculation or any key to continue calculations\n");
            i = getch();
            if((int)i==27)
            {
                system("cls");
                break;
            }
            else
            {
             system("cls");
            }
        }
        i++;
      }
      while ( fabs (Fu(xi)) > E );


            }
            break;
        }

    stop:printf("x = %2.lf",x);
    printf("\n\n ��� ���� ��� ������� ���i��  %.2Lf sec.\n",sum);
    printf("T = %d",T);
    return 0;
    }
 else {
 printf("\n\n ��������� ������ ���i��\n");
}
}
double f(double x)
{
    return(((x+2)*(x+2)*(x+2))-7*x);
}

double Fu(double x)
{
    return(pow(3*x,2)+12*x+5);
}

