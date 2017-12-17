#include <bits/stdc++.h>
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)>(b))?(b):(a)
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0E-8
#define MAX_N 1010
#define INF 1 << 30
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;

bool atlas[1001][1001] = { { false } }, used[1001] = { false };
int next[1001], len = 1, head = 1, tail, n;
void dfs(int now);
void extent();
void reverse(int start, int stop);
void creat_loop();

int main()
{
    int tmp;
    scanf("%d", &n);
    getchar();
    repp(i, 1, n)
    {
        while(true)
        {
            scanf("%d", &tmp);
            atlas[i][tmp] = atlas[tmp][i] = true;
            tmp = getchar();
            if(tmp =='\n' || tmp==EOF || tmp == '\r') break;
        }
    }
    used[1] = true;
    dfs(1);
    while(len < n)
    {
        if(!atlas[head][tail]) creat_loop();
        extent();
    }
    if(!atlas[head][tail]) creat_loop();
    tmp = 1;
    while(n--)
    {
        printf("%d ", tmp);
        tmp = next[tmp];
    }
    puts("1");
    return 0;
}

void dfs(int now)
{
    repp(i, 1, n)
    {
        if(!used[i] && atlas[now][i])
        {
            len++;
            tail = next[now] = i;
            used[i] = true;
            if(len == n) return ;
            dfs(i);
            return ;
        }
    }
}

void extent()
{
    int tmp = head, before;
    repp(i, 1, n) if(!used[i] && atlas[i][tmp])
    {
        len++;
        next[i] = tmp;
        head = i;
        used[i] = true;
        return ;
    }
    while(true)
    {
        before = tmp, tmp = next[tmp];
        repp(i, 1, n)
        {
            if(!used[i] && atlas[tmp][i])
            {
                len++;
                used[i] = true;
                next[tail] = head;
                next[i] = tmp;
                head = i;
                tail = before;
                return ;
            }
        }
    }
}

void creat_loop()
{
    int before = next[head], tmp = next[before];
    while(true)
    {
        if(atlas[before][tail] && atlas[tmp][head])
        {
            reverse(tmp, tail);
            next[tmp] = head;
            head = tail;
            tail = before;
            next[tail] = head;
            return ;
        }
        before = tmp, tmp = next[tmp];
    }
}

void reverse(int start, int stop)
{
    int to = start, from = next[start], tmp;
    while(to != stop)
    {
        tmp = next[from];
        next[from] = to;
        to = from;
        from = tmp;
    }
}
