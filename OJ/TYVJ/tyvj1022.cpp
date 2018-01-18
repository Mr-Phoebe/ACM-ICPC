#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	long int i,k=0,n,x;
	int a[1001];
	cin>>n;
	do{
		k++;
		a[k]=fabs(n%-2);
		if(n<0)
			n--;
		n/=-2;
	}while(n!=0);
	for(i=k;i>=1;i--)
		cout<<a[i];
	cout<<endl;

	return 0;
}