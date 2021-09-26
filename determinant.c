#include<stdio.h>
#include<math.h>
float determinant(int N, float massiv[][N])
{
    int i,j;
    int r=0,n=0;
    int k;
    float a_ii,a_ki;
    for(i=0;i<N-1;i++)
    {
        if(massiv[i][i]!=0)
        {
            a_ii=massiv[i][i];
            for(k=i+1;k<N;k++)
            {
                a_ki=-massiv[k][i];
                for(j=0;j<N;j++)
                massiv[k][j]+=massiv[i][j]*(a_ki/a_ii);
            }
        }
        else
        {
            int t;
            for(t=i+1;t<N;t++)
            if(massiv[i][t]!=0) break;
            if(t!=N)
            {
                n++;
                int c[N];
                for(j=0;j<N;j++)
                {
                    c[j]=massiv[j][i];
                    massiv[j][i]=massiv[j][t];
                    massiv[j][t]=c[j];
                }
                i=i-1;
                continue;
            }
            else
            {
                r=1; break;
            }
        }
    }
    float D;
    switch(r)
    {
        case 0:
        D=pow(-1,n);
        for(i=0;i<N;i++)
        D*=massiv[i][i];
        break;
        case 1:
        D=0; break;
    }
    return D;
}
void main()
{
    int N;
    printf("N="); scanf("%d",&N);
    float massiv[N][N];
    int i,j;
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    {
        printf("a_%d%d=",i+1,j+1); scanf("%f",&massiv[i][j]);
    }
    float D=determinant(N,massiv);
    printf("D=%f",D);
}