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
    T x = 0, tmp = 1; char c = getchar();
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

const int MAXN=500010;

struct Node
{
    int l,r,x;
    int idx,ans;
}a[MAXN];

int num[MAXN],ans_flag=0;
int n,q;

struct Trie
{
	int ch[2*MAXN][2];
	int v[2*MAXN];
	int sz;
	Trie(){ sz=1; }
	int idx(int x){ return x%2; }

	void insert(int x,int po)
	{
		int u=0;
		for(int i=13;i>=0;i--)
		{
			int c=idx(x>>i);//cout<<(x>>i)<<endl;
			if(!ch[u][c])
			{
				v[sz]=po;
				ch[u][c]=sz++;
			}
			v[u]=po;
//            cout<<" "<<u<<" "<<sz<<" "<<v[u]<<endl;
			u=ch[u][c];
		}
		v[u]=po;
//		cout<<x<<endl;
	}

	int find(int x,int l,int po,int i)
	{
	    if(i==-1&&v[po]>=l)
            return v[po];
        int c=idx(x>>i);//cout<<po<<" "<<i<<" "<<c<<" "<<v[po]<<endl;system("pause");
        if(ch[po][!c])
        {
            if(v[ch[po][!c]]>=l)
                return find(x,l,ch[po][!c],i-1);
            else
                return find(x,l,ch[po][c],i-1);
        }
        return find(x,l,ch[po][c],i-1);
	}

	void clear()
	{
	    sz=1;memset(ch,0,sizeof(ch));memset(v,0,sizeof(v));
	}
};

Trie s;

bool cmp(Node a,Node b)
{
    return a.r<b.r;
}

bool cmp1(Node a,Node b)
{
    return a.idx<b.idx;
}

int main()
{
    int T;
//    freopen("data.txt","r",stdin);
    read(T);
    while(T--)
    {
        s.clear();
        read(n),read(q);
        for(int i=1;i<=n;i++)
            read(num[i]);
        for(int i=1;i<=q;i++)
        {
            read(a[i].l);read(a[i].r);read(a[i].x);
            a[i].idx=i;
        }
        sort(a+1,a+q+1,cmp);
        int nr=1;
        for(int i=1;i<=q;i++)
        {
            ans_flag=0;
            for(int j=nr;j<=a[i].r;j++)
                s.insert(num[j],j);
            nr=a[i].r+1;
            a[i].ans=a[i].x^num[s.find(a[i].x,a[i].l,0,13)];//cout<<"  "<<a[i].ans<<endl;
        }
        sort(a+1,a+q+1,cmp1);
        for(int i=1;i<=q;i++)
            printf("%d\n",a[i].ans);
    }
    return 0;
}
