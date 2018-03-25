/*
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(String str, String patter)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa","a{1,3}") → true
isMatch("aaa","a{1,3}") → false
isMatch("ab","a{1,3}b{1,3}") → true
isMatch("abc","a{1,3}b{1,3}c") → true
isMatch("abbc","a{1,3}b{1,2}c") → false
isMatch("acbac","a{1,3}b{1,3}c") → false
isMatch("abcc","a{1,3}b{1,3}cc{1,3}") → true
*/
#include<bits/stdc++.h>

using namespace std;

bool dfs(string a, string b)
{
    if(a.length() == 0 && b.length() == 0)
    {
        return true;
    }
    else if(a.length() == 0 || b.length() == 0)
        return false;
    if(a[0] != b[0])
        return false;
    if(b.length() >= 1 && b[1] == '{')
    {
        int len = 0, l = 0, r = 0;
        for(;b[len+1] != '}'; len++);
        string lr = b.substr(1, len);
        string rest = b.substr(len+2);
        sscanf(lr.c_str(), "{%d,%d}", &l, &r);
        for(int i = l; i < r; i++)
        {
            int pos = i-1;
            if(pos >= a.length())
                break;
            if(a[pos] == b[0])
            {
                if(dfs(a.substr(pos+1), rest))
                    return true;
            }
            else
            {
                break;
            }
        }
        return false;
    }
    else
        return dfs(a.substr(1), b.substr(1));
}

bool isMatch(string& a, string& b)
{
    return dfs(a, b);
}

int main()
{
    int n;
    string a, b;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;
        cout<<isMatch(a, b)<<endl;
    }
    return 0 ;
}
