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

int HASH[10]={1,1,2,6,24,120,720,5040,40320,362880};
int op[10];
bool vis[400010];

struct Node
{
    int num[6];
    int hash,step;
}s,t;

void fr(int *a)
{
	int tt=a[5];
	a[5]=a[1];
	a[1]=a[4];
	a[4]=a[0];
	a[0]=tt;
}

void ba(int *a)
{
	int tt=a[0];
	a[0]=a[4];
	a[4]=a[1];
	a[1]=a[5];
	a[5]=tt;
}

void le(int *a)
{
	int tt=a[0];
	a[0]=a[3];
	a[3]=a[1];
	a[1]=a[2];
	a[2]=tt;
}

void ri(int *a)
{
	int tt=a[2];
	a[2]=a[1];
	a[1]=a[3];
	a[3]=a[0];
	a[0]=tt;
}

void change(int x,int *a)
{
	switch(x)
	{
		case 1:
			fr(a);
			break;
		case 2:
			ba(a);
			break;
		case 3:
			le(a);
			break;
		case 4:
			ri(a);
			break;
	}
}

int cantos(Node tmp)
{
    int a[7],k=0;
    for(int i=0;i<6;i++)
            a[k++]=tmp.num[i];
    int res=0;
    for(int i=0;i<6;i++)
    {
        int k=0;
        for(int j=0;j<i;j++)
            if(a[j]>a[i])
                k++;
        res+=HASH[i]*k;
    }
    return res;
}

int bfs()
{
	queue<Node> q;
	Node temp=s,next;
	vis[temp.hash]=true;
	while(!q.empty())
        q.pop();
	q.push(temp);
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		for(int i=1;i<=4;i++)
		{
			next=temp;
			change(i,next.num);
			next.hash=cantos(next);
			if(vis[next.hash])
				continue;
			vis[next.hash]=true;
			next.step=temp.step+1;
			if(next.step>1000)
                return -1;
            q.push(next);
			if(next.hash==t.hash)
				return next.step;
		}
	}
	return -1;
}


int main()
{
	while(read(t.num[0])&&read(t.num[1])&&read(t.num[2])&&read(t.num[3])&&read(t.num[4])&&read(t.num[5]))
	{
		CLR(vis,0);
		bool flag=true;
		t.hash=cantos(t);
		for(int i=0;i<6;i+=2)
			op[t.num[i]]=t.num[i+1],op[t.num[i+1]]=t.num[i];
		for(int i=0;i<6;i+=2)
		{
			read(s.num[i]);read(s.num[i+1]);
			if(op[s.num[i]]!=s.num[i+1])
				flag=false;
		}
		s.hash=cantos(s);
		s.step=0;
		if(!flag)
		{
			puts("-1");
			continue;
		}
		if(s.hash==t.hash)
		{
			puts("0");
			continue;
		}
		int step=bfs();
        cout<<step<<endl;
	}
	return 0;
}
