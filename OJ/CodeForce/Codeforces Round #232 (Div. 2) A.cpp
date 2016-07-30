#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
	int x,y;
}a[111];

bool cmp(struct Node a,struct Node b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	else
		return a.y>b.y;
}

int main() 
{
	int n,xx,yy;
	int ans;
//	freopen("data.txt","r",stdin);
	cin>>n;
	cin>>xx>>yy;
	ans=yy-xx;
	for(int i=1;i<n;i++)
		cin>>a[i].x>>a[i].y;	
	sort(a+1,a+n,cmp);
	for(int i=1;i<n;i++)
	{
		if(a[i].x<=xx)
		{
			if(a[i].y<=xx)
				continue;
			else
			{
				if(a[i].y<=yy)
				{
					ans-=a[i].y-xx;xx=a[i].y;
				}
				else
				{
					ans-=yy-xx;break;
				}
			}
				
		}
		else if(a[i].x>=yy)
			break;
		else
		{	
			if(a[i].y<=yy)
			{
				ans-=a[i].y-a[i].x;
				xx=a[i].y;
			}
			else
			{
				ans-=yy-a[i].x;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}