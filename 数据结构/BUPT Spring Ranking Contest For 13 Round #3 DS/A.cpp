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

using namespace std;


int main()
{
    int n,i,j,k;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++,printf("\n"))
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                printf("%d ",k);
            }
            else
            {
                printf("0 ");
            }
        }
    }
    return 0;
}
