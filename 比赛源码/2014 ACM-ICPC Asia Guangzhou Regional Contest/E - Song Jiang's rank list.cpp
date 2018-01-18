#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int n,m;

struct Per
{
    string name;
    int val;

    Per(){}
    Per(string a,int b):name(a),val(b){}

    bool operator < (const Per &o) const
    {
        if(val == o.val) return name < o.name;
        return val > o.val;
    }
}per[205];

map<string,int> ma;


int main()
{
    while(~scanf("%d",&n))
    {
        if(n == 0) break;
        ma.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>per[i].name;
            cin>>per[i].val;
            ma[per[i].name] = per[i].val;
        }
        sort(per+1,per+1+n);

        for(int i=1;i<=n;i++)
            cout<<per[i].name<<' '<<per[i].val<<endl;

        scanf("%d",&m);

        for(int i=1;i<=m;i++)
        {
            string t;
            cin>>t;
            Per tmp = Per("",ma[t]);
            Per tmp2 = Per(t,ma[t]);
            int ans1 = lower_bound(per+1,per+n+1,tmp) - per;
            int ans2 = lower_bound(per+1,per+n+1,tmp2) - per;
            if(ans1 == ans2)
                cout<<ans1<<endl;
            else
                cout<<ans1<<" "<<ans2-ans1+1<<endl;
        }
    }
    return 0;
}
