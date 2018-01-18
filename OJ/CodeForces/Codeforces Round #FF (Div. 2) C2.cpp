#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

#define inf 0x7fffffff
#define ll long long

using namespace std;

const int MAXN=100010;

inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n,ans=1;
int a[MAXN],l[MAXN],r[MAXN];

int main()
{
//    freopen("data.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        ans=1;
        for(int i=0;i<n;i++)
            a[i]=read();
        if(n==1)
        {
            cout<<"1"<<endl;continue;
        }
        else if(n==2)
        {
            cout<<"2"<<endl;continue;
        }
        l[0]=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
                l[i]=l[i-1]+1;
            else
                l[i]=1;
        }
        r[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i+1]>a[i])
                r[i]=r[i+1]+1;
            else
                r[i]=1;
        }
/*        for(int i=0;i<n;i++)
            cout<<l[i]<<" "<<r[i]<<endl;*/
        for(int i=1;i<n-1;i++)
            if(a[i-1]+1<a[i+1])
                ans=max(ans,l[i-1]+1+r[i+1]);
        for(int i=1;i<n;i++)
            if(a[i]<=a[i-1])
                ans=max(ans,l[i-1]+1);
        for(int i=0;i<n-1;i++)
            if(a[i]>=a[i+1])
                ans=max(ans,r[i+1]+1);

        printf("%d\n",ans);
    }

}
