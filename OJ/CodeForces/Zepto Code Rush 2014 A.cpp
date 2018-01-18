#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
	int t,h,m;
}a[2010],b[2010];

int n,x,ans1=0,ans2=0;

bool cmp(Node a,Node b)
{
		return a.m>b.m;
}

int main()
{
	scanf("%d %d",&n,&x);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&a[i].t,&a[i].h,&a[i].m);
		b[i].t=a[i].t;
		b[i].h=a[i].h;
		b[i].m=a[i].m;
	}	
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
//	for(int i=0;i<n;i++)
//		printf("%d %d\n",a[i].h,a[i].m);
	int temp=0,c=x;
	for(int i=0;i<n;i++)
		if(a[i].t==temp&&c>=a[i].h)
		{
			c+=a[i].m;
			ans1++;
			temp=!temp;
			a[i].t=3;//≥‘ÕÍ¡À 
			i=-1;
		}
	temp=1;c=x;
	for(int i=0;i<n;i++)
		if(b[i].t==temp&&c>=b[i].h)
		{
			c+=b[i].m;
			ans2++;
			temp=!temp;
			b[i].t=3;
			i=-1;
		}
	printf("%d\n",max(ans1,ans2));
	return 0;
}

/*
8 2
0 20 3
1 5 2     
1 4 1     
1 7 1     
0 1 3     
1 5 3
1 7 2
1 3 1     

Answer
2

*/
 