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

int main()
{

    char a[8][10]= {"vaporeon","jolteon","flareon","espeon","umbreon","leafeon","glaceon","sylveon"};
    char b[10];
    int c[8]= {8,7,7,6,7,7,7,7};
    int n;
    while(read(n))
    {
        int cou=0;
        gets(b);
        for(int i=0; i<n; i++)
            if(b[i]!='.')
                cou++;
        if(!cou)
        {
            if(n==8)
                printf("vaporeon\n");
            if(n==7)
                printf("jolteon\n");
            if(n==6)
                printf("espeon\n");
            continue;
        }
        int cou1=0;
        for(int i=0; i<8; i++)
        {
            cou1=0;
            for(int j=0; j<n; j++)
                if(a[i][j]==b[j]&&b[j]!='.')
                    cou1++;

            if(cou==cou1&&c[i]==n)
            {
                printf("%s\n",a[i]);
                break;
            }
        }
    }
    return 0;
}
