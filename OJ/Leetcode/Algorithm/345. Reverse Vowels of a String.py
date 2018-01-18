class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = re.findall('[aeiouAEIOU]', s)
        return re.sub('[aeiouAEIOU]', lambda m: vowels.pop(), s)