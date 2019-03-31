class Solution {
public:
    bool queryString(string S, int N) {
        unordered_set<int> st;
        st.insert(0);
        for(int i = 0; i < S.size(); i++)
        {
            int tmp = 0;
            for(int j = i; j < i+30 && j < S.size(); j++)
            {
                tmp *= 2;
                tmp += S[j] - 48;
                if(tmp > N)
                    break;
                st.insert(tmp);
            }   
        }
        if(st.size() == N+1)
            return true;
        return false;
    }
};
