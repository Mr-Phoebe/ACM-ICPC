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
	#define CLR(x,y) memset(x,y,sizeof(x))
	#define mp(x,y) make_pair(x,y)
	#define eps 1e-9
	#define INF 0x3f3f3f3f
	
	using namespace std;
	
	typedef long long ll;
	typedef long double ld;
	typedef pair<ll, ll> pll;
	typedef complex<ld> point;
	typedef pair<int, int> pii;
	typedef pair<pii, int> piii;
	
	template<class T>
	inline bool read(T &n)
	{
	    T x = 0, tmp = 1; char c = getchar();
	    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
	    if(c == EOF) return false;
	    if(c == '-') c = getchar(), tmp = -1;
	    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
	    n = x*tmp;
	    return true;
	}
	template <class T>
	inline void write(T n)
	{
	    if(n < 0)
	    {
	        putchar('-');
	        n = -n;
	    }
	    int len = 0,data[20];
	    while(n)
	    {
	        data[len++] = n%10;
	        n /= 10;
	    }
	    if(!len) data[len++] = 0;
	    while(len--) putchar(data[len]+48);
	}
	//-----------------------------------
	
	int num[105];
	
	int gcd(int a, int b)
	{
		return b ? gcd(b, a % b) : a;
	}
	
	int main(void)
	{
		int n, temp=0,maxx=-1;
		read(n);
		for(int i=0; i<n; i++)
		{
			read(num[i]);
			maxx=max(maxx,num[i]);
		}
		temp=num[0];
		for (int i=1; i<n; i++)
				temp=gcd(temp,num[i]);
		int movetimes=maxx/temp-n;
		puts(movetimes & 1 ? "Alice" : "Bob");
		return 0;
	}