class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        table = ['','','abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']
        queue = ['']
        for x in digits:
            new_q = []
            for y in queue:
                for a in table[int(x)]:
                    new_q.append(y+a)
            queue = new_q
        return queue