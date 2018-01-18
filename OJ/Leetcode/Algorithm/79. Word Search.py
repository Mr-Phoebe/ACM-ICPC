class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def preCheck():
            preDict = {}
    
            for i in word:
                if i in preDict: preDict[i]+=1
                else: preDict[i] = 1
            
            for i in board:
                for j in i:
                    if j in preDict and preDict[j]>0: preDict[j]-=1
            for i in preDict.values():
                if i>0: return False
            return True
                    
        
        if not board: return False
        if not word: return True
    
        if not preCheck(): return False
        
        m = len(board)
        n = len(board[0])
        l = len(word)
        for i in xrange(m):
            for j in xrange(n):
                if self.helper(board,word,i,j): return True
    
        return False
        
    def helper(self, board, word, i, j):
        if board[i][j] == word[0]:
            if not word[1:]:
                return True
            board[i][j] = " " # indicate used cell
            # check all adjacent cells
            if i > 0 and self.helper(board, word[1:], i-1, j):
                return True
            if i < len(board)-1 and self.helper(board, word[1:], i+1, j):
                return True
            if j > 0 and self.helper(board, word[1:], i, j-1):
                return True
            if j < len(board[0])-1 and self.helper(board, word[1:], i, j+1):
                return True
            board[i][j] = word[0] # update the cell to its original value
            return False
        else:
            return False
