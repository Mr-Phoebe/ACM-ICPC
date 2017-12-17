class Solution:
    # @param {string} s
    # @return {integer}
    def longestValidParentheses(self, s):
        length=len(s);top=0;Max=0
        str_stack=[' ' for i in range(length)]
        pos_stack=[0 for i in range(length)]
        for i in range(length):
            if s[i]=='(':
                str_stack[top]='('
                pos_stack[top]=i
                top+=1
            else:
                if top>0 and str_stack[top-1]=='(':
                    top-=1
                    tmp=i+1 if top==0 else i-pos_stack[top-1]
                    Max=Max if Max>tmp else tmp
                else:
                    str_stack[top]=')'
                    pos_stack[top]=i
                    top+=1
        return Max