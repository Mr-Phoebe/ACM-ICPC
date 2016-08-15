//By LH
#pragma warning(disable:4996)
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
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

struct node
{
    int x, y, r;
} a[1005];
int n, c[1005], ansp[1005],ansq[1005], q[1005];
bool v[1005];

int gcd(int x, int y)
{
    int t;
    if (x > y) swap(x, y);
    while (x != 0)
    {
        t = y%x;
        y = x;
        x = t;
    }
    return y;
}

int dis(int i, int j)
{
    return (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].r);
        memset(c, 0, sizeof(c));
        memset(v, 0, sizeof(v));
        c[1] = 1;
        ansp[1] = 1;
        ansq[1] = 1;
        v[1] = true;
        int head = 1, tail = 1, cnt = 1;
        q[1] = 1;
        while (cnt < n && head <= tail)
        {
            int now = q[head];
            for (int i = 2; i <= n; i++)
                if (!v[i])
                {
                    if (dis(i, now) == (a[i].r+a[now].r)*(a[i].r+a[now].r))
                    {
                        if (c[now] == 0) continue;
                        else
                        {
                            cnt++;
                            v[i] = true;
                            c[i] = -c[now];
                            ansp[i] = a[now].r*ansp[now];
                            ansq[i] = a[i].r*ansq[now];
                            int tmp = gcd(ansp[i], ansq[i]);
                            ansp[i] = ansp[i]/tmp;
                            ansq[i] = ansq[i]/tmp;
                            tail++;
                            q[tail] = i;
                        }
                    }
                }
            head++;
        }
        for (int i = 1; i <= n; i++)
            if (c[i] == 0) printf("not moving\n");
            else
            {
                if (ansp[i] % ansq[i] == 0) printf("%d ", ansp[i]/ansq[i]);
                else printf("%d/%d ", ansp[i], ansq[i]);
                if (c[i] == 1) printf("clockwise\n");
                else printf("counterclockwise\n");
            }
    }
    return 0;
}