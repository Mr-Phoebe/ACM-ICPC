#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define mp make_pair
#define fi first
#define se second
typedef pair<int, int> PII;
typedef set<PII>:: iterator PIIP;

set<PII> A;
PII a1, a2, a3, a4;
PIIP i, j, k, l;

int n, m;

void addnode(int x, int y)
{
    if (x >= 0 && x <= n && y >= 0 && y <= m)
        A.insert(mp(x, y));
}

double dist(PII x, PII y)
{
    return sqrt((x.fi-y.fi)*(x.fi-y.fi) + (x.se-y.se)*(x.se-y.se));
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        A.clear();
        // ÓÒÉÏ½Ç
        addnode(n, m);
        addnode(n, m-1);
        addnode(n-1, m-1);
        addnode(n-1, m);
        // ÓÒÏÂ½Ç
        addnode(n, 1);
        addnode(n, 0);
        addnode(n-1, 0);
        addnode(n-1, 1);
        // ×óÏÂ½Ç
        addnode(1, 1);
        addnode(1, 0);
        addnode(0, 0);
        addnode(0, 1);
        // ×óÉÏ½Ç
        addnode(1, m);
        addnode(1, m-1);
        addnode(0, m-1);
        addnode(0, m);

        double tmp = -1;
        for (i = A.begin(); i != A.end(); i++)
        {
            for (j = A.begin(); j != A.end(); j++)
            {
                for (k = A.begin(); k != A.end(); k++)
                {
                    for (l = A.begin(); l != A.end(); l++)
                    {
                        if (i == j || i == k || i == l || j == k || j == l || k == l)
                            continue;
                        double t = dist(*i, *j) + dist(*j, *k) + dist(*k, *l);
                        if (t > tmp)
                        {
                            tmp = t;
                            a1 = *i;
                            a2 = *j;
                            a3 = *k;
                            a4 = *l;
                        }
                    }
                }
            }
        }
        printf("%d %d\n", a1.fi, a1.se);
        printf("%d %d\n", a2.fi, a2.se);
        printf("%d %d\n", a3.fi, a3.se);
        printf("%d %d\n", a4.fi, a4.se);
    }
    return 0;
}