#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int n;

map<int,int> M;

int main()
{
    while(~scanf("%d",&n))
    {
        M.clear();
        for(int i=1;i<=n+1;i++)
        {
            int a;
            scanf("%d",&a);
            if(M.find(a) == M.end()) M.insert(make_pair(a,0));
            M[a]++;
        }

        for(map<int,int>::iterator It = M.begin();It != M.end();++It)
        if(It->second == 2){printf("%d\n",It->first);break;}
    }
    return 0;
}