#include<iostream>

using namespace std;

int main()
{
	int n,k,p,m;
	cin>>n>>k;
	p=n/2;
	if(k==0)
	{
		if(n==1) cout<<"1"<<endl;
		else cout<<"-1"<<endl;
		return 0;
	}
	else
	{
		if(p!=0) 
			m=k/p;
		else
			m=0;
		if(m==0)
		{
			cout<<"-1"<<endl;
			return 0;
		}	
	}
	bool odd=(n&1);
	int first=m-p*m+k,second=2*first;
	for(int i=1;i<=p;i++)
	{
		int z=1,temp=first+1;
		cout<<first++<<" "<<second<<" ";
		while(first%m!=0||first==second)
			first++;
		if(first-temp==m-1)
		{
			first=second+1;
			while(first%m!=0)
				first++;
		}	
		while(first+z*m==second)
			z++;
		second=first+z*m;
		if(second%first==0)
			second+=m;
	}
	if(odd)
		cout<<first<<endl;
	else
		cout<<endl;
	return 0;
	
} 