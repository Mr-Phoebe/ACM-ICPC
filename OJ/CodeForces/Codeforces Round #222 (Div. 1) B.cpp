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

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

const int MAXN=100010;
int n,m,s;
int ans[MAXN];

struct Node
{  
    int id, val, pass;  
    friend bool operator <(const Node& a, const Node& b)
	{  
        return a.pass > b.pass;  
    }  
}p[MAXN], bug[MAXN]; 

bool cmp(const Node& a, const Node& b)
{  
    return a.val > b.val;  
} 
  
bool judge(int k)
{  
    int a=1,b=1,sum=s;  
    priority_queue<Node> q;  
    while(b<=m)
	{  
        while(a<=n)
		{  
            if(p[a].val >= bug[b].val)
				q.push(p[a]);  
            else
				break;  
            a++;  
        }  
        if(q.empty())
			return false;  
        Node c=q.top();q.pop();  
        if(sum<c.pass)
			return false;  
        sum-=c.pass;  
        b+=k;  
    }  
    return true;      
}  

void sovle(int k)
{
	int a=1,b=1;  
    priority_queue<Node> q;  
    while(b<=m)
	{  
        while(a<=n)
		{  
            if(p[a].val >= bug[b].val)
				q.push(p[a]);  
            else
				break;  
            a++;  
        }  
        Node c=q.top();q.pop();  
        for(int i=b;i<min(m+1,b+k);i++)
        	ans[bug[i].id]=c.id;
        b+=k;  
    }        
} 


int main()
{
	read(n),read(m),read(s);
	for(int i=1;i<=m;i++)
		read(bug[i].val),bug[i].id=i;
	for(int i=1;i<=n;i++)
		read(p[i].val),p[i].id=i;
	for(int i=1;i<=n;i++)
		read(p[i].pass);
	sort(p+1,p+1+n,cmp);
	sort(bug+1,bug+1+m,+cmp);
/*
	for(int i=1;i<=m;i++)
		cout<<bug[i].val<<" ";
	cout<<endl;
*/
	if(!judge(m))
	{
		puts("NO");
		return 0;
	}
	int l=1,r=m;
	while(l<r)
	{
		int mid=MID(l,r);
		if(judge(mid))
			r=mid;
		else 
			l=mid+1;
	}
	sovle(r);
	puts("YES");
	for(int i=1;i<=m;i++)
		write(ans[i]),putchar(' ');
	putchar('\n');
	return 0;
}