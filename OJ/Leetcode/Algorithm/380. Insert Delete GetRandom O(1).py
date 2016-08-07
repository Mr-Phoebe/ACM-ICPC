import random
class RandomizedSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.output = []
        self.index = {}
        

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.index:
            return False
        self.output.append(val)
        self.index[val] = len(self.output) - 1
        return True
        

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.index:
            return False
        index = self.index[val]
        last = self.output[-1]
        self.index[last] = index
        self.output[index] = last
        self.output.pop()
        del self.index[val]
        return True
        

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        return self.output[random.randint(0,len(self.output)-1)]

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()