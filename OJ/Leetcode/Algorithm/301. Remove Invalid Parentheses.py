class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        l = 0; r = 0;
        for c in s:
            if c == '(':
                l += 1
            elif c == ')':
                if l != 0:
                    l -= 1
                else:
                    r += 1
        valid = set()
        self.dfs(s,0,"",l,r,0,valid)
        return list(valid)
        
    def dfs(self, s, pos, ans, l, r, need, valid):
        if(l < 0 or r < 0 or need < 0):
            return
        ll = len(s)
        if pos == ll:
            if(l == 0 and r == 0 and need == 0):
                valid.add(ans)
            return
        c = s[pos]
        if c == '(':
            self.dfs(s, pos+1, ans+c, l,   r, need+1, valid)
            self.dfs(s, pos+1, ans,   l-1, r, need,   valid)
        elif c == ')':
            self.dfs(s, pos+1, ans+c, l, r,   need-1, valid)
            self.dfs(s, pos+1, ans,   l, r-1, need,   valid)
        else:
            self.dfs(s, pos+1, ans+c, l, r, need, valid)
        return