#include<stdio.h>
#include<math.h>
int main()
{
    int N,i,j,q=0;
    printf("input number of variables:"); scanf("%d", &N);
    double eps,k,alfa,betta,maxdx,A[N*N],B[N],C[N],D[N],X[N],Y[N],Z[N],T[N];
    printf("input accuracy of eps:"); scanf("%lf", &eps);
    for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
                {
                    printf("alfa%d%d=", i+1,j+1); scanf("%lf", &A[i*N+j]);
                }
            printf("b%d=", i+1); scanf("%lf", &B[i]);
        }
    for(i=0;i<N;i++)
        {
            C[i]=0;
            for(j=0;j<N;j++)
                {
                    C[i]+=fabs(A[N*(i%N)+j]);
                }
        }
    alfa=C[0]; betta=B[0];
    for(i=1;i<N;i++)
        {
            if(alfa<C[i]) alfa=C[i];
            if(betta<B[i]) betta=B[i];
        }
    if(alfa<1)
        {
            k=(double)(log((double)((1-alfa)*eps)/(betta)))/(log(alfa))-1;
            printf("minimum number of iterations:%lf\n", ceil(k));
            printf("write the initial approximation:\n");
            for(i=0;i<N;i++)
                {
                    printf("for x%d:", i+1); scanf("%lf", &T[i]);
                }
            for(i=0;i<N;i++)
                {
                    X[i]=B[i];
                    for(j=0;j<N;j++)
                        {
                            X[i]+=A[i*N+j]*T[j];
                        }
                    Y[i]=X[i];
                }
            do
                {
                    for(i=0;i<N;i++)
                        {
                            Z[i]=X[i]; X[i]=B[i];
                        }
                    for(i=0;i<=N;i++)
                        {
                            if(i<N)
                                {
                                    for(j=0;j<N;j++)
                                        {
                                            X[i]+=A[i*N+j]*Z[j];
                                        }
                                    D[i]=X[i]-Y[i]; Y[i]=X[i];
                                }
                            else
                                {
                                    maxdx=D[0];
                                    for(j=1;j<N;j++)
                                        {
                                            if(maxdx<D[j]) maxdx=D[j];
                                        }
                                }
                        }
                    ++q;
                }while(maxdx>eps);
            for(i=0;i<N;i++)
                {
                    printf("x%d=%lf\n", i+1,X[i]);
                }
            printf("exact number of iterations:%d", q);
        }
    else return 0;;
}