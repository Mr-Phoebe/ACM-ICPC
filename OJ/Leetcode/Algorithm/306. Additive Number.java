import java.math.BigInteger;

class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();
        BigInteger total = new BigInteger(num);

        for(int i = 1; i <= n / 2; i++)
        {
            if(num.charAt(0) == '0' && i > 1)
                return false;
            BigInteger a = new BigInteger(num.substring(0, i));
            for(int j = i+1; j < n; j++)
            {
                if(num.charAt(i) == '0' && j > i+1)
                    break;
                BigInteger b = new BigInteger(num.substring(i, j));
                System.out.println(num.substring(i, j));
                if(isValid(a, b, j, num))
                    return true;
            }
        }
        return false;
    }

    private boolean isValid(BigInteger a, BigInteger b, int pos, String num)
    {
        if(pos == num.length())
            return true;
        b = b.add(a);
        a = b.subtract(a);
        String sum = b.toString();
        return num.startsWith(sum, pos) && isValid(a, b, pos+sum.length(), num);
    }
}
