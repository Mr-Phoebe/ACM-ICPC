# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.stack = [[nestedList, 0]]

    def next(self):
        """
        :rtype: int
        """
        self.hasNext()
        nextlist = self.stack[-1][0]
        pos = self.stack[-1][1]
        self.stack[-1][1] += 1
        return nextlist[pos].getInteger()

    def hasNext(self):
        """
        :rtype: bool
        """
        while len(self.stack) > 0:
            nextlist = self.stack[-1][0]    
            pos = self.stack[-1][1]
            if pos >= len(nextlist):
                self.stack.pop()
            else:
                self.stack[-1][1] = pos + 1
                if nextlist[pos].isInteger():
                    self.stack.append([[nextlist[pos]], 0])
                    return True
                else:
                    self.stack.append([nextlist[pos].getList(), 0])
                
        return False

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
