#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int T,a,b,c,A,B,C,ans1,ans2,g;

char ch;
void read(int &x)
{
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
    for(x=0;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
}

void print(int A,int B)
{
    ans1=abs(A-B)*360;ans2=12*60*60;
    g=__gcd(ans1,ans2);
    ans1/=g;ans2/=g;
    if(ans1>180*ans2)ans1=360*ans2-ans1;
    if(ans2==1)printf("%d ",ans1);else printf("%d/%d ",ans1,ans2);
}

int main()
{
    scanf("%d",&T);
    for(;T;--T)
    {
        read(a);read(b);read(c);
        a%=12;
        A=(a*60+b)*60+c;
        B=12*(b*60+c);
        C=12*60*c;
        print(A,B);
        print(A,C);
        print(B,C);
        printf("\n");
    }
}