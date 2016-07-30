#include<iostream>
#include<cstdio>

using namespace std;

struct candy
{
	int v,u;
}c[100100];

int n,m,temp;
int x,y,z,p;

int main()
{
//	freopen("data.txt","r",stdin);
	scanf("%d %d %d %d %d %d",&n,&m,&x,&y,&z,&p);
	for(int i=1;i<=p;i++)
		scanf("%d %d",&c[i].v,&c[i].u);
	x%=4;y%=2;z%=4;
	switch(x)
	{
		case 1:
			for(int i=1;i<=p;i++)
			{
				temp=c[i].v;
				c[i].v=c[i].u;
				c[i].u=n-temp+1;	
			}
			temp=m;
			m=n;
			n=temp;
			break;
		case 2:
			for(int i=1;i<=p;i++)
			{
				c[i].v=n-c[i].v+1;
				c[i].u=m-c[i].u+1;
			}
			break;
		case 3:
			for(int i=1;i<=p;i++)
			{
				temp=c[i].v;
				c[i].v=m-c[i].u+1;
				c[i].u=temp;
			}
			temp=m;
			m=n;
			n=temp;
			break;
	}
	switch(y)
	{
		case 1:
			for(int i=1;i<=p;i++)
				c[i].u=m-c[i].u+1;
	}
	switch(z)
	{
		case 1:
			for(int i=1;i<=p;i++)
			{
				temp=c[i].v;
				c[i].v=m-c[i].u+1;
				c[i].u=temp;
			}
			break;
		case 2:
			for(int i=1;i<=p;i++)
			{
				c[i].v=n-c[i].v+1;
				c[i].u=m-c[i].u+1;
			}
			break;
		case 3:
			for(int i=1;i<=p;i++)
			{
				temp=c[i].v;
				c[i].v=c[i].u;
				c[i].u=n-temp+1;
			}
			break;
	}
	for(int i=1;i<=p;i++)
		printf("%d %d\n",c[i].v,c[i].u);
	return 0;
}