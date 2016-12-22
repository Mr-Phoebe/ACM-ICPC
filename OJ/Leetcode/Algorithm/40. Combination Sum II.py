class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        result = []
        self.dfs(0, candidates, result, [], target)
        return result
    def dfs(self, i, candidates, result, path, target):
    	if target == 0:
    		result.append(path)
    		return
    	if i >= len(candidates):
    		return

    	for ii in range(i, len(candidates)):
    		if i < ii and candidates[ii] == candidates[ii-1]:
    			continue
       		if candidates[ii] > target:
    			break
    		self.dfs(ii+1, candidates, result, path + [candidates[ii]], target-candidates[ii])


'''
def combinationSum2(self, candidates, target):
    candidates.sort()
    table = [None] + [set() for i in range(target)]
    for i in candidates:
        if i > target:
            break
        for j in range(target - i, 0, -1):
            table[i + j] |= {elt + (i,) for elt in table[j]}
        table[i].add((i,))
    return map(list, table[target])
'''