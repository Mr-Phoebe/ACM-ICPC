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

int a, n, m;
bool flag;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        if (n%2 == 1)
        {
            if (n == 1) printf("IMPOSSIBLE\n");
            else
            {
                printf("%d = %d + %d\n", n, n/2, (n+1)/2);
            }
        }
        else
        {
            flag = false;
            for (int i = 2; i <= int(sqrt(2*n))+1; i++)
                if ((2*n)%i == 0)
                {
                    if (flag) break;
                    int tmp1, tmp2, tmpa, tmpm;
                    tmp1 = i;
                    tmp2 = 2*n/i;
                    if ((tmp2-tmp1+1)%2 == 0)
                    {
                        tmpa = (tmp2-tmp1+1)/2;
                        tmpm = tmp1;
                        if (!flag || tmpm < m)
                        {
                            if (tmpa > 0)
                            {
                                flag = true;
                                a = tmpa;
                                m = tmpm;
                            }
                        }
                    }
                }
            if (!flag) printf("IMPOSSIBLE\n");
            else
            {
                printf("%d = ", n);
                for (int i = a; i <= a+m-2; i++) printf("%d + ", i);
                printf("%d\n",a+m-1);
            }
        }

    }
    return 0;
}