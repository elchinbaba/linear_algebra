float *arr(int N) return new float[N];
float **horner(float *A,int N,float c)
{
    float *B=arr(N);
    B[0]=A[0];
    for(int i=1;i<N;i++) B[i]=c*B[i-1]+A[i];
    static float r=c*B[N-1]+A[N];
    float *r_pointer=&r;
    static float *pointer[2];
    pointer[0]=B;
    pointer[1]=r_pointer;
    return pointer;
}
float **horner(float *A,int N,float p,float q)
{
    float *B=arr(N-1);
    B[0]=A[0];
    B[1]=A[1]-q*B[0];
    for(int i=2;i<N-1;i++) B[i]=A[i]-p*B[i-1]-q*B[i-2];
    float *R=arr(2);
    R[0]=A[N-1]-p*B[N-2]-q*B[N-3];
    R[1]=A[N]-q*B[N-2];;
    static float *pointer[2];
    pointer[0]=B;
    pointer[1]=R;
    return pointer;
}
#include<iostream>
using namespace std;
int main()
{
    int n=4;
    float A[n+1]={1,5,-4,-2,1};
    float c=2,p=1,q=1;
    float **point1=horner(A,n,c);
    float **point2=horner(A,n,p,q);
    float *B1=point1[0],*B2=point2[0],r=*point1[1],*R=point2[1];
    for(int i=0;i<n;i++) cout<<B1[i]<<" ";
    cout<<endl<<r<<endl<<endl;
    for(int i=0;i<n-1;i++) cout<<B2[i]<<" ";
    cout<<endl;
    for(int i=0;i<2;i++) cout<<R[i]<<" ";
    return 0;
}