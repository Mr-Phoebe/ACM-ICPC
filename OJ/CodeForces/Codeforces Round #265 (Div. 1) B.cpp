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
    T x = 0, tmp = 1;
    char c = getchar();
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


int p[8][3];

long long dist(int i,int j)
{
    long long dx=(long long)(p[i][0]-p[j][0])*(p[i][0]-p[j][0]);
    long long dy=(long long)(p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
    long long dz=(long long)(p[i][2]-p[j][2])*(p[i][2]-p[j][2]);
    return dx+dy+dz;
}

int check()
{
    map<long long,int>M;
    map<long long,int>::iterator it;
    int i,j;
    for(i=0; i<8; i++)
        for(j=i+1; j<8; j++)
            M[dist(i,j)]++;
    if(M.size()==3)
    {
        it=M.begin();
        long long a=(it++)->first;
        long long b=(it++)->first;
        long long c=(it)->first;
        if(b==2*a&&c==3*a)
            return 1;
    }
    return 0;
}
int main()
{
    //freopen("b.txt","r",stdin);
    int i,j,i1,i2,i3,i4,i5,i6,i7;
    for(i=0; i<8; i++)
        for(j=0; j<3; j++)
            read(p[i][j]);
    int flag=0;
    for(i1=0; i1<6; i1++,next_permutation(p[1],p[1]+3))
        for(i2=0; i2<6; i2++,next_permutation(p[2],p[2]+3))
            for(i3=0; i3<6; i3++,next_permutation(p[3],p[3]+3))
                for(i4=0; i4<6; i4++,next_permutation(p[4],p[4]+3))
                    for(i5=0; i5<6; i5++,next_permutation(p[5],p[5]+3))
                        for(i6=0; i6<6; i6++,next_permutation(p[6],p[6]+3))
                            for(i7=0; i7<6; i7++,next_permutation(p[7],p[7]+3))
                                if(check())
                                    goto ok;
    puts("NO");
    return 0;
ok:
    printf("YES\n");
    for(i=0; i<8; i++)
        for(j=0; j<3; j++)
            printf("%d%c",p[i][j],j==2?'\n':' ');
    return 0;
}
