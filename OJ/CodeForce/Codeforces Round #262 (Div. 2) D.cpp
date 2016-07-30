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
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------
int main()
{
    long long l,r,k,i,x,p,v;
    read(l),read(r),read(k);
    vector<long long> ans;
    if(l==r||k==1)
        ans.push_back(l);
    else
    {
        x=l+(l&1);                  //构造一个偶数
        if(x+3<=r&&k>=4)            //XOR为0
        {
            for(i=0; i<=3; i++)
                ans.push_back(x+i);
        }
        else                        //分类讨论k的大小
        {
            p=1;
            while(p<=l)
                p<<=1;
            p|=p>>1;
            if(p<=r&&(l^p)<=r&&k>=3)
            {
                ans.push_back(l);
                ans.push_back(l^p);
                ans.push_back(p);
            }
            else if(x+1<=r)
            {
                ans.push_back(x);
                ans.push_back(x+1);
            }
            else
            {
                ans.push_back(l);
                if ((l^(l+1))<=l)
                    ans.push_back(l+1);
            }
        }
    }
    v=ans[0];
    for(i=1; i<ans.size(); i++)
        v^=ans[i];
    cout<<v<<'\n'<< ans.size()<<'\n';
    for(i=0; i<ans.size(); i++)
        cout<<ans[i]<<' ';
}
