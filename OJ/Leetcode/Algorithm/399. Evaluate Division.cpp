class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        v = vector<double>(2*equations.size()+1, 1.0);
        p = vector<int>(2*equations.size()+1, 0);
        for( int i = 0; i < values.size(); i ++ )
            add( equations[i], values[i] );
        for( auto q: queries )
        {
            int i = m[q.first], j = m[q.second], h1 = find_fa( i ), h2 = find_fa( j );
            if( h1 && (h1 == h2) )
                res.push_back(v[j]/v[i]);
            else res.push_back(-1.0);
        }
        return res;
    }
private:
    int idx = 1;
    unordered_map<string,int> m;
    vector<double> v;
    vector<int> p;
    int find_fa( int idx )
    {
        if( idx == 0 ) return 0;
        else if( p[idx] == 0 ) return idx;
        int temp = find_fa( p[idx] );
        v[idx] *= v[p[idx]];
        p[idx] = temp;
        return p[idx];
    }
    void add(pair<string, string> eq, double val)
    {
         auto i = getIdx(eq.first), j = getIdx(eq.second), h1 = find_fa(i), h2 = find_fa(j);
         if( h1 != h2 )
         {
             p[h2] = h1;
             v[h2] = v[i]/v[j]*val;
         }
    }
    int getIdx( string s )
    {
        if( m.find(s) == m.end() )
        {
            m[s] = idx;
            return idx++;
        }
        else return m[s];
    }
};
