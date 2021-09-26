float *arr(int N) {return new float[N];}
float *answer(int N,float *massiv[])
{
    int i,j,k,t=0;
    float a_ii,a_ki;
    for(i=0;i<N;i++)
    {
        if(massiv[i][i]!=0)
        {
            a_ii=massiv[i][i];
            for(j=0;j<N+1;j++)
            massiv[i][j]/=a_ii;
            for(k=0;k<N;k++)
            if(k!=i)
            {
                a_ki=-massiv[k][i];
                for(j=0;j<N+1;j++)
                massiv[k][j]+=massiv[i][j]*a_ki;
            }
        }
        else {t=1; break;}
    }
    float *solutions=arr(N);
    for(i=0;i<N;i++) heller[i]=massiv[i][N];
    return solutions;
}
#include<iostream>
int main()
{
    int n; scanf("%d",&n);
    float *massiv[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        massiv[i]=arr(n+1);
        for(j=0;j<n+1;j++)
        {
            printf("a_%d%d=",i+1,j+1); scanf("%f",&massiv[i][j]);
        }
    }
    float *answers=answer(n,massiv);
    for(i=0;i<n;i++)
    printf("x_%d=%f\n",i,answers[i]);
    return 0;
}