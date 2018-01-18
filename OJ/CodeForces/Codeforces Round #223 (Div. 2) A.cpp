#include<iostream> 
#include<vector>

using namespace std;

vector<int> num;

long long Se=0,Di=0;

int main()
{
	int n;
	bool turn=true;
	cin>>n;
	for(int i=0;i<n;i++)
	{	
		int temp;
		cin>>temp;
		num.push_back(temp);
	}
	while(!num.empty())
	{
		int first=*num.begin(),last=*(num.end()-1);
		if(turn)
		{
			turn=!turn;
			if(first>=last)
			{
				Se+=first;
				num.erase(num.begin());
			}
			else
			{
				Se+=last;
					num.erase(num.end()-1);
			}
		}
		else
		{
			turn=!turn;
			if(first>=last)
			{
				Di+=first;
				num.erase(num.begin());
			}
			else
			{
				Di+=last;
				num.erase(num.end()-1);
			}
		}
	}
	cout<<Se<<" "<<Di<<endl;
} 