float *arr(int N) {return new float[N];}
#include<iostream>
using namespace std;
#include<cmath>
#define deltaX 0.05
double f(float x)
{
    double y=pow(x,3)-x+1;
    return y;
}
double differential(float a,int n)
{
    if(n==0) return f(a);
    else return differential(a+deltaX,n-1)-differential(a-deltaX,n-1);
}
double derivative(float a,int n)
{
    double dy_n=differential(a,n);
    double dx_n=pow(2*deltaX,n);
    return dy_n/dx_n;
}
double chords_method(float a,float b,double eps)
{
    float x=(a+b)/2;
    if(derivative(x,1)*derivative(x,2)==0 && b>a) return 0;
    else
    {
        float x_n,x_0,delta;
        if(derivative(x,1)*derivative(x,2)>0)
        {
            x_0=a;
            do{
                x_n=x_0-f(x_0)*(b-x_0)/(f(b)-f(x_0));
                delta=fabs(x_n-x_0);
                x_0=x_n;
            }while(delta>eps);
        }
        if(derivative(x,1)*derivative(x,2)<0)
        {
            x_0=b;
            do{
                x_n=x_0-f(x_0)*(x_0-a)/(f(x_0)-f(a));
                delta=fabs(x_n-x_0);
                x_0=x_n;
            }while(delta>eps);
        }
        return x_n;
    }
}
int main()
{
    cout<<chords_method(-2,-1,0.001);
    return 0;
}