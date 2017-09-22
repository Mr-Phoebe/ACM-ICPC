class Solution(object):
    def judgePoint24(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        import itertools

        numbers = set(tuple(itertools.permutations([str(num) + '.0' for num in nums])))
        operators = set(tuple(itertools.permutations('***///+++---', 3)))
        equation = [None] * 7
        
        for number in numbers:
            for operator in operators:
                for i, num in enumerate(number):
                    equation[i<<1] = num
                for i, opt in enumerate(operator):
                    equation[(i<<1)|1] = opt
                
                if self.possible(equation):
                    return True
        return False

    def possible(self, equation):
        
        def evaluate(eqn):
            if found[0]:
                return
            
            n = len(eqn)
            if n == 3:
                val = eval(''.join(eqn))
                if abs(val - 24) < 0.0001:
                    found[0] = True
                return

            for i in range(0, n-1, 2):
                try:
                    evaluate(eqn[:i] + [str(eval(''.join(eqn[i:i+3])))] + eqn[i+3:])
                except:
                    pass
              
        found = [False]      
        evaluate(equation)
        return found[0]