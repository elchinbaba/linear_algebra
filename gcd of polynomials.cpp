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
    for(int i=0;i<=N;i++) P[i]=P_massiv[i+1];
    float *G_massiv=massiv(G,M+1);
    M=G_massiv[0]-1;
    for(int i=0;i<=M;i++) G[i]=G_massiv[i+1];
    if(N>=M)
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
int main()
{
    int n=3,m=3;
    float A[n+1]={3,4,0,3};
    float B[m+1]={3,4,3,4};
    float *point=gcd(A,B,n,m);
    for(int i=1;i<point[0]+1;i++)
    cout<<point[i]<<endl;
    return 0;
}