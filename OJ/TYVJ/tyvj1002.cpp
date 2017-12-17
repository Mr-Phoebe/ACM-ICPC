#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdio>

using namespace std;

struct student
{
	int mask;
	int maskclass;
	int number;
	char name[20];
	char west;
	char cadre;
	int scholarship;
}a[100];


int main()
{
	int n,i,max,sum,maxnum;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i].name>>a[i].mask>>a[i].maskclass>>a[i].cadre>>a[i].west>>a[i].number;
		a[i].scholarship=0;
		if(a[i].mask>80&&a[i].number>=1)
			a[i].scholarship+=8000;
		if(a[i].mask>85&&a[i].maskclass>80)
			a[i].scholarship+=4000;
		if(a[i].mask>90)
			a[i].scholarship+=2000;
		if(a[i].mask>85&&a[i].west=='Y')
			a[i].scholarship+=1000;
		if(a[i].maskclass>80&&a[i].cadre=='Y')
			a[i].scholarship+=850;
	}
	max=a[0].scholarship;
	sum=a[0].scholarship;
	for(i=1;i<n;i++)
	{
		sum+=a[i].scholarship;
		if(a[i].scholarship>max)
		{max=a[i].scholarship;maxnum=i;}
	}
	cout<<a[maxnum].name<<endl<<a[maxnum].scholarship<<endl;
	cout<<sum<<endl;

    
	return 0;
}
