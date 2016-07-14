#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct
{
    int x, y;
    int w;
}edge;
const int MAXN = 50005;
edge e[MAXN];
int ans;

int rank[MAXN];
int pa[MAXN];

void make_set(int x)
{
    pa[x] = x;
    rank[x] = 0;
}

int find_set(int x)
{
    if(x != pa[x])
        pa[x] = find_set(pa[x]);
    return pa[x];
}

/*按秩合并x，y所在的集合*/
void union_set(int x, int y, int w)
{
    x = find_set(x);
    y = find_set(y);
    if(x == y)
		return ;
    ans += w;
    if(rank[x] > rank[y])/*让rank比较高的作为父结点*/
    {
        pa[y] = x;
    }
    else 
    {
        pa[x] = y;
        if(rank[x] == rank[y])
            rank[y]++;
    }
}


int cmp(const void *a, const void *b)
{
    return ( (*(edge *)a).w > (*(edge *)b).w ) ? 1 : -1;
}

int main()
{
	freopen("data.txt","r",stdin);
    int n, i, j, x, y, k;
    while(scanf("%d", &n) && n)
    {
        k = n * (n-1) / 2;
        j = 0;
        for(i = 0; i < k; i++)
        {
            scanf("%d%d%d", &e[j].x, &e[j].y, &e[j].w);
            j++;
        }

        for(i = 0; i <= n; i++)
            make_set(i);

        qsort(e, j, sizeof(e[0]), cmp);

        /*Kruscal过程求最小生成树*/
        ans = 0;
        for(i = 0; i < j; i++)
        {
            x = find_set(e[i].x);
            y = find_set(e[i].y);
            if(x != y)
                union_set(x, y, e[i].w);
        }
        printf("%d\n", ans);
    }
    return 0;
}