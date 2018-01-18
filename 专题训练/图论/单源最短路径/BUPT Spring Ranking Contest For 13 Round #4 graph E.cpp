#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

const long long INF = 1LL<<63-1;
const int N=1000010;

int n, m, ww;
long long d[N];
int cnt;

struct node
{
    int to;
    int next;//每次插边的时候是插在已插的边前面，所以已插的边是新边的next
    int weight;
}e[N];

int lastshow[N];
bool inqueue[N];
queue<int>q;

void insert(int a, int b, int w)
{
    e[++cnt].to = b;
    e[cnt].weight = w;
    e[cnt].next = lastshow[a];
    lastshow[a] = cnt;//lastshow记录一个点上次作为起点的边的序号，所以一条边的next是它的起点的lastshow值
}

bool spfa()
{
    q.push(1);
    while(!q.empty())
	{
        int x = q.front();
        q.pop();
        inqueue[x] = false;
        int id = lastshow[x];
        while(id != -1)
		{
            if(d[x] < INF && d[e[id].to] > e[id].weight + d[x])
			{
                d[e[id].to] = e[id].weight + d[x];
                if(!inqueue[e[id].to])
				{
                    inqueue[e[id].to] = true;
                    q.push(e[id].to);
                }
            }
            id = e[id].next;
        }
    }
    return false;
}

void init()
{
    int i;
    for(i = 1; i <= n; i ++)
	{
        lastshow[i] = -1;
        inqueue[i] = false;
    }
    for(i = 1; i <= n; ++ i)
        d[i]=INF;
    d[1]=0;
    cnt=0;
    while(!q.empty())
        q.pop();
}

int a[N], b[N], w[N];

int main()
{
    int T;
    int i;
    long long sum;
    cin >> T;
    while(T -- )
	{
        sum = 0;
        cnt = 0;
        scanf("%d %d", &n, &m);
        init();
        for(i = 1; i <= m; i ++)
		{
            scanf("%d %d %d", &a[i], &b[i], &w[i]);
            insert(a[i], b[i], w[i]);
        }
        spfa();
        for(i = 2; i <= n; i ++)
            sum += d[i];
        init();
        for(i = 1; i <= m; i ++)
            insert(b[i], a[i], w[i]);
        spfa();
        for(i = 2; i <= n; i ++)
            sum += d[i];
        printf("%lld\n",sum);
    }
    return 0;
}
