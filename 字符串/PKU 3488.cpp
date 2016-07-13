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
char date[1000][1000];
string str;

int main ()
{
    int num;
    int i,j;
    int len;
    while(cin>>num)
    {
        for(i=0;i<num;i++)
            cin>>date[i];
        len=strlen(date[0]);
        int flag=0;
        for(j=0;j<len;j++)
        {

            for(i=0;i<num;i++)
            {
                if(date[i][j]!='_')
                    flag=1;
                if(flag==1)
                    str+=date[i][j];
            }
        }
        int pos=str.length();
        for(i=pos-1;i>=0;i--)
        {
            if(str[i]=='_')
            {
                printf(" ");
                str[i]=' ';
                continue;
            }
            else if(str[i]=='\\')
            {
                cout<<endl;
                continue;
            }
            else
                cout<<str[i];
        }
        cout<<endl<<endl;
        str.clear();
    }
    return 0;
}
