class CatchTheBeat
{
public:
    template<class CC> int LIS_num(vector<CC>& v)
    {
        int i,N=v.size();
        vector<CC> dp(N,(numeric_limits<CC>::max)()),id(N);
        for(int i = 0; i < v.size(); i++)
        {
            id[i] = lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin();
            dp[id[i]] = v[i] - 1;
        }
            
        return *max_element(id.begin(),id.end())+1;
    }

    int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset)
    {
        vector<ll> X(n,0),Y(n,0);
        vector<pair<int,ll> > P;
        X[0] = x0;
        Y[0] = y0;
        for(int i=1; i<n; i++)
        {
            X[i] = (X[i-1]*(ll)a+b)%mod1;
            Y[i] = (Y[i-1]*(ll)c+d)%mod2;
        }
        for(int i = 0; i < n; i++)
        {
            X[i] -= offset;
            if(Y[i]-X[i]<0 || X[i]+Y[i]<0) continue;
            P.pb(mp(Y[i]-X[i],X[i]+Y[i]));
        }
        if(P.empty()) return 0;

        sort(P.begin(),P.end());
        vector<ll> V;
        for(auto it : P) V.pb(it.second);
        return LIS_num(V);
    }
}
