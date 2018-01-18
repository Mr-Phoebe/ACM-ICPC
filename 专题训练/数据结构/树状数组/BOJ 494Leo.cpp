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
#define eps 1e-9
#define INF 0x3f3f3f3f
#define lowbit(x) (x)&(-x)

using namespace std;

template<class T>
inline bool read(T & n)
{
    T signal = 1,x =0;
    char ch = getchar();
    while((ch <'0' || ch >'9') && ch != EOF && ch != '-') ch = getchar();
    if(ch == EOF) return false;
    if(ch == '-') signal = -1,ch = getchar();
    while(ch >='0' && ch <= '9'){
        x *= 10;
        x += ch - '0';
        ch =getchar();
    }
    n = signal * x;
    return true;
}

template<class T>
inline void write(T n)
{
    if(n < 0) putchar('-'),n = -n;
    int len = 0,num[20];
    while(n){
        num[len++] = n % 10;
        n /= 10;
    }
    if(len == 0) num[len++] = 0;
    while(len--)
        putchar(num[len] + '0');
}

const int MAX = 200100;

int N;
int a[MAX];
int b[MAX];
int r[MAX];
int s[MAX];

void update(int x, int data)
{
    for(;x <= N; x += (x &(-x)))
        s[x] += data;
}
inline int getsum(int x)
{
    int ans =0;
    for(;x > 0; x -= (x &(-x)))
        ans += s[x];
    return ans;
}

int main(void)
{
    freopen("data.txt","r",stdin);
    while(read(N)){
        for(int i = 0 ; i < N; ++i){
            read(a[i]),read(b[i]);
            a[i]++;
        }
        memset(s,0,sizeof(int) * (N + 1));
        for(int i = N-1; i >= 0; i--){
            int lb = 1, ub = N;
            while(lb != ub){
                int mid = (ub + lb) / 2;
                //printf("%d %d %d\n",i,mid,getsum(mid));
                if(mid - getsum(mid) >= a[i]) ub = mid;
                else lb = mid + 1;
            }
            r[lb] = b[i];
            update(lb,1);
        }
        for(int i = 1; i < N; ++i)
            write(r[i]),putchar(' ');
        write(r[N]), putchar('\n');
    }
    return 0;
}

