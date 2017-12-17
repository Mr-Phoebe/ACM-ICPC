#include<iostream>
#define MID(x,y) (x+((y-x)>>1))
using namespace std;

typedef long long ll;

ll v[3],cnt[3];

bool check(ll m)
{
	return cnt[0] <= m-(m/v[0]) && cnt[1] <= m-(m/v[1]) && cnt[0]+cnt[1] <= m-(m/(v[0]*v[1]));
}


int main()
{
	cin>>cnt[0]>>cnt[1]>>v[0]>>v[1];
	ll l=0,r=1e18;
	while(l<r)
	{
		ll m=MID(l,r);
		if(check(m))
			r=m;
		else
			l=m+1;
	}
	cout<<r<<endl;
	return 0;
}
