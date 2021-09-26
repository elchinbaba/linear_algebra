#include<iostream>
using namespace std;
#include<cmath>
#define deltaX 0.05
double f(float x)
{
    double y=pow(x,3)+3*pow(x,2)-3;
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
double modified_method(float a,float b,double eps,int N)
{
    float x_0=(a+b)/2;
    if(derivative(x_0,1)*derivative(x_0,2)==0 || b<a) return 0;
    else
    {
        int t=0;
        if(derivative(x_0,1)*derivative(x_0,2)>0)
        {
            do{
                t++;
                a=a-f(a)*(b-a)/(f(b)-f(a));
                if(derivative(b,1))
                b=b-f(b)/derivative(b,1);
                else return 0;
            }while(fabs(b-a)>eps && t!=N);
        }
        if(derivative(x_0,1)*derivative(x_0,2)<0)
        {
            do{
                t++;
                if(derivative(a,1))
                a=a-f(a)/derivative(a,1);
                else return 0;
                b=b-f(b)*(b-a)/(f(b)-f(a));
            }while(fabs(b-a)>eps && t!=N);
        }
        return (a+b)/2;
    }
}
int main()
{
    cout<<modified_method(-2,-1,0.01,100);
    return 0;
}