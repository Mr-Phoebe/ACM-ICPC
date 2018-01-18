#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    long long int a,b,w,x,c;
    scanf("%I64d%I64d%I64d%I64d%I64d",&a,&b,&w,&x,&c);
    if(c<=a)
    {
        puts("0"); return 0;
    }

    long long ans=(a*w-c*w+b)/(x-w);

    if(abs(ans*(x-w))<abs(a*w-c*w+b)) ans++;

    printf("%I64d\n",ans);

    return 0;
}


/* 

    c'=c-t;

   a'=a- (x*t-b)/w; 

    c'<=a';

    t>= (a*w-cw+b)/(x-w);*/
