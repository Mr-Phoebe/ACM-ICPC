#include<iostream>
#include<cstdio>

using namespace std;

const int INF=111111111;

struct apple
{
	int k,num;
}a[1005];

int main()
{
//	freopen("data.txt","r",stdin);
	int t,w,temp,last,n,top=0;
	scanf("%d %d",&t,&w);
	scanf("%d",&temp);
	last=temp;n=1;
	for(int i=1;i<t;i++)
	{
		scanf("%d",&temp);
//		cout<<temp<<" "<<n<<endl;
		if(temp==last)
			n++;	
		else
		{
			a[top].k=last;
			a[top++].num=n;
			n=1;last=temp;	
		}
	}
	a[top].k=last;
	a[top++].num=n;
//	for(int i=0;i<top;i++)
//			cout<<a[i].k<<" "<<a[i].num<<endl;
	int s=0,d=0,ma=0;n=0;temp=0;
	while(d<top)
	{
		if(a[s].k==1)
			while(n<w+1&&d<top)
			{
				n++;
				temp+=a[d++].num;
			}
		else
			while(n<w&&d<top)
			{
				n++;
				temp+=a[d++].num;
			}
		ma=max(ma,temp);
//		cout<<temp<<endl;
		temp-=a[s++].num;
		n--;
	}
	printf("%d\n",ma);
	return 0;
}
 