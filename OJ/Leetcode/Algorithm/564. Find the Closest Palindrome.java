public class Solution {
    public String nearestPalindromic(String n) {
        Long number = Long.parseLong(n);
        Long big = findHigherPalindrome(number + 1);
        Long small = findLowerPalindrome(number - 1);
        return Math.abs(number - small) > Math.abs(big - number) ? String.valueOf(big) : String.valueOf(small);
    }
    private char[] makePalindrome(char[] s)
    {
        int m = s.length;
        char[] t = Arrays.copyOf(s, m);
        for (int i = 0; i < m / 2; i++)
            t[m - 1 - i] = t[i];
        return t;
    }
    public Long findHigherPalindrome(Long limit)
    {
        String n = Long.toString(limit);
        char[] s = n.toCharArray();
        int m = s.length;
        char[] t = makePalindrome(s);
        for(int i = 0; i < m; i++)
        {
            if(s[i] < t[i])
                return Long.parseLong(String.valueOf(t));
            else if(s[i] > t[i])
            {
                for(int j = (m - 1) / 2; j >= 0; j--)
                    if(++t[j] > '9')
                        t[j] = '0';
                    else
                        break;
                t = makePalindrome(t);
                return Long.parseLong(String.valueOf(t));
            }
        }
        return Long.parseLong(String.valueOf(t));
    }
    public Long findLowerPalindrome(Long limit)
    {
        String n = Long.toString(limit);
        char[] s = n.toCharArray();
        int m = s.length;
        char[] t = makePalindrome(s);
        for(int i = 0; i < m; i++)
        {
            if(s[i] > t[i])
                return Long.parseLong(String.valueOf(t));
            else if(s[i] < t[i])
            {
                for(int j = (m - 1) / 2; j >= 0; j--)
                    if(--t[j] < '0')
                        t[j] = '9';
                    else
                        break;
                if(t[0] == '0')
                {
                    char[] a = new char[m - 1];
                    Arrays.fill(a, '9');
                    return Long.parseLong(String.valueOf(a));
                }
                t = makePalindrome(t);
                return Long.parseLong(String.valueOf(t));
            }
        }
         return Long.parseLong(String.valueOf(t));
    }
}
