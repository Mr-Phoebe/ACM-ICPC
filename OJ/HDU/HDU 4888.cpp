#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <climits>

#define MAXN 120005
#define eps 1e-5

#define INF 0x3f3f3f3f

#define test

#define For(i,m,n) for(int i=(m);i<(n);i++)
#define vecfor(iter,a) for(vector<int>::iterator iter=a.begin();iter!=a.end();iter++)
#define rep(i,m,n) for(int i=(m);i<=(n);i++)
#define LL __int64


using namespace std;

struct Line
{
    int l, r, uod, y;
    int h;
} line[MAXN<<2];

struct node
{
    int l, r, mid;
    LL length, sum, cnt;
} arr[MAXN<<2];

LL num[MAXN];
int Hash[MAXN<<1];
int x[MAXN];

void build(int idx, int l, int r)
{
    arr[idx].l=l;
    arr[idx].r=r;
    arr[idx].length=Hash[r]-Hash[l];
    arr[idx].cnt=arr[idx].sum=0;
    int mid=(l+r)>>1;
    arr[idx].mid=mid;
    if(l+1<r)
    {
        build(idx<<1,l,mid);
        build(idx<<1|1,mid,r);
    }
}

void pushup(int idx)
{
    if(arr[idx].cnt)
        arr[idx].sum=arr[idx].length;
    else
    {
        if(arr[idx].l+1==arr[idx].r)
            arr[idx].sum=0;
        else
            arr[idx].sum=arr[idx<<1].sum+arr[idx<<1|1].sum;
    }
}

void update(int idx, int l, int r, int val)
{
    if(arr[idx].l>=l&&arr[idx].r<=r)
        arr[idx].cnt+=val;
    else
    {
        if(arr[idx].mid>l)
            update(idx<<1,l,r,val);
        if(arr[idx].mid<r)
            update(idx<<1|1,l,r,val);
    }
    pushup(idx);
}

bool cmp(Line a, Line b)
{
    return a.y<b.y;
}

int main()
{
    int t, cs=1;
    int n, m, l, r;
    int x1, x2, y1, y2, type;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        rep(i,1,m)
            scanf("%I64d",&num[i]);
        int tot=1;
        rep(i,1,n)
        {
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&type);
            int down=tot, up=tot+1;         // make it a line
            line[up].l=line[down].l=x1;     //left->right
            line[up].r=line[down].r=x2;
            line[up].h=line[down].h=num[type];
            line[down].y=y1;        // high
            line[up].y=y2;
            line[down].uod=1;       // kind
            line[up].uod=-1;
            Hash[down]=x1, Hash[up]=x2;     //there are each begin and end
            tot+=2;
        }
        sort(line+1,line+tot,cmp);
        sort(Hash+1,Hash+tot);
        sort(num+1,num+m+1);
        int cnt=unique(Hash+1,Hash+tot)-Hash;
        LL ans=0;
        rep(j,1,m)
        {
            build(1,1,cnt-1);
            LL temp=0;
            int pre=0;
            rep(i,1,tot-1)          //  discretization of the x
                if(line[i].h>=num[j])
                {
                    temp+=arr[1].sum*(line[i].y-line[pre].y);
                    int x1=lower_bound(Hash+1,Hash+cnt,line[i].l)-Hash;
                    int x2=lower_bound(Hash+1,Hash+cnt,line[i].r)-Hash;
                    update(1,x1,x2,line[i].uod);
                    pre=i;
                }
            ans+=temp*(num[j]-num[j-1]);
        }
        printf("Case %d: %I64d\n",cs++,ans);
    }
    return 0;
}
