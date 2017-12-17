class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if len(words) == 0:
            return []
        wordsMap = {}
        for word in words:
            if word not in wordsMap:
                wordsMap[word] = 1
            else:
                wordsMap[word] += 1
        word_size = len(words)
        word_len = len(words[0])
        ans = []
        for i in range(len(s) - word_len * word_size + 1):
            j = 0
            cur_dict = {}
            while j < word_size:
                word = s[i + word_len * j:i + word_len * j + word_len]
                if word not in wordsMap:
                    break
                if word not in cur_dict:
                    cur_dict[word] = 1
                else:
                    cur_dict[word] += 1
                if cur_dict[word] > wordsMap[word]:
                    break
                j += 1
            if j == word_size:
                ans.append(i)
        return ans
