float *arr(int N) {return new float[N];}
#include<iostream>
using namespace std;
float *delete_fromstart(float *P,int N,int n)
{
    int m=N-n; float *G=arr(m);
    for(int i=0;i<m;i++) G[i]=P[i+n];
    return G;
}
#include<cmath>
float grouping_by_coefficients(float *P,int N,float a)
{
    if(P[0]<0)
    {
        for(int i=0;i<N+1;i++) P[i]=-P[i];
        return grouping_by_coefficients(P,N,a);
    }
    else
    {
        float *massiv=arr(N+1); int i;
        for(i=0;i<N+1;i++) massiv[i]=P[i];
        int k=0;
        for(i=0;i<N;i++)
        {
            if(massiv[i]<0 && massiv[i+1]>0) k++;
            if(massiv[i+1]==0) massiv[i+1]=massiv[i];
        }
        int m=k+1; float *A=arr(m);
        for(i=0;i<N+1;i++) massiv[i]=P[i];
        int t=0,sum=0; k=0;
        for(i=0;i<N;i++)
        {
            t++;
            if(massiv[i]*massiv[i+1]<0 && massiv[i+1]>0) {A[k]=t; sum+=A[k]; t=0; k++;}
            if(massiv[i+1]==0) massiv[i+1]=massiv[i];
        }
        A[m-1]=N+1-sum;
        float *G=arr(N+1),*H,P_j_x,ksi=a;
        int n=N;
        while(1)
        {
            N=n; for(i=0;i<N+1;i++) G[i]=P[i];
            for(i=0;i<m;i++)
            {
                P_j_x=0;
                for(int j=0;j<A[i];j++) P_j_x+=G[j]*pow(ksi,N-j);
                if(!(P_j_x>0)) break;
                if(N+1>A[i])
                {
                    H=arr(N+1-A[i]);
                    H=delete_fromstart(G,N+1,A[i]);
                    N=N-A[i];
                    for(k=0;k<N;k++) G[k]=H[k];
                }
            }
            if(i==m && P_j_x>0) break;
            ksi+=0.01;
        }
        return ksi;
    }
}
#include<iostream>
using namespace std;
int main()
{
    int n=5;
    float A[n+1]={2,0,0,100,-5,-40};
    cout<<grouping_by_coefficients(A,n,0.1);
}