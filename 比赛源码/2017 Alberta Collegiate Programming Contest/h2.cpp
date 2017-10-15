#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

long double g[105][105][105];
long double d[105][105];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,r;
    cin >> n >> m >> r;
    vector<vector<pair<double,double> > > v(n);
    double x,y,z;
    cin >> x;
    double l,p;
    cin >> l >> p;
    for(int i=0; i<105; i++) for(int j=0; j<105; j++) for(int k=0; k<105; k++) g[i][j][k] = -2;
    for(int i=0; i<105; i++) for(int j=0; j<105; j++) d[i][j] = -2;
    for(int i=0; i<m-1; i++)
    {
        cin >> x >> y >> z;
        v[x].push_back({z,y});
    }
    for(int i=0; i<n; i++)
    {
        v[i].push_back({0,0});
        v[i].push_back({r,0});
        sort(v[i].begin(),v[i].end());
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<v[i].size()-1; j++)
        {
            for(int k=0; k<v[i+1].size()-1; k++)
            {
                int x1 = v[i][j].first + v[i][j].second;
                int y1 = v[i][j+1].first;
                int x2 = v[i+1][k].first + v[i+1][k].second;
                int y2 = v[i+1][k+1].first;
                if(max(x1,y1) < min(x2,y2))
                {
                    g[i][j][k] = -2;
                    continue;
                }
                if(max(x2,y2) < min(x1,y1))
                {
                    g[i][j][k] = -2;
                    continue;
                }
                int ll = min(y1,y2) - max(x1,x2);
                if(ll < l)
                {
                    g[i][j][k] = -2;
                    continue;
                }
                g[i][j][k] = (ll - l);
                g[i][j][k] /= 2.0;
            }
        }
    }
    priority_queue<pair<double,pair<int,int> >, vector<pair<double,pair<int,int> > >, greater<pair<double,pair<int,int> > > >q;
    for(int i=0; i<v[0].size()-1; i++)
    {
        if(v[0][i].first + v[0][i].second <= p && v[0][i+1].first >= p)
        {
            d[0][i] = min(p - v[0][i].first - v[0][i].second, v[0][i+1].first - p - l);
            q.push({d[0][i],{0,i}});
        }
    }
    while(!q.empty())
    {
        pair<double,pair<int,int> > f = q.top();
        q.pop();
        double dd = f.first;

        int i = f.second.first;
        int j = f.second.second;
        if(i != 0)
        {
            for(int k=0; k<105; k++)
            {
                if(min(d[i][j],g[i-1][k][j]) > d[i-1][k])
                {
                    d[i-1][k] = min(d[i][j],g[i-1][k][j]);
                    q.push({d[i-1][k],{i-1,k}});
                }
            }
        }
        if(i != n-1)
        {
            for(int k=0; k<105; k++)
            {
                if(min(d[i][j],g[i][j][k]) > d[i+1][k])
                {
                    d[i+1][k] = min(d[i][j],g[i][j][k]);
                    q.push({d[i+1][k],{i+1,k}});
                }
            }
        }
    }
    long double res = -2;
    for(int i=0; i<105; i++)
    {
        //cout << d[n-1][i] << " " ;
        res = max(res,d[n-1][i]);
    }
    if(res < -1) cout << "Impossible";
    else cout << fixed << setprecision(10) << res << endl;
    return 0;
}
