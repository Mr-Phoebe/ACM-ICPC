#include<iostream> 

using namespace std;

int n,p,k;


int main()
{
	cin>>n>>p>>k;
	if(p-k>1)
	{
		cout<<"<< ";
		for(int i=p-k;i<p;i++)
			cout<<i<<" ";
	}
	else
	{
		for(int i=1;i<p;i++)
			cout<<i<<" ";
	}	
	cout<<"("<<p<<") ";
	if(p+k<n)
	{
		for(int i=p+1;i<=p+k;i++)
			cout<<i<<" ";
		cout<<">>"<<endl;
	}
	else
	{
		for(int i=p+1;i<=n;i++)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}