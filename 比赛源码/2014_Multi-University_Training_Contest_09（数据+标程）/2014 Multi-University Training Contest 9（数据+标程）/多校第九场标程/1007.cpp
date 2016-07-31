//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 550
#define M 1109  

int ecnt;
struct Edge{  
	int u , v;  
	int cost;  
}E[N * 2 + M];  
void addedge(int u,int to, int cost) {
	E[ecnt++] = (Edge){u, to, cost};
}

const int inf=(1)<<30;  
int pre[N],ID[N],vis[N];  
int In[N];  
int Directed_MST(int root,int NV,int NE) {  
	int ret = 0;  
	while(true) {  
		for(int i=0;i<NV;i++) In[i] = inf;  
		for(int i=0;i<NE;i++){  
			int u = E[i].u;  
			int v = E[i].v;  
			if(E[i].cost < In[v] && u != v) {  
				pre[v] = u;  
				In[v] = E[i].cost;  
			}  
		}  
		for(int i=0;i<NV;i++) {  
			if(i == root) continue;  
			if(In[i] == inf)    return -1;//除了跟以外有点没有入边,则根无法到达它  
		}  
		//2.找环  
		int cntnode = 0;  
		memset(ID,-1,sizeof(ID));  
		memset(vis,-1,sizeof(vis));  
		In[root] = 0;  
		for(int i=0;i<NV;i++) {//标记每个环  
			ret += In[i];  
			int v = i;  
			while(vis[v] != i && ID[v] == -1 && v != root) {  
				vis[v] = i;  
				v = pre[v];  
			}  
			if(v != root && ID[v] == -1) {  
				for(int u = pre[v] ; u != v ; u = pre[u]) {  
					ID[u] = cntnode;  
				}  
				ID[v] = cntnode ++;  
			}  
		}  
		if(cntnode == 0)    break;//无环  
		for(int i=0;i<NV;i++) if(ID[i] == -1) {  
			ID[i] = cntnode ++;  
		}  
		//3.缩点,重新标记  
		for(int i=0;i<NE;i++) {  
			int v = E[i].v;  
			E[i].u = ID[E[i].u];  
			E[i].v = ID[E[i].v];  
			if(E[i].u != E[i].v) {  
				E[i].cost -= In[v];  
			}  
		}  
		NV = cntnode;  
		root = ID[root];  
	}  
	return ret;  
}  

int main() {
	int n, m, a[N], s[N];
	while (1){
	scanf("%d%d", &n, &m);
	if (!n) break;
	Rep(i, n) {
		scanf("%d", &a[i]);
		a[i]++;
	}
	s[0] = 0;
	Rep(i, n) s[i + 1] = a[i] + s[i];
	ecnt = 0;
	Rep(i, n) {
		for (int j = s[i + 1] - 1; j>s[i]; j--) addedge(j, j - 1, 0);
		addedge(s[n], s[i], 0);
	}
	while (m--) {
		int a, L1, b, L2, cost;
		scanf("%d%d%d%d%d", &a, &L1, &b, &L2, &cost);
		a--, b--;
		a = s[a] + L1;
		b = s[b] + L2;
		addedge(a, b, cost);
	}
	printf("%d\n", Directed_MST(s[n], s[n] + 1, ecnt));
	}
	return 0;
}
