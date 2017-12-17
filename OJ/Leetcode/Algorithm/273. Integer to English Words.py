class Solution(object):
    def change(self, a):
        below_20 =  ["", "One", "Two", "Three", "Four","Five",
                     "Six","Seven","Eight","Nine","Ten", 
                     "Eleven","Twelve","Thirteen","Fourteen",
                     "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"]
        below_100 = ["", "", "Twenty", "Thirty", "Forty", 
                     "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        s = ""
        h = int(a/100)
        t = int((a%100)/10)
        n = int(a%10)

        if h != 0:
            s = s + below_20[h] + " " + "Hundred"
        if t != 0:
            if t >= 2:
                s = s + " " + below_100[t] + " " + below_20[n]
            else:
                s = s + " " + below_20[t*10+n]
        elif n !=0:
            s = s + " " + below_20[n]
        return s.strip()
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        a = num

        bb = int(a/1000000000)
        mm = int((a%1000000000)/1000000)
        tt = int((a%1000000)/1000)
        ww = int(a%1000)

        if a == 0:
            return "Zero"
        ans = ""
        if bb != 0:
            ans = ans + self.change(bb) + " Billion "
        if mm != 0:
            ans = ans + self.change(mm) + " Million "
        if tt != 0:
            ans = ans + self.change(tt) + " Thousand "
        if ww != 0:
            ans = ans + self.change(ww)

        return ans.strip()