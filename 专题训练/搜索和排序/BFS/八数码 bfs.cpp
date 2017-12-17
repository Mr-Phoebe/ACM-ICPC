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
//-----------------------------------------

typedef vector<int> vec;
typedef vector<vec> mat;

struct Node
{
	int b[3][3];
	int x,y;
	int hash;
}s,t;

bool vis[400010];
int pre[400010];
char ans[400010];
int HASH[10]={1,1,2,6,24,120,720,5040,40320,362880};
int dir[4][2]={1,0,0,1,-1,0,0,-1};
char move[5]="drul";

inline bool in(int x,int y)
{
	return ((x>=0)&&(y>=0)&&(x<=2)&&(y<=2));
}

int cantos(Node tmp)
{
    int a[10],k=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[k++]=tmp.b[i][j];
    int res=0;
    for(int i=0;i<9;i++)
	{
		int k=0;
        for(int j=0;j<i;j++)
            if(a[j]>a[i])
                k++;
        res+=HASH[i]*k;
    }
    return res;
}

bool isok(Node tmp)
{
    int a[10],k=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[k++]=tmp.b[i][j];
    int sum=0;
    for(int i=0;i<9;i++)
        for(int j=i+1;j<9;j++)
            if(a[j]!=9&&a[i]!=9&&a[i]>a[j])
                sum++;
    return !(sum&1);
}

void bfs()
{
    queue<Node> q;
    Node temp=s;
    vis[temp.hash]=true;
    q.push(temp);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        int hh=temp.hash;//Ô­¿µÍÐ
        for(int i=0;i<4;i++)
        {
            t=temp;
            t.x+=dir[i][0];
            t.y+=dir[i][1];
            if(!in(t.x,t.y))
                continue;
            t.b[temp.x][temp.y]=temp.b[t.x][t.y];
            t.b[t.x][t.y]=9;
            int th=t.hash=cantos(t);
            if(vis[th])
                continue;
            vis[th]=true;
            q.push(t);
/*            for(int ik=0;ik<3;ik++)
            {
                for(int j=0;j<3;j++)
                    cout<<t.b[ik][j]<<" ";cout<<endl;
            }cout<<endl;
            system("pause");*/
            pre[th]=hh;
            ans[th]=move[i];
            if(th==0)
                return;
        }
    }
}

void print(int now)
{
    if(now!=s.hash)
        print(pre[now]);
    else
        return;
   printf("%c",ans[now]);
}

int main()
{
	char str[100];
	while(gets(str))
	{
		memset(vis,0,sizeof(vis));
        memset(pre,-1,sizeof(pre));
		for(int i=0,k=0;i<3;i++)
            for(int j=0;j<3;j++)
			{
                if((str[k]<='9'&&str[k]>='0')||str[k]=='x')
				{
                    if(str[k]=='x')
                        s.b[i][j]=9,s.x=i,s.y=j;
                    else
                        s.b[i][j]=str[k]-'0';
                }
                else
                    j--;
                k++;
            }
     	if(!isok(s))
		{
            printf("unsolvable\n");
            continue;
        }
        s.hash=cantos(s);
        if(s.hash==0)
		{
            puts("");
            continue;
        }
        bfs();
        print(0);
        putchar('\n');
	}
	return 0;
}



