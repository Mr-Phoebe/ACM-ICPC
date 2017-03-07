class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        import re
        num_pt1 = '^[+|-]?\.?\d+'
        num_pt2 = '^[+|-]?\d+\.\d*'
        e_pt1 =   num_pt1 + '[e|E][+|-]?\d+'
        e_pt2 =   num_pt2 + '[e|E][+|-]?\d+'
        pt = num_pt1 + '$|' + num_pt2 + '$|' + e_pt1 +'$|' + e_pt2 + '$'
        #if re.match('^[+|-]?\.?\d+$|^[+|-]?\d+\.\d*$|^[+|-]?\.?\d+e[+|-]?\d+$|^[+|-]?\d+\.\d*e[+|-]?\d+$', s.strip()):
        if re.match(pt, s.strip()):
            return True
        else:
            return False