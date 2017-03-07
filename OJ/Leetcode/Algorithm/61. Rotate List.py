# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None or k == 0:  
            return head  
          
        length = 1  
        node = head  
        while node.next != None:  
            length += 1  
            node = node.next  
              
        m = k % length  
          
        node.next = head  
          
        for i in range(length - m):  
            node = node.next  
          
        head = node.next  
          
        node.next = None  
          
        return head 