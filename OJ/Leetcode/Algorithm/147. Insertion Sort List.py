# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cur = head
        while cur:
            minn = self.findmin(cur)
            cur.val, minn.val = minn.val, cur.val
            cur = cur.next

    def findmin(self, head):
        cur = head
        minn = cur
        while cur:
            if cur.val < minn.val:
                minn = cur
            cur = cur.next

        return minn