float *arr(int N) {return new float[N];}
float *reverse(float *P,int N)
{
    float temp;
    for(int i=0;i<N/2;i++)
    {
        temp=P[i];
        P[i]=P[N-1-i];
        P[N-1-i]=temp;
    }
    return P;
}
float *minus(float *P,int N)
{
    for(int i=0;i<N+1;i++) if((N+1-i)%2==1) P[i]=-P[i];
    return P;
}
float *P1(float *P,int N)
{
    reverse(P,N+1);
    return P;
}
float *P2(float *P,int N)
{
    reverse(P,N+1);
    minus(P,N);
    return P;
}
float *P3(float *P,int N)
{
    minus(P,N+1);
    return P;
}
#include<iostream>
using namespace std;
int main()
{
    int n=3;
    float A[n+1]={1,-1,-1,-1};
    float *P=P3(A,n);
    for(int i=0;i<n+1;i++) cout<<P[i]<<endl;
    return 0;
}