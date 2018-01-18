#include<iostream>

using namespace std;

int main()
{
	int n,m,k;
	int a;
	int time=0;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		switch(a)
		{
			case 1:
				if(!m)
					time++;
				else
					m--;
				break;
			case 2:
		 		if(!k)
		 		{
		 			if(!m)
			 			time++;
		 			else
		 				m--;
		 		}
		 		else
		 			k--;
	 			break;
			}
	}
	cout<<time<<endl;
	return 0;
} 