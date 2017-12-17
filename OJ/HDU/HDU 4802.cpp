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


double finds(char *str,double &sum,double temp)
{
	switch(str[0])
	{
		case 'A':
			if(str[1]=='-')
				return 3.7;
			else
				return 4.0;
		case 'B':
			if(str[1]=='+')
				return 3.3;
			else if(str[1]=='-')
				return 2.7;
			else
				return 3.0;
		case 'C':
			if(str[1]=='+')
				return 2.3;
			else if(str[1]=='-')
				return 1.7;
			else
				return 2.0;
		case 'D':
			if(str[1]=='-')
				return 1.0;
			else
				return 1.3;
		case 'F':
			return 0.0;
		default:
			sum-=temp;
			return 0.0;
	}
}

int main()
{
	int n;
	while(read(n))
	{
		char str[10];
		double sum=0;
		double up=0;
		for(int i=0;i<n;i++)
		{
			gets(str);
			double temp=0;
			int j=0;
			while(isdigit(str[j]))
			{
				temp*=10;
				temp+=str[j++]-'0';
			}
			sum+=temp;
			double s=finds(str+j+1,sum,temp);
			up+=s*temp;
		}
		if(fabs(sum)<eps)
			puts("0.00");
		else
			printf("%.2f\n",up/sum);
	}
	return 0;
}