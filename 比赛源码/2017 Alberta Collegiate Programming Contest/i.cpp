#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    int k = sqrt(n+5);
    set<int> s[k+5];
    int cur = -1;
    for(int i=0; i<n; i++)
    {
        if(i%k == 0) cur++;
        s[cur].insert(a[i]);
    }
    cur++;
    int q;
    cin >> q;
    int ind,m;
    for(int j=0; j<q; j++)
    {
        cin >> ind >> m;
        ind--;
        set<int> b;
        int x;
        for(int i=0; i<m; i++)
        {
            cin >> x;
            b.insert(x);
        }
        int i;
        int flag = 0;
        for(i=ind; (i)%k != 0; i++)
        {
            if(b.find(a[i]) == b.end())
            {
                flag = 1;
                cout << i-ind << "\n";
                break;
            }
        }
        if(flag) continue;
        int cc = i/k;
        while(cc < cur)
        {
            if(s[cc].size() > b.size())
            {
                flag = 1;
                break;
            }
            int count = 0;
            for(auto it = b.begin(); it!=b.end(); it++)
            {
                if(s[cc].find(*it) != s[cc].end())
                {
                    count++;
                }
            }
            if(count != s[cc].size()) flag = 1;
            if(flag == 1) break;
            cc++;
        }
        if(cc == cur)
        {
            cout << n-ind << "\n";
            continue;
        }
        i = cc*k;
        flag = 0;
        while(i < n)
        {
            if(b.find(a[i]) == b.end())
            {
                cout << i-ind << "\n";
                flag = 1;
                break;
            }
            i++;
        }
        if(flag) continue;
        cout << n-ind << "\n";
    }

    return 0;
}
