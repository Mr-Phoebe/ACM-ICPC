class Solution {
public:
    string nextClosestTime(string time) {
        int a, b, c, d;
        sscanf(time.c_str(),"%d:%d", &a, &c);
        oritime = a*60+c;
        diff = 24*60;
        b = a%10; a /= 10;
        d = c%10; c /= 10;
        int num[4] = {a, b, c, d};
        vector<int> ans = {a, b, c, d}, res;
        dfs(0, res, ans, num);
        return toans(ans);
    }
private:
    void dfs(int len, vector<int>& res, vector<int>& ans, int* num)
    {
        if(len > 1 && res[0] > 2)  return;
        if(len > 3 && res[2] > 6)  return;
        if(len == 4)
        {
            update(res, ans);
            return;
        }
        for(int i = 0; i < 4; i++)
        {
            res.push_back(num[i]);
            dfs(len+1, res, ans, num);
            res.pop_back();
        }
    }
    void update(vector<int>& now, vector<int>& ans)
    {
        int f = now[0]*10 + now[1];
        int b = now[2]*10 + now[3];
        if(f >= 24 || b >= 60)    return;
        int z = f*60 + b;
        int nowdiff;
        if(z <= oritime)
            nowdiff = 24*60 + z - oritime;
        else
            nowdiff = z - oritime;
        if(diff > nowdiff)
        {
            ans = now;
            diff = nowdiff;
        }
    }
    string toans(vector<int> a)
    {
        string f;
        if(!a[0])
            f = "0"+to_string(a[1]);
        else
            f = to_string(a[0]*10+a[1]);
        string b;
        if(!a[2])
            b = "0"+to_string(a[3]);
        else
            b = to_string(a[2]*10+a[3]);
        
        return f + ":" + b;
    }
    int oritime;
    int diff;
};
