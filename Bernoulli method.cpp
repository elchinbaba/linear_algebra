float *arr(int N) {return new float[N];}
#include<iostream>
using namespace std;
float Bernoulli(float *P,int N,int n)
{
    if(n>=N)
    {
        float *G=arr(N);
        for(int i=0;i<N;i++)
        {
            if(i==N-1) G[i]=1;
            else G[i]=0;
        }
        float y_N_i;
        for(int i=N;i<=n;i++)
        {
            y_N_i=0;
            for(int j=0;j<N;j++) y_N_i+=-P[N-j]*G[j]; y_N_i/=P[0];
            for(int j=0;j<N-1;j++) G[j]=G[j+1]; G[N-1]=y_N_i;
        }
        return G[N-1]/G[N-2];
    }
    else return 0;
}
int main()
{
    int n=5;
    float A[n+1]={1,2,0,0,0,-2};
    cout<<Bernoulli(A,n,26);
    return 0;
}