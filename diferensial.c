#include<stdio.h>
#include<math.h>
double f(float x)
{
    double y=;
    return y;
}
double differential(float a,int n)
{
    if(n==0) return f(a);
    else return differential(a+0.05,n-1)-differential(a-0.05,n-1);
}
void main()
{
    float a; printf("a="); scanf("%f",&a);
    int n; printf("n="); scanf("%d",&n);
    double dy_n=differential(a,n);
    double dx_n=pow(0.1,n);
    printf("f^(%d)(%f)=%lf",n,a,dy_n/dx_n);
}