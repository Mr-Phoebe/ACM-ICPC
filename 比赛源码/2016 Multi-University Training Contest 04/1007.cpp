#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1000010;
const int M = 100010;
const int inf = 0x37373737*2;
int dp,pre[N],p[N],tt[N],L[N],R[N],id,value[N];
int jump[M][18],deep[N],n,m,i,a,b,c,cnt,sum;
int v[N],s[N];
struct G{
	int x,l,r,v;
	void set(int a,int b,int c,int d)
	{
		x=a;l=b;r=c;v=d;
	}
}g[N];
bool cmp(G a,G b)
{
	return a.x<b.x;
}
void link(int x,int y)
{
	dp++;pre[dp]=p[x];p[x]=dp;tt[dp]=y;
}
void dfs(int x,int fa)
{
	int i;
	L[x]=++id;
	jump[x][0]=fa;
	for (i=1;i<=17;i++)
	jump[x][i]=jump[jump[x][i-1]][i-1];
	deep[x]=deep[fa]+1;
	i=p[x];
	while (i)
	{
		if (tt[i]!=fa)
		dfs(tt[i],x);
		i=pre[i];
	}
	R[x]=id;
}
void clean(int x)
{
	if (v[x])
	{
		s[x]+=v[x];
		v[2*x]+=v[x];
		v[2*x+1]+=v[x];
		v[x]=0;
	}
}
void change(int x,int a,int b,int l,int r,int c)
{
	clean(x);
	if ((a<=l)&&(r<=b))
	{
		v[x]+=c;
		return;
	}
	int m=(l+r)>>1;
	if (a<m) change(2*x,a,b,l,m,c);
	if (m<b) change(2*x+1,a,b,m,r,c);
	clean(2*x);clean(2*x+1);
	s[x]=max(s[2*x],s[2*x+1]);
}
int getlca(int x,int y,int typ)
{
	if (deep[x]<deep[y]) x^=y^=x^=y;
	int i;
	if (typ==0)
	{
	for (i=17;i>=0;i--)
	if (deep[jump[x][i]]>=deep[y]) x=jump[x][i];
	if (x==y) return x;
	for (i=17;i>=0;i--)
	if (jump[x][i]!=jump[y][i]) x=jump[x][i],y=jump[y][i];
	return jump[x][0];
	}
	else
	{
	for (i=17;i>=0;i--)
	if (deep[jump[x][i]]>deep[y]) x=jump[x][i];
	return x;
	}
}
void set(int a,int b,int c,int d,int e)
{
	if ((a==0)||(b==0)||(c==0)||(d==0)) return;
	if ((a==n+1)||(b==n+1)||(c==n+1)||(d==n+1)) return;
	g[++cnt].set(a,c,d,e);g[++cnt].set(b+1,c,d,-e);
}
void gao(int x,int y)
{
	int i=p[x];
	set(1,L[x]-1,1,L[x]-1,y);
	set(R[x]+1,n,R[x]+1,n,y);
	set(1,L[x]-1,R[x]+1,n,y);
	set(R[x]+1,n,1,L[x]-1,y);
	while (i)
	{
		if (tt[i]!=jump[x][0]) set(L[tt[i]],R[tt[i]],L[tt[i]],R[tt[i]],y);
		i=pre[i];
	}
}
void init()
{
	int i;
	dp=cnt=sum=id=0;
	for (i=1;i<=n;i++) p[i]=L[i]=R[i]=deep[i]=jump[i][0]=value[i]=0;
	for (i=1;i<=4*n;i++) v[i]=s[i]=0;
}
int main()
{
	int ii,test;
	scanf("%d",&test);
	for (ii=1;ii<=test;ii++)
	{
	scanf("%d%d",&n,&m);
	init();
	for (i=1;i<n;i++)
	{ 
		scanf("%d%d",&a,&b);
		link(a,b);
		link(b,a); 
	} 
	dfs(1,0);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		int lca=getlca(a,b,0);
		if (a==b)
		{
			sum+=c;
			value[a]+=c;
		}
		else
		if (lca==a)
		{
			a=getlca(a,b,1);
			set(1,L[a]-1,L[b],R[b],c);
			set(R[a]+1,n,L[b],R[b],c);
		}
		else
		if (lca==b)
		{
			b=getlca(a,b,1);
			set(L[a],R[a],1,L[b]-1,c);
			set(L[a],R[a],R[b]+1,n,c);
		}
		else
			set(L[a],R[a],L[b],R[b],c);
	}
	for (i=1;i<=n;i++)
	if (value[i]) gao(i,-value[i]);
	sort(g+1,g+1+cnt,cmp);
	g[cnt+1].x=0;
	int ans=-inf;
	for (i=1;i<=cnt;i++)
	{
		change(1,g[i].l-1,g[i].r,0,n,g[i].v);
		if (g[i].x!=g[i+1].x)
		{
			clean(1);
			ans=max(ans,s[1]+sum);
		}
	} 
	printf("Case #%d: %d\n",ii,ans);
	}
	
}