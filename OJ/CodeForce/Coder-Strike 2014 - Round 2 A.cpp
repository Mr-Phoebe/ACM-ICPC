#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n,m,mi,ma;
	int a[111];
	bool right=true;
	scanf("%d %d %d %d",&n,&m,&mi,&ma);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>ma||a[i]<mi)
			right=false;
	}
	bool find1=true,find2=true;
	if(n-m==1)
	{
		find1=false;
		for(int i=0;i<m;i++)
			if(a[i]==ma||a[i]==mi)
				find1=true;
	}	
	if(n==m)
	{
		find1=find2=false;
		for(int i=0;i<m;i++)
			if(a[i]==ma)
				find1=true;
			else if(a[i]==mi)
				find2=true;
	}	
	if(right&&find1&&find2)
		puts("Correct");
	else
		puts("Incorrect");
	return 0;
} 