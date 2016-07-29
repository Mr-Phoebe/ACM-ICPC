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

using namespace std;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
//-------------------------

typedef long long ll;
const int M=1000000009;
const int MAXN=100010;
ll p[MAXN]={1};

ll qpow(ll a,ll b)  
{  
    ll ans=1;  
    while(b)  
    {  
        if(b&1)  
            ans=(ans*a)%M;   
        b>>=1;  
        a=((a%M)*(a%M))%M;  
    }  
    return ans;  
}  


int main()
{
	for(int i=1;i<MAXN;i++)
		p[i]=(p[i-1]*i)%M;
    int n,m,l,r,tl,tr;
    while(read(n)&&read(m))
    {
        l=r=0;
        for(int i=0;i<n;i++)
        {
            int x;
            read(x);
            if(l>=x)
                tl=l-x;
            else if(r>=x)
                tl=(l%2)==(x%2) ? 0:1;
            else
                tl=x-r;
            if(r+x<=m)
                tr=r+x;
            else if(l+x<=m)
                tr=(r+x-m)%2==0 ? m:m-1;
            else
                tr=2*m-(l+x);
            l=tl;r=tr;
        }
        ll sum=0;
        for(int i=l;i<=r;i+=2)
            sum=(sum+(p[m]%M)*(qpow((p[i]*p[m-i])%M,M-2)%M))%M;
        printf("%I64d\n",sum%M);
    }
	return 0;
}
