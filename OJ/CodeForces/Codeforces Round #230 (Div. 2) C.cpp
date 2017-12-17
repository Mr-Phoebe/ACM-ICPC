#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

typedef __int64 LL;

LL dis(LL x,LL y)
{
    return x*x+y*y;
}
int main()
{
    LL n;
    LL i,st;
    while(~scanf("%I64d",&n))
    {
        if(n==0)
        {
            cout<<"1"<<endl;
            continue;
        }
        LL sum=0;
        st=n;
        LL leap;
        for(i=0;i<n;i++)
        {
            leap=0;
            while(n*n<dis(i+1,st))
            {
                sum++;
                st--;
                leap=1;
            }
            if(leap==0)
                sum++;
        }
        cout<<sum*4<<endl;
    }
    return 0;
}
