#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const __int64 mx=2000000200000000000LL;
vector<__int64> data[63];
bool prime[63]={false,false,true,true,false,true,false,true,false,false,false,true,false,true,false,false,
false,true,false,true,false,false,false,true,false,false,false,false,false,true,false,true,false,false,false,
false,false,true,false,false,false,true,false,true,false,false,false,true,false,false,false,false,false,true,
false,false,false,false,false,true,false,true,false};
inline __int64 fp(__int64 x,int n)//快速幂
{
	__int64 ans=1;
	while(n)
	{
		n&1?ans*=x:1;
		x*=x;
		n>>=1;
	}
	return ans;
}
int Moeb[66][66][2],Ms[66];//莫比乌斯函数
inline void calcM()//计算莫比乌斯函数 
{
	int i,j,r;
	int arr[66],mt[66],mst;
	for(r=2;r<63;++r)
	{
		for(i=2;i<63;++i)
		{
			arr[i]=i;
			mt[i]=-1;
		}
		for(i=2;i<=r;++i)
		{
			if(!prime[i])
			{
				continue;
			}
			for(j=i;j<63;j+=i)
			{
				arr[j]/=i;
				mt[j]*=-1;
			}
		}
		mst=0;
		for(i=2;i<63;++i)
		{
			if(arr[i]==1)
			{
				Moeb[r][mst][0]=i;
				Moeb[r][mst++][1]=mt[i];
			}
		}
		Ms[r]=mst;
	}
	return;
}
inline void getdata()//打表
{
	int i,j,r;
	__int64 t,lim;
	for(i=1;i<Ms[62];++i)
	{
		r=Moeb[62][i][0];
		lim=pow(3e18,1.0/r);
		for(j=1;j<=lim;++j)
		{
			t=fp(j,r);
			if(t<mx)
			{
				data[r].push_back(t);
			}
		}
	}
	return;
}
inline __int64 mypow(__int64 x,int n)//x开n次方向下取整
{
	__int64 ans;
	if(n==2)
	{
		ans=floor(sqrt(x*1.0));
		while(ans*ans<x)
		{
			++ans;
		}
		while(ans*ans>x)
		{
			--ans;
		}
		return ans;
	}
	return upper_bound(data[n].begin(),data[n].end(),x)-data[n].begin();
}
inline bool del(__int64 x,int r)//x是否被删除
{
	if(x==1)
	{
		return true;
	}
	int i;
	vector<__int64>::iterator p;
	__int64 t=mypow(x,2);
	if(t*t==x)
	{
		return true;
	}
	for(i=2;i<=r;++i)
	{
		if(!prime[i])
		{
			continue;
		}
		p=lower_bound(data[i].begin(),data[i].end(),x);
		if(p!=data[i].end()&&(*p)==x)
		{
			return true;
		}
	}
	return false;
}
inline __int64 f(__int64 x,int r)//x之前有多少被删除的
{
	if(x==1)
	{
		return 0;
	}
	__int64 ans=0;
	int i;
	for(i=0;i<Ms[r];++i)
	{
		ans+=(mypow(x,Moeb[r][i][0])-1)*Moeb[r][i][1];
	}
	return ans+1;
}
int main()
{
	calcM();
	getdata();
	int i,T,r;
	__int64 n,ans,t;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%d",&n,&r);
		ans=n+f(n,r);
		if(del(ans,r))
		{
			++ans;
		}
		if(ans==9)
		{
			++ans;
		}
		while((t=n+f(ans,r))!=ans)
		{
			ans=n+f(t,r);
			if(del(ans,r))
			{
				++ans;
			}
			if(ans==9)
			{
				++ans;
			}
		}
		printf("%I64d\n",ans); 
	}
	return 0;
}

