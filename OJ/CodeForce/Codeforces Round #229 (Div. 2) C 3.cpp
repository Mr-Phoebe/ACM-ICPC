#include<iostream>
#include<cstdio>

using namespace std;

int n,k,w;
int c[100010];
int bintree[100010];
int sum[100010];
int cou[100010];

int lowbit(int i)
{ return i&(-i); }

int getsum(int i)
{
	int sum = 0;
	while (i > 0)
		sum += bintree[i], i -= lowbit(i);
	return sum;
}

void update(int pos, int vari, int len)
{
	while (pos <= len)
		bintree[pos] += vari, pos += lowbit(pos);
}

int main()
{
	cin>>n>>k>>w;
	getchar();
	for(int i=1;i<=n;i++)
	{
		char ch;
		ch=getchar();
		c[i]=(int)ch-48;
		if(c[i]==1)
		{
			update(i,c[i],n);
			sum[i]=getsum(i);
			if(i>k)
				cou[i]=cou[i-k];
			else
				cou[i]=0;
		}
		else
		{	
			if(i>k)
				cou[i]=cou[i-k]+1;
			else
				cou[i]=1;
			sum[i]=sum[i-1];
		} 
	}

	for(int i=1;i<=w;i++)
	{
		int l,r;
		cin>>l>>r;
		int time=(r-l+1)/k;
		int temp=sum[r]-sum[l-1];
		int ans=cou[r]-cou[l-1];
		ans+=temp-time+ans;
		cout<<ans<<endl;
	}
	return 0;
} 