/*author: birdstorm*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

#define MAXN 50005
#define N 65
#define inf 1.0e20
#define eps 1.0e-6
#define MOD 1000000007

#define For(i,m,n) for(int i=(m);i<(n);i++)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define rep(i,m,n) for(int i=(m);i<=(n);i++)
#define repd(i,m,n) for(int i=(m);i>=(n);i--)
#define LL long long
#define test
#define MAX 26

using namespace std;
const int CHARSET=26, BASE='a', MAX_NODE=100005;

struct Trie{
    int tot, root, child[MAX_NODE][CHARSET];
    Trie(){
        memset(child[1],0,sizeof child[1]);
        root=tot=1;
    }
    void insert(char s[]){
        int *cur=&root;
        for(int i=0;s[i];++i){
            char g=s[i];
            cur=&child[*cur][g-BASE];
            if(*cur==0){
                *cur=++tot;
                memset(child[tot],0,sizeof child[tot]);
            }
        }
    }
    int dfs(int cur, bool flag){
        int *temp, c;
        bool vis[26]={false}, f=false;
        for(c=0; c<26; c++){
            temp=&child[cur][c];
            if(*temp!=0){
                vis[dfs(*temp,flag)]=true;
                f=true;
            }
        }
        if(!f) return flag;
        for(c=0; c<26; c++){
            if(!vis[c]) return c;
        }
    }
};

Trie p;
int t, n, x, l, r, m, k;
char str[MAXN];

int main()
{
    scanf("%d%d",&n,&k);
    For(i,0,n){
        scanf("%s",str);
        p.insert(str);
    }
    int ans=p.dfs(1,false);
    if(ans){
        if(p.dfs(1,true)) printf("First\n");
        else printf((k&1)?"First\n":"Second\n");
    }
    else printf("Second\n");
    return 0;
}

