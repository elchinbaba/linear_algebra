#include<iostream>
using namespace std;
#include<cmath>
#define deltaX 0.05
double f(float x)
{
    double y=pow(x,3)-pow(x,2)-9*x+9;
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
double newton_raphson_method(float a,float b,double eps)
{
    float x=(a+b)/2;
    if(derivative(x,1)*derivative(x,2)==0 && b>a) return 0;
    else
    {
        float x_n,x_0,delta;
        if(derivative(x,1)*derivative(x,2)>0) x_0=b;
        if(derivative(x,1)*derivative(x,2)<0) x_0=a;
        do{
            if(derivative(x_0,1))
            {
                x_n=x_0-f(x_0)/derivative(x_0,1);
                delta=x_n-x_0;
                x_0=x_n;
            }
            else return 0;
        }while(delta>eps);
        return x_n;
    }
}
int main()
{
    cout<<newton_raphson_method(2.5,4,0.001);
    return 0;
}