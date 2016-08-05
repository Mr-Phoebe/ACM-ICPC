#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <climits>
#define MAXN 100050
#define INF 1000000000
using namespace std;
const int N = 1 << 20;
const int M = 1 << 20;
int n;
int edge_cnt, first_edge[N], next_edge[M], to[M], capacity[M], curr_edge[N];
int source, target, flow, pre[N], level[N], queue[N], sign;

void addEdge(int u, int v, int w) {
    to[edge_cnt] = v;
    capacity[edge_cnt] = w;
    next_edge[edge_cnt] = first_edge[u];
    first_edge[u] = edge_cnt++;
}

bool bfs(int s, int t) {
    std::fill(level, level + n, -1);
    sign = t;
    level[t] = 0;
    int head = 0, tail = 0;
    queue[tail++] = t;
    while(head != tail && level[s] == -1) {
        int u = queue[head++];
        for(int iter = first_edge[u]; iter != -1; iter = next_edge[iter]) {
            if(capacity[iter ^ 1] > 0 && level[to[iter]] == -1) {
                level[to[iter]] = level[u] + 1;
                queue[tail++] = to[iter];
            }
        }
    }
    return level[s] != -1;
}

void push() {
    int delta = INT_MAX, u, p;
    for(u = target; u != source; u = to[p ^ 1]) {
        p = pre[u];
        delta = std::min(delta, capacity[p]);
    }
    for(u = target; u != source; u = to[p ^ 1]) {
        p = pre[u];
        capacity[p]  -= delta;
        if(!capacity[p]) {
            sign = to[p ^ 1];
        }
        capacity[p ^ 1] += delta;
    }
    flow += delta;
}

void dfs(int u) {
    if(u == target) {
        push();
    } else {
        for(int & iter = curr_edge[u]; iter != -1; iter = next_edge[iter]) {
            if(capacity[iter] > 0 && level[u] == level[to[iter]] + 1) {
                pre[to[iter]] = iter;
                dfs(to[iter]);
                if(level[sign] > level[u]) {
                    return;
                }
                sign = target;
            }
        }
        level[u] = -1;
    }
}
int u[MAXN],v[MAXN],val[MAXN];
int cnt=0;
void dinic(int s, int t, int node_cnt) {
    source = s;
    target = t;
    n = node_cnt;
    std::fill(first_edge, first_edge + n, -1);
    edge_cnt = 0;

    //construct graph...
    for(int i=0;i<cnt;++i){
    	addEdge(u[i],v[i],val[i]);
    	addEdge(v[i],u[i],0);
    }


    flow = 0;
    while(bfs(source, target)) {
        for(int i = 0; i < n; ++i) {
            curr_edge[i] = first_edge[i];
        }
        dfs(source);
    }
}

char s[MAXN];
int nc;
int a[20],b[20];
int w[105][105];
bool bo[1005];

int solve(int sta){
	int src=0;
	int tc=1;
	int cid=nc+2;
	cnt=0;
	int sum=0;
	for(int i=1;i<=nc;++i){
		if(((1<<s[i])&sta)==0)continue;
		for(int j=i+1;j<=nc;++j){
			if(((1<<s[j])&sta)==0)continue;
			sum+=w[i][j]+w[j][i];
			u[cnt]=src,v[cnt]=cid,val[cnt++]=w[i][j]+w[j][i];
			u[cnt]=cid,v[cnt]=i+1,val[cnt++]=INF;
			u[cnt]=cid,v[cnt]=j+1,val[cnt++]=INF;
			cid++;
		}
		u[cnt]=i+1,v[cnt]=tc,val[cnt++]=a[i];
	}
	dinic(src,tc,cid+1);
	for(int i=0;i<10;++i){
		if(((1<<i)&sta))
			sum-=(b[i]-a[i]);
	}


//	if(sta==34){
//		printf("%s\n",s+1);
//		for(int i=0;i<cnt;++i)
//			printf("%d %d %d\n",u[i],v[i],val[i]);
//		printf("::%d %d\n",flow,sum);
//	}
	return sum-flow;
}
int main() {
	int tt;
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&nc);
		scanf("%s",s+1);
		for(int i=1;i<=nc;++i)
			s[i]-='0';
		for(int i=0;i<10;++i)
			scanf("%d%d",&a[i],&b[i]);
		for(int i=1;i<=nc;++i)
			for(int j=1;j<=nc;++j)
				scanf("%d",&w[i][j]);
		int ans=0;
		for(int i=0;i<(1<<10);++i){
			int tmp=solve(i);
			ans=max(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}
