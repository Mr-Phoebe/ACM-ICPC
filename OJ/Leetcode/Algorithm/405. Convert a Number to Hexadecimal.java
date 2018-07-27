class Solution {
    public String toHex(int num) {
        if(num == 0)
            return "0";
        StringBuilder sb = new StringBuilder();
        while(num != 0)
        {
            int val = 0xf & num;
            char c = (char)(val + '0');
            if(val >= 10)
                c = (char)('a' + val - 10);
            sb.append(c);
            num >>= 4;
        }
        sb.reverse();
        return sb.toString();
    }
}
