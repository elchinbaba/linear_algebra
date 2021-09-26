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
    scanf("%d",&N);
    float massiv[N][2*N];
    int i,j;
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    {
        printf("a_%d%d=",i+1,j+1); scanf("%f",&massiv[i][j]);
    }
    float D=determinant(N,massiv);
    if(D!=0)
    {
        for(i=0;i<N;i++)
        for(j=N;j<2*N;j++)
        {
            if(j-N==i) massiv[i][j]=1;
            else massiv[i][j]=0;
        }
        int k,t;
        float a_ii,a_ki;
        for(i=0;i<N;i++)
        {
            if(massiv[i][i]!=0)
            {
                a_ii=massiv[i][i];
                for(j=0;j<2*N;j++)
                massiv[i][j]/=a_ii;
                for(k=0;k<N;k++)
                if(k!=i)
                {
                    a_ki=-massiv[k][i];
                    for(j=0;j<2*N;j++)
                    massiv[k][j]+=massiv[i][j]*a_ki;
                }
            }
            else 
            {
                for(t=i+1;t<N;t++)
                if(massiv[i][t]!=0) break;
                int c[2*N];
                for(j=0;j<2*N;j++)
                {
                    c[j]=massiv[j][i];
                    massiv[j][i]=massiv[j][t];
                    massiv[j][t]=c[j];
                }
                i=i-1;
            }
        }
        float ters_matris[N][N];
        for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            ters_matris[i][j]=massiv[i][j+N];
            printf("%f ",ters_matris[i][j]);
            if(j==N-1) printf("\n");
        }
    }
    else printf("Inverse matrix does not exist.");
}