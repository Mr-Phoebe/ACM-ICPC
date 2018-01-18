class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        mypair={"(":")","[":"]","{":"}"}
        mystack=[]
        for i in s:
            if i in mypair:
                mystack.append(i)
            else:
                if mystack!=[] and mypair[mystack.pop()]==i:
                    continue
                else:
                    return False
        return True if mystack==[] else False