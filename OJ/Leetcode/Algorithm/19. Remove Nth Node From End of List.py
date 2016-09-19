# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        dummy = ListNode(0) 
        dummy.next = head
        walker = dummy
        runner = dummy
        
        for i in range(n):
            runner = runner.next
            
        while(runner.next != None):
            walker = walker.next
            runner = runner.next
            
        walker.next = walker.next.next
        return dummy.next