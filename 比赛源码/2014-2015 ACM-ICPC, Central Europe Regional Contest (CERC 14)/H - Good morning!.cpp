#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

set<int> n[10];

set<int> s;
set< int,greater<int> > rs;

int t,x;

bool judge(int x)
{
    int tmp[10],cnt=0;
    while(x > 0)
    {
        tmp[cnt++] = x % 10;
        x /= 10;
    }
    tmp[cnt++]=1;
    for(int i=cnt-1;i>=1;i--)
        if(n[tmp[i]].find(tmp[i-1])==n[tmp[i]].end())   return  false;
    return true;
}

int main()
{
    for(int i=0;i<10;i++) n[i].clear();

    n[1].insert(1);
    n[1].insert(2);
    n[1].insert(3);
    n[1].insert(4);
    n[1].insert(5);
    n[1].insert(6);
    n[1].insert(7);
    n[1].insert(8);
    n[1].insert(9);
    n[1].insert(0);

    n[2].insert(2);
    n[2].insert(3);
    n[2].insert(5);
    n[2].insert(6);
    n[2].insert(8);
    n[2].insert(9);
    n[2].insert(0);

    n[3].insert(3);
    n[3].insert(6);
    n[3].insert(9);

    n[4].insert(4);
    n[4].insert(5);
    n[4].insert(6);
    n[4].insert(7);
    n[4].insert(8);
    n[4].insert(9);
    n[4].insert(0);

    n[5].insert(5);
    n[5].insert(6);
    n[5].insert(8);
    n[5].insert(9);
    n[5].insert(0);

    n[6].insert(6);
    n[6].insert(9);

    n[7].insert(7);
    n[7].insert(8);
    n[7].insert(9);
    n[7].insert(0);

    n[8].insert(8);
    n[8].insert(9);
    n[8].insert(0);

    n[9].insert(9);

    n[0].insert(0);

    s.clear();
    rs.clear();

    for(int i=0;i<=999;i++)
    if(judge(i))
    {
        s.insert(i);
        rs.insert(i);
    }

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&x);

        int nxt = *(s.lower_bound(x));
        int pre = *(rs.lower_bound(x));

        if(nxt - x > x - pre)
            printf("%d\n" , pre);
        else
            printf("%d\n" , nxt);
    }
    return 0;
}