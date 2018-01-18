#include <cstdio>
#include <algorithm>

#define rep(i,l,r) for (int i=l;i<=r;++i)

int getx()
{
	char c;int x;bool pd=false;
	for (c=getchar();c!='-'&&(c<'0'||c>'9');c=getchar());
	if (c=='-') c=getchar(),pd=true;
	for (x=0;c>='0'&&c<='9';c=getchar())
		x=(x<<3)+(x<<1)+c-'0';
	return pd?-x:x;
}
bool upmin(int &a,const int &b){return a>b?a=b,1:0;}
bool upmax(int &a,const int &b){return a<b?a=b,1:0;}
const int MAX_N=1050;
const int INF=~0U>>2;
int a[MAX_N];
int n;
int minN=INF,minD,minF;
int main()
{
	n=getx();
	rep(i,1,n) a[i]=getx();
	std::sort(a+1,a+n+1);
	rep(d,0,20000)
	{
		int min=INF,max=-INF;
		rep(i,1,n)
		{
			upmin(min,a[i]-(i-1)*d);
			upmax(max,a[i]-(i-1)*d);
		}
		int now=(max-min+1)/2;
		if (upmin(minN,now))
		{
			minD=d;
			minF=now+min;
		}
	}
	printf("%d\n%d %d\n",minN,minF,minD);
}