#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int left=0,mid=0,right=0;
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=6;i++)
	{
		if(fabs(a-i)>fabs(b-i))
			right++;
		else if(fabs(a-i)==fabs(b-i))
			mid++;
		else
	 		left++;
	}
	cout<<left<<" "<<mid<<" "<<right<<endl;
} 