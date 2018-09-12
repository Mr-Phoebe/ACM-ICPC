struct Node{
    int w, to;
    Node(int w,int to)
    {
        this->w = w;
        this->to = to;
    }
    Node(){}
    bool operator < (const Node &x) const
    {
        return w > x.w;
    }
};

class Solution {
public:
    bool is_a_path(string a, string b)
    {
        int len = a.length();
        int dif = 0;
        for(int i=0;i<len;i++)
            if(a[i] != b[i])
                dif++;
        return (dif == 1);
    }
    void addPath(vector<string>& wordList, vector<vector<int>>& path){
        int a,b;
        int n = (int)wordList.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(is_a_path(wordList[i], wordList[j]))
                {
                    if(i == 0 || j == n-1)
                    {
                        path[i].push_back(j);
                    }
                    else
                    {
                        path[i].push_back(j);
                        path[j].push_back(i);
                    }
                }
            }
        }
    }

    void addResult(vector<string>& wordList,vector<vector<string>>& res, vector<vector<int>>& pre,int dst, int src, vector<string>& tmp){
        if(dst == src)
        {
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<(int)pre[dst].size();i++)
        {
            tmp.push_back(wordList[pre[dst][i]]);
            addResult(wordList, res, pre, pre[dst][i], src, tmp);
            tmp.pop_back();
        }
    }

    void Dijkstra(vector<vector<int>>& path, vector<string>& wordList,vector<vector<string>>& res){
        priority_queue<Node> q;
        int INF = 0x7fffffff;
        int n = (int)wordList.size();
        vector<int> dp(n+5, INF);
        vector<vector<int>> pre(n+5);
        vector<int> vis(n+5, 0);
        int src = 0;
        int dst = n-1;
        dp[src] = 0;
        q.push(Node(0, src));
        while(!q.empty())
        {
            Node top = q.top();
            q.pop();
            if(vis[top.to]) continue;
            vis[top.to] = 1;
            for(int i=0;i<(int)path[top.to].size();i++)
            {
                int tmp = path[top.to][i];
                if(dp[tmp] >= top.w + 1)
                {
                    dp[tmp] = top.w + 1;
                    pre[tmp].push_back(top.to);
                    q.push(Node(dp[tmp],tmp));
                }
            }
        }
        vector<string> tmp;
        tmp.push_back(wordList[dst]);

        // backtrace to get the result
        addResult(wordList, res, pre, dst, src, tmp);
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = (int)wordList.size();
        vector<vector<string>> res;
        vector<vector<int>> path(n+5);
        if(n == 0) return res;
        vector<string> mwordList;
        mwordList.push_back(beginWord);
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(wordList[i] == beginWord)
                continue;
            if(wordList[i] == endWord)
            {
                flag = 1;
                continue;
            }
            mwordList.push_back(wordList[i]);
        }
        if(flag == 0)
            return res;
        mwordList.push_back(endWord);
        addPath(mwordList, path);


        Dijkstra(path, mwordList, res);

        for(int i=0;i<(int)res.size();i++)
            reverse(res[i].begin(), res[i].end());
        return res;
    }
};
