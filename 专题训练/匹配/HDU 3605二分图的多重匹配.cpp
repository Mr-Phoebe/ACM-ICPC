/*
ֱ�ӽ�������ͼģ�ͣ����������㷨....
�������㷨���Խ������ƥ��.... ע�ⲻ�ܰѿ���ƥ�����ĵ�ָ�Ȼ���������Ķ���ƥ�������������϶���ҵ�....
�������ƥ����Ǽ�¼һ�¶���ƥ��ĵ�(���Y����)�Ѿ�ƥ����Pi���㡣���Pi<Ki��ô��ֱ�����ˣ�
����Ļ���������Yi�Ѿ�ƥ���ÿһ���㲢��YiȾɫ...
��ΪYi��һ�ξ���ҪȾɫ�ˣ�����Y���������10��������ÿ��������·����������10... �����ͺܿ���...
*/
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

const int N=100005;
const int M=11;

int y[M][N];
int tem[M],num[M],chk[M];
int G[N][M];

int n,m;
bool dfs(int u)
{
	for(int i=0;i<m;i++)
		if(G[u][i] && !chk[i])
		{
			chk[i]=1;
			if(tem[i]<num[i])
			{
				y[i][tem[i]++]=u;return 1;
			}
			else
			{
				for(int j=0;j<tem[i];j++)
					if(dfs(y[i][j]))
					{
						y[i][j]=u;
						return 1;
					}
			}
		}
	return 0;
}

int main()
{
	while(read(n)&&read(m))
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				read(G[i][j]);
		for(int i=0;i<m;i++)
		{
			read(num[i]);
			tem[i]=0;
		}
		int flag=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				chk[j]=0;
			if(!dfs(i))
			{
				flag=0;
				break;
			}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}
