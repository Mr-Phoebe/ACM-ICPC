#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

long long sum=0;
string str;

int main()
{
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		switch(str.at(i))
		{
			case'1':
				sum+=a;
				break;
			case'2':
				sum+=b;
				break;
			case'3':
				sum+=c;
				break;
			case'4':
				sum+=d;
				break;
		}
	}
	cout<<sum<<endl;
}