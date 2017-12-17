# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-01-08 20:42:06
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-01-08 20:42:22
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        orig = head
        prev = head
        head = None if head is None else head.next
        while head:
            if prev.val == head.val:
                prev.next = head.next
            else:
                prev = prev.next
            head = head.next
        return orig     