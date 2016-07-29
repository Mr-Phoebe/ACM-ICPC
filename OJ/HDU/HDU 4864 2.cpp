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
//---------------------------------------------------------------------------

typedef long long ll;
const int MAXN=100005;

struct Node
{
    int x, y;
    bool operator<(const Node &b) const
	{
        if(x==b.x)
            return y>b.y;
        return x>b.x;
    }
}a[MAXN];

int main()
{
	freopen("data.txt","r",stdin);
    int n, m;
    while(read(n)&&read(m))
	{
        multiset<int> s[105];
        ll money=0;
        int maxx=0,ans=0;
        for(int i=0;i<n;i++)
		{
            int x,y;
            read(x),read(y);
            s[y].insert(x);
            if(maxx<y)
            	maxx=y;
        }
        for(int i=0;i<m;i++)
            read(a[i].x),read(a[i].y);
        sort(a,a+m);
        for(int i=0;i<m;i++)
		{
            int x=a[i].x;
            int y=a[i].y;
            for(int j=y;j<=maxx;j++)
			{
                if(s[j].empty())
                    continue;
                multiset<int>::iterator it=s[j].lower_bound(x);
                if(it==s[j].end())
                    continue;
                else
				{
                    ans++;
                    money+=500ll*x+2ll*y;
                    s[j].erase(it);
                    break;
                }
            }
        }
        printf("%d %I64d\n",ans,money);
    }
    return 0;
}
