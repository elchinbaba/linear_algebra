float *arr(int N) {return new float[N];}
#include<cmath>
float sum(float x,float *P,int N)
{
    float C=0;
    for(int i=0;i<N+1;i++) C+=P[i]*pow(x,N-i);
    return C;
}
float Newton_method(float *P,int N)
{
    if(P[0]<0)
    {
        for(int i=0;i<N+1;i++) P[i]=-P[i];
        return Newton_method(P,N);
    }
    else
    if(N*P[0]!=0)
    {
        int n=N,i; float *G,*H,ksi=-P[1]/(N*P[0])-0.01,P_x,P_N_x;
        while(1)
        {
            ksi+=0.01;
            P_x=sum(ksi,P,N);
            if(!(P_x>0)) continue;
            N=n; G=arr(N+1); for(i=0;i<N+1;i++) G[i]=P[i];
            for(i=0;i<n;i++)
            {
                N=N-1;
                H=arr(N+1);
                for(int j=0;j<N+1;j++) H[j]=G[j]*(N+1-j);
                P_N_x=sum(ksi,H,N);
                if(!(P_N_x>0)) break;
                for(int j=0;j<N+1;j++) G[j]=H[j];
            }
            if(i==n && P_N_x>0) break;
        }
        return ksi;
    }
    else return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int n=5;
    float A[n+1]={2,0,0,100,-5,-40};
    cout<<Newton_method(A,n);;
    return 0;
}