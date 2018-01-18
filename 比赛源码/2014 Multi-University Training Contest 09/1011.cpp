#include <stdio.h>
#include <cstring>
//#include <assert.h>
#include <iostream>
using namespace std;

const int MAX_N = 100002;

int n, m;
long long attack[MAX_N];

void init(){
    int x, y, d;
    
    memset(attack, 0, sizeof(attack[0]) * (n + 1));
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &x, &y, &d);
        attack[x] += d;
        attack[y + 1] -= d;
    }
    for (int i = 1; i <= n; i++) attack[i] += attack[i - 1];
    for (int i = n - 1; i >= 1; i--) attack[i] += attack[i + 1];
}

void solve(){
    long long hp;
    int total = 0, K, pos;
    scanf("%d", &K);
    for (int i = 0; i < K; i++){
        scanf("%I64d%d", &hp, &pos);
        if (attack[pos] < hp) total++;
    }
    printf("%d\n", total);
}

int main(){
while (1){
    scanf("%d%d", &n, &m);
    if (!n) break;
    init();
    solve();
}
    return 0;
}
