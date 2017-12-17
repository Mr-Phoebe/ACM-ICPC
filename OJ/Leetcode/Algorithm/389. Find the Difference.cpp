class Solution {
public:
    char findTheDifference(string s, string t) {
        string tmp=s.length()>t.length()?s:t;
        string mi=s.length()<t.length()?s:t;
        unordered_map<int,int> a;
        for (int i=0;i<tmp.length();i++)
             a[tmp[i]]++;
        for (int i=0;i<mi.length();i++)
             a[mi[i]]--;
        for (unordered_map<int,int>::iterator it=a.begin();it!=a.end();++it)
            if (it->second)
                return (char)(it->first);
        return NULL;
    }
};