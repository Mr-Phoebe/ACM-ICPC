#include<iostream>
#include<cmath>

using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int p,n,i,j,temp;
	float max=0,min=100000000.0;
	int fz1,fm1,fz2,fm2;
	cin>>p>>n;
	for(i=1;i<=n;i++)
	{
		for(j=(int)floor(i/sqrt(p))-3;j<=(int)floor(i/sqrt(p))+3;j++)
		{
			if(j<=0||j>n||i==j)
				continue;
			if(sqrt(p)-(float)i/(float)j>=1e-7&&(float)i/(float)j-max>=1e-7)
			{
				fz1=i;fm1=j;max=(float)i/(float)j;
			}
			if(sqrt(p)-(float)i/(float)j<=1e-7&&(float)i/(float)j-min<=1e-7)
			{
				fz2=i;fm2=j;min=(float)i/(float)j;
			}
		}
	}
	if((temp=gcd(fz1,fm1))!=1)
	{
		fz1/=temp;
		fm1/=temp;
	}
	if((temp=gcd(fz2,fm2))!=1)
	{
		fz2/=temp;
		fm2/=temp;
	}
	cout<<fz1<<"/"<<fm1<<" "<<fz2<<"/"<<fm2<<endl;
	return 0;
}

