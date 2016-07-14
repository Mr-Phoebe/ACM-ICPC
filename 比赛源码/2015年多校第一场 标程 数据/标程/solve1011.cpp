#include<cstdio>
using namespace std;
struct P
{
	__int64 x,y,z;
};
struct Plane 
{
	__int64 a,b,c,d;
};
Plane pls[110];
struct B
{
	__int64 x,y,z,r;
};
B bs[20];
int m,n;
inline int fp(const Plane& pl,const P& p)//在哪一侧
{
	return pl.a*p.x+pl.b*p.y+pl.c*p.z+pl.d>0?1:0;
}
inline int fb(const B& b,const P& p)
{
	return (p.x-b.x)*(p.x-b.x)+(p.y-b.y)*(p.y-b.y)+(p.z-b.z)*(p.z-b.z)>b.r*b.r?1:0;
}
inline int f(const P& p)
{
	int ans=0,i;
	for(i=0;i<m;++i)
	{
		ans^=fp(pls[i],p);
	}
	for(i=0;i<n;++i)
	{
		ans^=fb(bs[i],p);
	}
	return ans;
}
int main()
{
	int T,i,p,q;
	P pt;
	int xot;//xot是异或的调整变量 
	bool tag;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&m,&n,&p,&q);
		for(i=0;i<m;++i)
		{
			scanf("%I64d%I64d%I64d%I64d",&pls[i].a,&pls[i].b,&pls[i].c,&pls[i].d);
		}
		for(i=0;i<n;++i)
		{
			scanf("%I64d%I64d%I64d%I64d",&bs[i].x,&bs[i].y,&bs[i].z,&bs[i].r);
		}
		if(p==0)
		{
			while(q--)
			{
				scanf("%I64d%I64d%I64d",&pt.x,&pt.y,&pt.z);
				puts("Both");
			}
			T?putchar('\n'):1;
			continue;
		}
		scanf("%I64d%I64d%I64d",&pt.x,&pt.y,&pt.z);
		//red:0 yellow:1
		xot=f(pt)^1;
		tag=true;
		while(--p)
		{
			scanf("%I64d%I64d%I64d",&pt.x,&pt.y,&pt.z);
			if(f(pt)^xot!=1)
			{
				puts("Impossible");
				T?putchar('\n'):1;
				tag=false;
				break;
			}
		}
		if(!tag)//不合法，处理剩余输入 
		{
			while(--p)
			{
				scanf("%I64d%I64d%I64d",&pt.x,&pt.y,&pt.z);
			}
			while(q--)
			{
				scanf("%I64d%I64d%I64d",&pt.x,&pt.y,&pt.z);
			}
			continue; 
		}
		while(q--)
		{
			scanf("%I64d%I64d%I64d",&pt.x,&pt.y,&pt.z);
			puts((f(pt)^xot)?"Y":"R");
		}
		T?putchar('\n'):1;
	}
	return 0;
}

