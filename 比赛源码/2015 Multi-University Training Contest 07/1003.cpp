#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#define eps 1e-9
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define MAXN 1005
#define MAXM 40005
#define INF 0x3fffffff
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define clr(x,y) memset(x,y,sizeof(x));
using namespace std;
typedef long long LL;
int i,j,k,n,m,x,y,T,ans,big,cas,num,len;
bool flag;
int p[200005],a[200005],b[400005],pp[400005];
set<int>st;
set<int>::iterator it;
struct node
{
    int u,id;
}lis[200005];
int u,id;


void KP()
{
    int mx=0;
    int id;
    for (int i=1; i<=m; i++)
    {
        if (mx>i) p[i]=min(p[2*id-i],p[id]+id-i);
        else p[i]=1;

        while (b[i+p[i]]==b[i-p[i]]) p[i]++;

        if (p[i]+i>mx)
        {
            mx=p[i]+i;
            id=i;
        }
    }
}
int red()
{
    char z=getchar();
    while (z<'0' || z>'9') z=getchar();
    int ans=0;
    while (z>='0' && z<='9') {
        ans=ans*10+z-'0';
        z=getchar();
    }
    return ans;
}

void init()
{
    memset(b,-1,sizeof(b));
    for (i=1; i<=n; i++) b[i*2]=a[i];
    m=2*n;
}

bool cmp(node a,node b)
{
    return a.u>b.u;
}

int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("21.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
    	n=red();
        for (i=1; i<=n; i++)
        {
            a[i]=red();
        }
        init();
        KP();
        int mx=0;
        for (i=1; i<=n; i++)
        {
            lis[i].u=(p[i*2+1]-1)/2;
            lis[i].id=i;
        }
        ans=0;
        sort(lis+1,lis+1+n,cmp);
        st.clear();
        for (i=1; i<=n; i++)
        {
            u=lis[i].u;
            id=lis[i].id;
            if (u==0) break;
            st.insert(id);
            it=st.upper_bound(u+id);
            it--;
            ans=max(ans,*it-id);
            it=st.lower_bound(id-u);
            ans=max(ans,id-*it);
        }
        printf("Case #%d: %d\n",++cas,ans*3);
    }
    return 0;
}
