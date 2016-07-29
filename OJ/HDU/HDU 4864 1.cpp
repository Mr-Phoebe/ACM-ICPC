#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#define pi acos(-1.0)
#define eps 1e-8
#define ll __int64
#define L 1000050
#define N 1050
#define Mod 1000000007
#define M 99999999999

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

struct Node
{
    int t,l;
    Node(){}
    Node(int t,int l):t(t),l(l){}
    bool operator < (const Node &b) const
    {
        if(t==b.t)
            return l<b.l;
        return t<b.t;
    }
}r[100010];

int n,m,ans;
ll money=0;

int main()
{
	freopen("data.txt","r",stdin);
    while(read(n)&&read(m))
    {
    	multiset<Node> a;
        Node temp;
        money=0;ans=0;
        for(int i=0;i<n;i++)
        {
            read(temp.t),read(temp.l);
            a.insert(temp);
        }
        for(int i=0;i<m;i++)
            read(r[i].t),read(r[i].l);
        sort(r,r+m);
        for(int i=m-1;i>=0;i--)
        {
            for(multiset<Node>::iterator it=a.lower_bound(r[i]);it!=a.end();it++)
                if((*it).l>=r[i].l)
                {
                	int x=r[i].t,y=r[i].l;
	                money+=x*500ll+2ll*y;
	                ans++;
	                a.erase(it);
	                break;
                }
        }
        cout<<ans<<" "<<money<<endl;
    }
    return 0;
}