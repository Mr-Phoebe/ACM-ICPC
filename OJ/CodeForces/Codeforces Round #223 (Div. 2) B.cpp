#include<iostream>
#include<algorithm>

using namespace std;

int b[1000010],a[1000010];
int n=1,m;

int main()
{
	int i,j;
	cin>>m;
	for(i=0;i<m;i++)
		cin>>b[i];
	sort(b,b+m);
	int mid=m/2,top=m-1;
	a[mid]=b[top--];
	
	for(i=1,j=1;top+1;)
	{
		if(top+1&&b[top--]<a[mid+j-1])
		{
			a[mid+j]=b[top+1];
			j++;
			n++;
		}	
		if(top+1&&b[top--]<a[mid-i+1])
		{
			a[mid-i]=b[top+1];
			i++;
			n++;
		}
	}	
	cout<<n<<endl;
	for(i=0;i<=m;i++)
	{
		if(a[i]==0)
			continue;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
} 