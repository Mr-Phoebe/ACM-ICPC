class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        list = []
        for x in range(1,n+1):
            tmp = ""
            tmp += "Fizz"[x%3*4::]+"Buzz"[x%5*4::] or str(x)
            list.append(tmp)
        return list 