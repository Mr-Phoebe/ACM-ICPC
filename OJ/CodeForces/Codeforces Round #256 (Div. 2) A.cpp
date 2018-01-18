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
int main()
{
	int s1=0;
    for (int i=0;i<3;i++)
	{
        int x;
        read(x);
        s1+=x;
    }
    int s2=0;
    for (int i=0;i<3;i++)
	{
        int x;
        read(x);
        s2+=x;
    }
    int n=0;
    cin>>n;
    n-=(s1+4)/5;
    n-=(s2+9)/10;
    if(n<0)
        puts("NO");
    else
        puts("YES");
    return 0;
} 