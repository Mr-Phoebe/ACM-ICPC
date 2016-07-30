#include <iostream>
 
using namespace std;

typedef long long ll;

int main()
{
//    freopen("in.txt", "r", stdin);
	int n,dir;
	ll sum,ans;
    cin>>n; 
    ans=sum=0;
    for(int i=1;i<=n;i++)
	{
		cin>>dir;
		if(dir)
			sum+=dir;
		else
			ans+=sum;
   }
   printf("%I64d\n",ans);
   return 0;
}