class Solution {
public String reorganizeString(String S) {
        int n = S.length();
        if(n <= 1) 
            return S;
        int[] str = new int[26];
        int hf = 0;
        for(char a: S.toCharArray())
            if(hf < ++str[a-'a']) 
                hf = str[a-'a'];
        if(hf*2-1>n) return "";
        char[] res=new char[n];
        int odd=0, even=1;
        for(int i=0;i<26;i++)
        {
            while(str[i]>0 && str[i]<n/2+1 && even<n)
            {
                res[even]= (char)(i+'a');
                even+=2;
                str[i]--;
            }
            while(str[i]>0)
            {
                res[odd]=(char)(i+'a');
                odd+=2;
                str[i]--;
            }
        }
        return new String(res);
    }
}
