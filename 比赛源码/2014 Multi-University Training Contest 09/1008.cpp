#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 50009
#define lo (o<<1)
#define ro (o<<1|1)
#define mid ((l+r)>>1)

struct NODE
{
	int sum, rmax;
};

NODE tree[maxn<<2];
int t,n,v[maxn][2],a[maxn],value[maxn<<2],pl;
char ch[maxn][10];

void insert(int o,int l,int r,int id,int x)
{
    if(l==r)
    {
        value[o]=x;
        if (x >= 0) tree[o].sum = tree[o].rmax = 1;
	else
	{
		tree[o].sum = -1;
		tree[o].rmax = 0;
	}
        return;
    }
    if(mid>=id) insert(lo,l,mid,id,x);
    else insert(ro,mid+1,r,id,x);
    tree[o].sum = tree[lo].sum + tree[ro].sum;
    tree[o].rmax = max(tree[ro].rmax, tree[ro].sum + tree[lo].rmax);
}

int query(int o,int l,int r,int id)
{
    int ret;
    if(r<=id)
    {
        int pll = pl + tree[o].rmax;
        if(pll<=0)
        {
	    pl += tree[o].sum;
            return -1;
        }
    }
    if(l==r) return value[o];
    if(mid<id) 
    {
	ret = query(ro,mid+1,r,id);
    	if (ret != -1) return ret;
    }
    return query(lo,l,mid,id);
}

bool init()
{
    scanf("%d",&n);
    if (!n) return false;
    memset(tree, 0, sizeof(tree));
    t = 0;
    for(int i=0;i<n;++i)
    {
        scanf("%s",ch[i]);
        if(ch[i][1]=='u') scanf("%d%d",&v[i][1],&v[i][0]);
        else scanf("%d",&v[i][0]);
        if (ch[i][1] != 'e') a[t++]=v[i][0];
    }
    sort(a,a+t);
    return true;
}

inline int getid(int x) {return lower_bound(a,a+t,x)-a;}

int ca=1;
void solve()
{
    printf("Case #%d:\n",ca++);
    for(int i=0;i<n;++i)
    {
	int id = getid(v[i][0]);
        if(ch[i][1]=='u') insert(1,0,t-1,id,v[i][1]);
        else if(ch[i][1]=='o') insert(1,0,t-1,id,-1);
        else 
        {
	    if (!id) printf("-1\n");
	    else
	    {
            	pl=0;
            	printf("%d\n", query(1,0,t-1,id-1));
	    }
        }
    }
}

int main()
{
    while(1)
    {
        if (!init()) break;
        solve();
    }
    return 0;
}  
