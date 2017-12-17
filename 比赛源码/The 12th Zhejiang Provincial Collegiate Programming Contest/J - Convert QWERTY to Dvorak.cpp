//      whn6325689
//		Mr.Phoebe
//		http://blog.csdn.net/u013007900
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
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define speed std::ios::sync_with_stdio(false);
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

map<char,char> dir;

void init()
{
    dir['_']='{';dir['+']='}';
    dir['-']='[';dir['=']=']';
    dir['Q']='"';dir['q']='\'';
    dir['W']='<';dir['w']=',';
    dir['E']='>';dir['e']='.';
    dir['R']='P';dir['r']='p';
    dir['T']='Y';dir['t']='y';
    dir['Y']='F';dir['y']='f';
    dir['U']='G';dir['u']='g';
    dir['I']='C';dir['i']='c';
    dir['O']='R';dir['o']='r';
    dir['P']='L';dir['p']='l';
    dir['{']='?';dir['[']='/';
    dir['}']='+';dir[']']='=';
    dir['S']='O';dir['s']='o';
    dir['D']='E';dir['d']='e';
    dir['F']='U';dir['f']='u';
    dir['G']='I';dir['g']='i';
    dir['H']='D';dir['h']='d';
    dir['J']='H';dir['j']='h';
    dir['K']='T';dir['k']='t';
    dir['L']='N';dir['l']='n';
    dir[':']='S';dir[';']='s';
    dir['"']='_';dir['\'']='-';
    dir['Z']=':';dir['z']=';';
    dir['X']='Q';dir['x']='q';
    dir['C']='J';dir['c']='j';
    dir['V']='K';dir['v']='k';
    dir['B']='X';dir['b']='x';
    dir['N']='B';dir['n']='b';
    dir['<']='W';dir[',']='w';
    dir['>']='V';dir['.']='v';
    dir['?']='Z';dir['//']='z';
}

int main()
{
//    freopen("data.txt","r",stdin);
    init();
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(dir[ch]!=0)
            putchar(dir[ch]);
        else
            putchar(ch);
    }
    return 0;
}


