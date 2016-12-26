# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2016-12-26 10:43:16
# @Last Modified by:   HaonanWu
# @Last Modified time: 2016-12-26 10:43:25
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        aa = int(a, 2)
        bb = int(b, 2)
        return bin(aa+bb).replace('0b','')