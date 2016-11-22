# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        if not head.next:
            return head
        p1 = head
        p2 = p1.next
        
        while True:
            p1.val, p2.val = p2.val, p1.val
            if not p2.next:
                break
            else:
                p1 = p2.next
            
            if not p1.next:
                break
            else:
                p2 = p1.next
        
        return head
        