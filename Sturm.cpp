float *arr(int N) {return new float[N];}
#include<iostream>
using namespace std;
/*float *massiv(float *A,int N)
{
    float *A_massiv=arr(N);
    for(int i=0;i<N;i++) A_massiv[i]=A[i];
    while(A[0]==0)
    {
        N=N-1;
        A_massiv=arr(N+1);
        for(int i=1;i<=N;i++) A_massiv[i]=A[i];
        for(int i=0;i<N;i++) A[i]=A_massiv[i+1];
    }
    A_massiv[0]=N;
    return A_massiv;
}*/
float *massiv(float *A,int N)
{
    float *A_massiv=arr(N);
    for(int i=0;i<N;i++) A_massiv[i]=A[i];
    while(A_massiv[0]==0 && N!=1)
    {
        N=N-1;
        for(int i=0;i<N;i++) A_massiv[i]=A_massiv[i+1];
    }
    for(int i=N;i>0;i--) A_massiv[i]=A_massiv[i-1];
    A_massiv[0]=N;
    return A_massiv;
}
float **division(float *P,float *G,int N,int M)
{
    float *P_massiv=massiv(P,N+1);
    N=P_massiv[0]-1;
    for(int i=0;i<N+1;i++) P[i]=P_massiv[i+1];
    float *G_massiv=massiv(G,M+1);
    M=G_massiv[0]-1;
    for(int i=0;i<M+1;i++) G[i]=G_massiv[i+1];
    if(N>=M && G[0]!=0)
    {
        float *Q=arr(N-M+1),*R=arr(M+1);
        for(int i=0;i<=N-M;i++)
        {
            Q[i]=P[i]/G[0];
            for(int j=i;j<=M+i;j++)
            P[j]=P[j]-G[j-i]*Q[i];
        }
        Q=massiv(Q,N-M+1);
        for(int i=0;i<M;i++)
        R[i]=P[i+N-M+1];
        R=massiv(R,M);
        static float *pointer[4];
        pointer[0]=Q;
        pointer[1]=R;
        pointer[2]=P_massiv;
        pointer[3]=G_massiv;
        return pointer;
    }
}
#include<cmath>
float P(float x,float *massiv,int N)
{
    float C=0;
    for(int i=0;i<=N;i++) C+=massiv[i]*pow(x,N-i);
    return C;
}
float *gcd(float *P,float *G,int N,int M)
{
    float **pointer,*R;
    int t;
    do{
        t=0;
        pointer=division(P,G,N,M);
        P=pointer[2];
        G=pointer[3];
        R=pointer[1];
        N=pointer[3][0]-1;
        M=pointer[1][0]-1;
        for(int i=0;i<N+1;i++) P[i]=G[i+1];
        for(int i=0;i<M+1;i++) G[i]=R[i+1];
        for(int i=1;i<=M+1;i++) if(R[i]==0) t++;
    }while(M!=0 && t!=M);
    float *D;
    if(M==0) D=massiv(P,N+1);
    else if(t==M) D=massiv(R,M+1);
    return D;
}
float *sturm(int a,int b,float *A,int N)
{
    int n=b-a+1;
    float *massiv=arr(n);
    for(int i=0;i<n;i++) massiv[i]=0;
    float *memory1=arr(n),*memory2=arr(n);
    float **pointer,*B,*R;
    int M;
    M=N-1; B=arr(M+1);
    for(int i=0;i<N;i++) B[i]=A[i]*(N-i);
    float *GCD=gcd(A,B,N,N-1);
    if(*GCD!=1)
    {
        for(int i=a;i<=b;i++)
        {
            memory1[i-a]=P(i,A,N);
            memory2[i-a]=P(i,B,M);
            if(memory1[i-a]*memory2[i-a]<0) massiv[i-a]++;
            if(memory2[i-a]==0) memory2[i-a]=memory1[i-a];
        }
        for(int i=0;i<n;i++) memory1[i]=memory2[i];
        while(M!=0)
        {
            pointer=division(A,B,N,M);
            A=pointer[2];
            B=pointer[3];
            R=pointer[1];
            N=pointer[3][0]-1;
            M=pointer[1][0]-1;
            for(int i=0;i<N+1;i++) A[i]=B[i+1];
            for(int i=0;i<M+1;i++) B[i]=-R[i+1];
            for(int i=a;i<=b;i++)
            {
                memory2[i-a]=P(i,B,M);
                if(memory1[i-a]*memory2[i-a]<0) massiv[i-a]++;
                if(memory2[i-a]==0) memory2[i-a]=memory1[i-a];
            }
            for(int i=0;i<n;i++) memory1[i]=memory2[i];
        }
        return massiv;
    }
    else return 0;
}
int main()
{
    float A[]={1,1,-2,-1};
    int a=-3,b=3;
    float *c=sturm(a,b,A,3);
    int n=b-a+1;
    for(int i=0;i<n;i++) cout<<c[i]<<endl;
    return 0;
}