float *arr(int N) {return new float[N];}
float **horner(float *A,int N,float c)
{
    float *B=arr(N);
    B[0]=A[0];
    for(int i=1;i<N;i++) B[i]=c*B[i-1]+A[i];
    float r=c*B[N-1]+A[N];
    static float *r_pointer=&r;
    static float *pointer[2];
    pointer[0]=B;
    pointer[1]=r_pointer;
    return pointer;
}
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
#include<cmath>
/*int factorial(int n)
{
	if(n==0 || n==1) return 1;
	else return n*factorial(n-1);
}
float sum(float x,float *P,int N)
{
    float C=0;
    for(int i=0;i<N+1;i++) C+=P[i]*pow(x,N-i);
    return C;
}
float *Horner_Ruffini(float *P,int N,int a)
{
    float *H=arr(N+1),*G=arr(N+1); for(int i=0;i<N+1;i++) G[i]=P[i];
    int i,n=N;
    for(i=0;i<N+1;i++)
    {
        H[i]=sum(a,G,n)/factorial(i);
        G=arr(n);
        for(int j=0;j<n;j++) G[j]=P[j]*(n-j);
        for(int j=0;j<n;j++) P[j]=G[j];
        n=n-1;
    }
    reverse(H,N+1);
    for(i=0;i<N+1;i++) H[i]*=pow(0.1,N-i);
    return H;
}*/
float *Horner_Ruffini(float *P,int N,int a)
{
    float **pointer,*H=arr(N+1),*G=arr(N+1),*r;
    int n=N;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<N+1;j++) G[j]=P[j];
        pointer=horner(G,N,a);
        N=N-1; G=arr(N+1);
        for(int j=0;j<N+1;j++) P[j]=pointer[0][j];
        r=pointer[1]; H[i]=*r;
    }
    reverse(H,n+1);
    for(int i=0;i<n+1;i++) H[i]*=pow(10,i);
    return H;
}
#include<iostream>
using namespace std;
int main()
{
    int n=3;
    float A[n+1]={1,0,-8,1};
    float *P=Horner_Ruffini(A,n,2);
    for(int i=0;i<n+1;i++) cout<<P[i]<<endl;
    return 0;
}