int *massiv_f(int N) {return new int[N];}
int yaddash_N(int c,int B)
{
    int N=0;
    do{
        c/=B;
        N++;
    }while(c!=0);
    return N;
}
int *reverse(int massiv[],int N)
{
    int temp;
    for(int i=0;i<N/2;i++)
    {
        temp=massiv[i];
        massiv[i]=massiv[N-1-i];
        massiv[N-1-i]=temp;
    }
    int *reverse_massiv=massiv;
    return reverse_massiv;
}
#include<cmath>
int *toplayici(int massiv[],int N,int h,int A)
{
    if(N%h==0)
    {
        int i,j;
        int t=N/h,*C=massiv_f(t);
        for(i=0;i<t;i++) {C[i]=0;}
        reverse(massiv,N);
        for(i=0;i<t;i++) for(j=h*i;j<h*(i+1);j++) {C[i]+=massiv[j]*pow(A,h-(j%h+1));}
        return C;
    }
    else
    {
        int error=1; 
        int *error_p=&error; 
        return error_p;
    }
}
int *yaddash_f(int c,int B)
{
    int N=yaddash_N(c,B);
    int *massiv=massiv_f(N);
    for(int i=0;i<N;i++)
    {
        massiv[i]=c%B;
        c/=B;
    }
    return massiv;
}
int *log_2(int yaddash[],int N,int h)
{
    int *massiv=yaddash;
    if(N%h!=0)
    {
        int k=h-N%h; N=N+k;
        for(int i=N-1;i>=k;i--) {massiv[i]=massiv[i-k];}
        for(int i=0;i<k;i++) {massiv[i]=0;}
    }
    return massiv;
}
int log_2_cemleyici(int yaddash[],int N,int h)
{
    int C=0;
    for(int i=0;i<N;i++) {C+=yaddash[i]*pow(10,h*(N-(i+1)));}
    return C;
}
int kechirt_2_10(int c)
{
    int N=yaddash_N(c,10),*yaddash=yaddash_f(c,10);
    reverse(yaddash,N);
    int C=0;
    for(int i=0;i<N;i++) {C=C*2+yaddash[i];}
    return C;
}
int kechirt_10_2(int c)
{
    int N=yaddash_N(c,2),*yaddash=yaddash_f(c,2);
    reverse(yaddash,N);
    int C=0;
    for(int i=0;i<N;i++) {C=C*10+yaddash[i];}
    return C;
}
#include<iostream>
using namespace std;
int kechirt(int A,int B,int c,string s)
{
    int C,*yaddash;
    int i,N,*p;
    if(A!=16)
    {
        yaddash=yaddash_f(c,B); 
        N=yaddash_N(c,B);
        if(A==10 || B==10) {C=*toplayici(yaddash,N,N,A);}
            else if(A==2 && B==8)
                    {
                        N=yaddash_N(c,10),yaddash=yaddash_f(c,10);
                        reverse(yaddash,N);
                        yaddash=log_2(yaddash,N,3);
                        if(N%3!=0) N=N+(3-N%3);
                        reverse(yaddash,N);
                        yaddash=toplayici(yaddash,N,3,10);
                        N=N/3;
                        for(i=0;i<N;i++) {yaddash[i]=kechirt_2_10(yaddash[i]);}
                        reverse(yaddash,N);
                        for(i=0;i<N;i++) cout<<yaddash[i]<<endl;
                        C=*toplayici(yaddash,N,N,10);
                    }
                    else if(A==8 && B==2)
                            {
                                N=yaddash_N(c,10),yaddash=yaddash_f(c,10);
                                reverse(yaddash,N);
                                for(i=0;i<N;i++) {yaddash[i]=kechirt_10_2(yaddash[i]);}
                                /*for(i=0;i<N;i++) {int j; for(j=3*i;j<3*(i+1);j++) p[j]=*yaddash_f(yaddash[i],10);} 
                                C=*toplayici(p,3*N,3*N,10);*/
                                C=log_2_cemleyici(yaddash,N,3);
                            }
    }
    else
    {
        N=s.length();
        int temp_int,yaddash_m[N];
        char temp_char,herf[]={'A','B','C','D','E','F'};
        for(i=0;i<N;i++)
        {
            temp_char=s.at(i);
            int t=0;
            for(int j=0;j<6;j++)
            {
                if(temp_char==herf[j]) 
                {
                    t=1;
                    break;
                }
            }
            if(t!=1) temp_int=int(temp_char)-48;
            else switch(temp_char)
                        {
                            case 'A':
                            temp_int=10; break;
                            case 'B':
                            temp_int=11; break;
                            case 'C':
                            temp_int=12; break;
                            case 'D':
                            temp_int=13; break;
                            case 'E':
                            temp_int=14; break;
                            case 'F':
                            temp_int=15; break;
                        }
            yaddash_m[i]=temp_int;
        }
        if(B==10)
        {
            reverse(yaddash,N);
            C=*toplayici(yaddash,N,N,16);
        }
        else if(B==2 || B==8)
                {
                    for(i=0;i<N;i++) {yaddash_m[i]=kechirt_10_2(yaddash_m[i]);}
                    C=log_2_cemleyici(yaddash_m,N,4);
                    if(B==8)
                        {
                            
                            N=yaddash_N(C,10),yaddash=yaddash_f(C,10);
                            reverse(yaddash,N);
                            yaddash=log_2(yaddash,N,3);
                            if(N%3!=0) N=N+(3-N%3);
                            reverse(yaddash,N);
                            yaddash=toplayici(yaddash,N,3,10);
                            int r=N/3;
                            for(i=0;i<r;i++) {yaddash[i]=kechirt_2_10(yaddash[i]);}
                            reverse(yaddash,r);
                            C=*toplayici(yaddash,r,r,10);
                        }
                }
    }
    return C;
}
void kechirt_16(int A,int c)
{
    int N;
    if(A==10)
    {
        N=yaddash_N(c,16);
        int *yaddash=yaddash_f(c,16);
        reverse(yaddash,N);
        string C;
        int t;
        for(int i=0;i<N;i++)
        {
            if(yaddash[i]<10) t=0;
            else t=1;
            switch(t)
            {
                case 0:
                C[i]=char(yaddash[i]+48);
                break;
                case 1:
                C[i]=char(yaddash[i]+55);
                break;
            }
            cout<<C[i];
        }
    }
    else
    {
        N=yaddash_N(c,10);
        int *yaddash=yaddash_f(c,10);
        if(A==8)
        {
            reverse(yaddash,N);
            for(int i=0;i<N;i++) {yaddash[i]=kechirt_10_2(yaddash[i]);}
            c=log_2_cemleyici(yaddash,N,3);
            N=yaddash_N(c,10); yaddash=yaddash_f(c,10);
        }
        reverse(yaddash,N);
        yaddash=log_2(yaddash,N,4);
        if(N%4!=0) N=N+(4-N%4);
        reverse(yaddash,N);
        yaddash=toplayici(yaddash,N,4,10);
        N=N/4;
        for(int i=0;i<N;i++) {yaddash[i]=kechirt_2_10(yaddash[i]);}
        for(int i=0;i<N;i++)
        {
            if(yaddash[i]<10) cout<<yaddash[i];
            else cout<<char(yaddash[i]+55);
        }
    }
    
}
int main()
{
    int A,B,c;
    string s;
    cout<<"Kechid etmek istediyiniz say sistemlerini daxil edin: "; cin>>A;
    if((A>0 && A<=10) || A==16) 
    {
        cin>>B;
        if((B>0 && B<=10) || B==16)
        {
            if(A!=B)
            {
                cout<<"Kechirmek istediyiniz ededi yazin: ";
                if(A==16) cin>>s;
                else 
                {
                    cin>>c;
                    if(c<0) exit(0);
                }
                if(B==16)
                {
                    kechirt_16(A,c);
                }
                else
                {
                    int p=c,q,t=0;
                    do{
                        q=p%10;
                        if(q>=A)
                        {
                            t=1;
                            break;
                        }
                        p/=10;
                    }while(p!=0);
                    if(t==0)
                    {
                        int C=kechirt(A,B,c,s);
                        cout<<C;
                    }
                }
            }
        }
    }
    return 0;
}