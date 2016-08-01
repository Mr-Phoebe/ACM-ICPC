#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int mo=1e9+7,N=5e5+10;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
const int inf = 0x3f3f3f3f;
int n, m, K, a[N], sum[N], r[N], f[N], g[N];
struct node{
	int v, id;
	bool operator < (const node &b)const{ return (v == b.v) ? (id > b.id) : (v < b.v);}
}u;
priority_queue <node> qa,qb;
void find(int x){
	g[++ g[0]] = x;
	if(r[x] == n) return;
	for(int i = x + f[0];i <= r[x];i ++) if(f[i] - i >= f[0]){ find(i); return;}
}
int main(){
	int S = 0;
	while(scanf("%d%d%d", &n, &m, &K) != EOF){
		S += n;
		for(int i = 0;i <= n;i ++) f[i] = 0;
		while(!qa.empty()) qa.pop();
		while(!qb.empty()) qb.pop();
		for(int i = 1;i <= n;i ++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
		int j = 0;
		for(int i = 0;i <= n;i ++){
			for(;j <= n && m + K * i - sum[j] > 0;j ++);
			r[i] = j - 1;
		}
		for(int i = n;i >= 1;i --){
			if(r[i] == n) f[i] = inf + i;
			else{
				while(!qa.empty()){
					u = qa.top();
					if(u.id > r[i])	qa.pop();
					else if(2 * u.id - f[u.id] >= i) qb.push((node){f[u.id] - u.id, u.id}), qa.pop();
				 	else break;
				}
				while(!qb.empty() && qb.top().id > r[i]) qb.pop();
				if(!qa.empty()) f[i] = max(f[i], qa.top().v);
				if(!qb.empty())	f[i] = max(f[i], qb.top().v + i);
			}
			if(f[i] > i) qa.push((node){i, i});
			else qb.push((node){f[i] - i, i});
		}
		for(int i = 1;i <= r[0];i ++) f[0] = max(f[0], f[i] - i);
		if(!f[0]) printf("Poor Hero!\n");
		else if(f[0] > n) printf("Poor JRY!\n");
		else{
			printf("%d\n", f[0]);
			g[0] = 0;
			for(int i = 1;i <= r[0];i ++) if(f[i] - i == f[0]){ find(i); break;}
			printf("%d\n", g[0]);
			for(int i = 1;i <= g[0];i ++) printf("%d%c", g[i], (i < g[0]) ? ' ' : '\n');
		}
	}
//	cout << S << endl;
	return 0;
}
