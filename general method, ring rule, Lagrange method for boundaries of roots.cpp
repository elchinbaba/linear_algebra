float *arr(int N) {return new float[N];}
#include<iostream>
using namespace std;
#include<cmath>
float maximum(float *a,int N)
{
    float max=fabs(a[0]);
    for(int i=1;i<N;i++) if(fabs(a[i])>max) max=fabs(a[i]);
    return max;
}
float general_method(float *a,int N)
{
    float *p=&a[1];
    float A=maximum(p,(N+1)-1);
    float R=1+A/fabs(a[0]);
    return R;
}
float ring_rule(float *a,int N)
{
    float B=maximum(a,N);
    float r=1/(1+B/fabs(a[N]));
    return r;
}
float Lagrange(float *a,int N)
{
    if(a[0]>0)
    {
        int k=0;
        for(int i=1;i<N+1;i++) if(a[i]<0) {k=i; break;}
        if(k!=0)
        {
            float B=a[k];
            for(int i=k+1;i<N+1;i++) if(a[i]<B) B=a[i];
            B=fabs(B);
            float R=1+pow(B/a[0],1/float(k));
            return R;
        }
        else return 0;
    }
    else
    {
        for(int i=0;i<N+1;i++) a[i]=-a[i];
        return Lagrange(a,N);
    }
}
int main()
{
    float a[]={2,0,0,100,-5,-40};
    float R=general_method(a,5);
    float r=ring_rule(a,5);
    cout<<R<<" "<<r<<endl;
    R=Lagrange(a,5);
    cout<<R;
    return 0;
}