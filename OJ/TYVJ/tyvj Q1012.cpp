#include<iostream>
#include<cmath>

using namespace std;

int is_prime(int n)
{
	int i;
	long int b=(int)(sqrt(n)+0.5);
	for(i=2;i<=b;i++)
		if(n%i==0)
			return 0;
	return 1;
}

int main()
{
	long double n;
	int result=1;
	cin>>n;

	for(int j=3;j<=(int)(sqrt(n)+0.5);j+=2)
	{
		if(is_prime(j))
			{result++;}
		
	} 	

	
	cout<<result<<endl;
} 
