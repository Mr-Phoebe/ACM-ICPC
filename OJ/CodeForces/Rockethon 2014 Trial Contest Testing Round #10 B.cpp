#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vs[30];

int main()
{
    vs[1].push_back("i");
    vs[2].push_back("ii");
    vs[2].push_back("w");

    int n;
    scanf("%d",&n);

    if(n==1) puts("i");
    else if(n==2) puts("ii\nw");
    else
    {
        int s;
        for(int i=3;i<=n;i++)
        {
            s=vs[i-1].size();
            for(int j=s-1;j>=0;j--)
            {
                vs[i].push_back("i"+vs[i-1][j]);
            }
            s=vs[i-2].size();
            for(int j=s-1;j>=0;j--)
            {
                vs[i].push_back("w"+vs[i-2][j]);
            }
        }
        s=vs[n].size();
        for(int i=0;i<s;i++)
        {
            cout<<vs[n][i]<<endl;
        }
    }

    return 0;
}
