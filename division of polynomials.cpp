float *arr(int N) {return new float[N];}
#include<iostream>
using namespace std;
float **division(float A[],float B[],int N,int M)
{
    if(N>=M)
    {
        if(B[0]!=0)
        {
            float *Q=arr(N-M+1),*R=arr(M);
            for(int i=0;i<=N-M;i++)
            {
                Q[i]=A[i]/B[0];
                for(int j=i;j<=M+i;j++)
                A[j]=A[j]-B[j-i]*Q[i];
            }
            for(int i=0;i<M;i++) R[i]=A[i+N-M+1];
            static float *pointer[2];
            pointer[0]=Q;
            pointer[1]=R;
            return pointer;
        }
        else if(M!=1)
                {
                    float B_massiv[M-1];
                    for(int i=0;i<M-1;i++) B_massiv[i]=B[i+1];
                    return division(A,B_massiv,N,M-1);
                }
    }
}
int main()
{
    int n=3,m=2;
    float A[n+1]={1,0,0,0};
    float B[m+1]={1,1,1};
    float **point=division(A,B,n,m);
    for(int i=0;i<n-m+1;i++) cout<<point[0][i]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++) cout<<point[1][i]<<" ";
    return 0;
}