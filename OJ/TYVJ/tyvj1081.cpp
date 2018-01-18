#include<iostream>
#include<cmath>

using namespace std;

const int maxn=2000*2000+10;
double mi=1111111111;
double x[2010],y[2010];
int ax,ay;

double pow(double x)
{
	return x*x;
}

double dist(int i,int j)
{
	return sqrt(pow(x[i]-x[j])+pow(y[i]-y[j]));
}

int main()
{
	int n;
//	freopen("data.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			double temp=dist(i,j);
			if(temp<mi)
			{
				mi=temp;
				ax=i;ay=j;
			}
		}
	cout<<ax<<" "<<ay<<endl;
	return 0;
} 