//Hello. I'm Peter.
//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<cctype>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;

const int N = 10010, mod = 1e9 + 7;
int n, P, val[N], Z, Z2, A, B;
vector<int>v[N];

int d[N], maxd, y, fa[N];
void dfs(int now, int f, int dep){
    d[now] = 0, fa[now] = f;
    for(int i = 0; i < v[now].size(); i++){
        int to = v[now][i];
        if(to == f) continue;
        dfs(to, now, dep + 1);
        if(y == 1) d[now] = max(d[now], d[to]);
    }
    d[now] = max(d[now], dep), maxd = max(maxd, d[now]);
}

bool vis[N];
vector<int>findansv(int Z){
    vector<int>ans; ans.clear();
    /*---------find A(the starting vertex)---------*/
    maxd = 0, y = 0, dfs(Z, 0, 0);
    
    vector<int>q; q.clear();
    int vm = -1, dm = -1;
    for(int i = 1; i <= n; i++) if(val[i] && (d[i] > dm || (d[i] == dm && val[i] > vm))) dm = d[i], vm = val[i];
    for(int i = 1; i <= n; i++) vis[i] = 0;
    for(int i = 1; i <= n; i++) if(d[i] == dm && val[i] == vm) q.push_back(i), vis[i] = 1;
    for(int i = dm; i >= 2; i--){
        vm = -1;
        for(int j = 0; j < q.size(); j++) vm = max(vm, val[fa[q[j]]]);
        
        vector<int>q2; q2.clear();
        for(int j = 0; j < q.size(); j++) if(val[fa[q[j]]] == vm && !vis[fa[q[j]]]) q2.push_back(fa[q[j]]), vis[fa[q[j]]] = 1;
        q = q2;
    }
    
    A = Z;
    for(int i = 1; i <= dm; i++){
        ans.push_back(val[A]);
        for(int j = 0, a = 1; j < v[A].size() && a == 1; j++){
            int to = v[A][j];
            if(to == fa[A]) continue;
            if(vis[to]) A = to, a = 0;
        }
    }
    ans.push_back(val[A]);
    reverse(ans.begin(), ans.end());
    
    
    /*---------find B(the destination vertex)---------*/
    maxd = 0, y = 1, dfs(Z, 0, 0);
    
    int ban = q.size() == 1? q.front() : 0;
    q.clear();
    q.push_back(Z);
    while(true){
        int vm = -1, dm = -1;
        for(int i = 0; i < q.size(); i++){
            for(int j = 0; j < v[q[i]].size(); j++){
                int to = v[q[i]][j];
                if(to == ban || to == fa[q[i]]) continue;
                if(d[to] > dm || (d[to] == dm && val[to] > vm)) dm = d[to], vm = val[to];
            }
        }
        
        vector<int>q2; q2.clear();
        for(int i = 0; i < q.size(); i++){
            for(int j = 0; j < v[q[i]].size(); j++){
                int to = v[q[i]][j];
                if(to == ban || to == fa[q[i]]) continue;
                if(d[to] == dm && val[to] == vm) q2.push_back(to);
            }
        }
        if(q2.empty()) break;
        q = q2;
    }
    
    vector<int>ans2; ans2.clear();
    B = q[0];
    //printf("Z = %d A = %d B = %d ban = %d\n",Z,A,B,ban);
    while(B != Z){
        ans2.push_back(val[B]);
        B = fa[B];
    }
    for(int i = (int)ans2.size() - 1; i >= 0; i--) ans.push_back(ans2[i]);
    
    return ans;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++){
        /*---------get input and build edge---------*/
        scanf("%d%d",&n,&P);
        for(int i = 1; i <= n; i++){
            v[i].clear();
        }
        for(int i = 1; i < n; i++){
            int a, b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b), v[b].push_back(a);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d",val + i);
        }
        
        /*---------find Z(the middle vertex of tree)---------*/
        maxd = 0, y = 0, dfs(1, 0, 0);
        for(int i = 1; i <= n; i++){
            if(d[i] == maxd){
                Z = i;
                break;
            }
        }
        maxd = 0, y = 1, dfs(Z, 0, 0);
        //printf("Z = %d\n",Z);
        
        Z2 = -1;
        for(int i = 1; i <= maxd>>1; i++){
            for(int j = 0; j < v[Z].size(); j++){
                int to = v[Z][j];
                if(to == fa[Z]) continue;
                if(d[to] == maxd){
                    Z = to;
                    break;
                }
            }
            if(i == maxd>>1 && !((maxd+1)&1))
            {
                Z2 = Z;
                for(int j = 0; j < v[Z2].size(); j++){
                    int to = v[Z2][j];
                    if(to == fa[Z2]) continue;
                    if(d[to] == maxd){
                        Z2 = to;
                        break;
                    }
                }
            }
        }
        //printf("maxd = %d Z = %d Z2 = %d\n",maxd,Z,Z2);
        
        vector<int>ans = findansv(Z);
        if(Z2 != -1){
            vector<int>ans2 = findansv(Z2);
            if(ans2.size() > ans.size()) ans = ans2;
            else if(ans2.size() == ans.size()){
                bool b = 0;
                for(int i = 0; i < ans.size() && !b; i++){
                    if(ans2[i] > ans[i]) b = 1;
                    else if(ans2[i] < ans[i]) break;
                }
                if(b) ans = ans2;
            }
        }
        
        ll p1 = 1, MAX = 0;
        for(int i = (int)ans.size() - 1; i >= 0; i--){
            MAX = (MAX + p1 * ans[i] % mod) % mod;
            p1 = p1 * P % mod;
        }
        printf("Case #%d: %d\n",kase,(int)MAX);
        for(int i = 0; i < ans.size(); i++){
            printf("%d%c", ans[i], i + 1 == ans.size()?'\n':' ');
        }
    }
    return 0;
}

