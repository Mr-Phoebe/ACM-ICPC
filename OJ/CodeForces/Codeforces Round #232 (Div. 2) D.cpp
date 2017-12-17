#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
int T,n;
struct frac
{
    LL a,b;
    frac operator+(frac rhs)
	{
        //(ac+bd)/b*c
        frac ans=(frac){a*rhs.b+b*rhs.a,b*rhs.b};
        LL g=__gcd(ans.a,ans.b);
        ans.a/=g;ans.b/=g;
        return ans;
    }
	frac operator-(frac rhs)
	{
        frac ans=(frac){a*rhs.b-b*rhs.a,b*rhs.b};
        LL g=__gcd(ans.a,ans.b);
        ans.a/=g;ans.b/=g;
        return ans;
    }
}ans;                  //construct a struct to simplify the plus and subtract
bool is(int x)         //isprime
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
int find(int x,int step)
{
    while(!is(x))
		x+=step;
    return x;
}
int main()
{
    scanf("%d",&T);
    while(T--)
	{
        scanf("%d",&n);
        int p=find(n,-1),p2=find(n+1,1);    //find the prime 
        long long a =p2-2, b =2LL*p2;
		a = a * p - 2 * (p2 - n - 1);
		b = b * p;
		long long d =__gcd(a, b); a /= d; b /= d;
		cout << a << "/" << b << endl;
    }
}