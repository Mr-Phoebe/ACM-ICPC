class Solution {
    public boolean isAnagram(String s, String t) {
        if(s == null && t == null) return true;
        if(s.length() != t.length()) return false;

        int[] freqs = new int[26]; int [] freqt = new int[26];
        for(char c: s.toCharArray())
            freqs[c - 'a'] += 1;
        for(char c: t.toCharArray())
            freqt[c - 'a'] += 1;
        return Arrays.equals(freqs, freqt);
    }
}
