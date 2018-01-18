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
#define pb(x) push_back(x)
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

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

const int MAXN = 305;
int n,m,v[MAXN],mat[MAXN][MAXN],dis[MAXN];
bool vis[MAXN];
int res,s;

int Stoer_Wagner(int n)
{
    int i, j;
    int res = INF;
    for (i = 0; i < n; i++)
        v[i] = i+1;//��ʼ����i��������i    !!!!!   ע���±�
    while (n > 1)
    {
        int maxp = 1,prev = 0;
        for (i = 1; i < n; i++) //��ʼ������Ȧ���ϵĸ��С,���ҳ�������Ķ���
        {
            dis[v[i]] = mat[v[0]][v[i]];
            vis[v[i]] = 0;
            if (dis[v[i]] > dis[v[maxp]])
                maxp = i;
        }
        vis[v[0]] = true;
        for (i = 1; i < n; i++)
        {
            vis[v[maxp]] = true;
            if (i == n - 1)  //ֻʣ���һ��û���뼯�ϵĵ㣬������С��
            {
                res = min(res,dis[v[maxp]]);
                for (j = 0; j < n; j++)  //�ϲ����һ�����Լ��Ƴ����ļ����еĵ�
                {
                    mat[v[prev]][v[j]] += mat[v[j]][v[maxp]];
                    mat[v[j]][v[prev]] = mat[v[prev]][v[j]];
                }
                v[maxp] = v[--n];//��maxp���ڵ�ȥ������n���ڵ��ɵ�maxp��
            }
            else
            {
                prev = maxp;
                maxp = -1;
                for (j = 1; j < n; j++)
                    if (!vis[v[j]])  //���ϴ����maxp���뼯�ϣ��ϲ��������ڵıߵ��
                    {
                        dis[v[j]] += mat[v[prev]][v[j]];
                        if (maxp == -1 || dis[v[maxp]] < dis[v[j]])
                            maxp = j;
                    }
            }
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt","r",stdin);
    while (read(n)&&read(m),read(s)&&(n+m+s))
    {
        CLR(mat,0);
        int x,y,z;
        while (m--)
        {
            read(x),read(y),read(z);
            mat[x][y] += z;
            mat[y][x] += z;
        }
        printf("%d\n",Stoer_Wagner(n));
    }
}
