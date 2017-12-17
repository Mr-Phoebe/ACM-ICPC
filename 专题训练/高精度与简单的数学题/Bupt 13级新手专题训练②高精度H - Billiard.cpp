#include<iostream>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
#define PI 3.1415926535797938462643383227950 
using namespace std;

int main ()  
{  
    long long a,b,s,m,n;  
    double A,v;  
    while(cin>>a>>b>>s>>m>>n)  
    {  
        if (a==0) break;  
        long long L,H;  
        double d;  
        L=a*m;  
        H=b*n;  
        d=L*L+H*H;  
        d=sqrt(d);  
        v=d/s;  
        A=atan(H/(L*1.0))*180/PI;  
        printf("%.2lf %.2lf\n",A,v);  
    }  
    return 0;  
}  