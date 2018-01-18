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
const int MAXN=100;

int dir[8][2]={-1,-2,1,-2,2,1,2,-1,-2,1,-2,-1,-1,2,1,2};
bool vis[8][8]; 
struct Node
{
	int x,y,idx;
	int f,g,h;	
	Node(){}
	bool operator < (const Node a) const
	{
		return f>a.f;
	}
}s,t,pre[MAXN];
priority_queue<Node > Q;
int tot=1;

inline bool in(int x,int y)
{
	return (x>=0 && x<8 && y>=0 && y<8);
}

int getH(Node a)
{
	return (abs(a.x-t.x)+abs(a.y-t.y))/sqrt(5);	
}


void print(Node a)
{
	if(a.x==s.x&& a.y==s.y)
		return;
	print(pre[a.idx]);
	printf("%c%d ",a.x+'A',a.y);
}

void bfs()
{
	s.g=0;s.h=getH(s);s.f=s.g+s.f;s.idx=tot++;
	vis[s.x][s.y]=true;
	Q.push(s);
	while(!Q.empty())
	{
		Node temp=Q.top();Q.pop();
		cout<<temp.x<<" "<<temp.y<<endl;
		if(temp.x==t.x && temp.y==t.y)
		{
			print(pre[temp.idx]);
			printf("%c%d\n",temp.x+'A',temp.y) 
			return;
		}
		for(int i=0;i<8;i++)
		{
			int xx=temp.x+dir[i][0];
			int yy=temp.y+dir[i][1];
			if(!in(xx,yy) || vis[xx][yy])
				continue;
			vis[xx][yy]=true;
			Node next;
			next.x=xx,next.y=yy,next.h=getH(next);
			next.g=temp.g+1;next.f=next.g+next.h;
			next.idx=tot++;pre[next.idx]=temp;
			Q.push(next);
		}
	}
}

int main()
{
	char str[20];
	gets(str);
	int i=0,len=strlen(str);
	while(!isdigit(str[i]) && i<len)	i++;
	s.x=str[i-1]-'A';s.y=str[i++]-'0';
	while(!isdigit(str[i]) && i<len)	i++;
	t.x=str[i-1]-'A';t.y=str[i++]-'0';	
	bfs();
	return 0;
}