#include<iostream>

using namespace std;

int main()
{
	long int i,j,k,x,y,x1,y1,x2,y2,s=0,n;
	bool a[240][240];
	cin>>x>>y>>n;
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			a[i][j]=false;
	for(i=0;i<n;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		for(k=x1-1;k<x2;k++)
			for(j=y1-1;j<y2;j++)
				a[k][j]=true;
	}	
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			if(a[i][j])
				s++;
	cout<<s<<endl;
	return 0;
}