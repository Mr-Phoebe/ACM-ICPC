import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt(), maxN = 0;
        Data[] myData = new Data[T];
        for (int i = 0; i < T; i++) {
            myData[i] = new Data();
            myData[i].read(in);
            maxN = Math.max(maxN, myData[i].getN());
        }
        BigInteger[] fib = new BigInteger[maxN];
        fib[0] = fib[1] = BigInteger.ONE;
        for (int i = 2; i < maxN; i++)
            fib[i] = fib[i - 1].add(fib[i - 2]);    
        for (int i = 0; i < T; i++)
            System.out.println(myData[i].solve(fib).remainder(new BigInteger("258280327")));
    }
}

class Data {
    private int n;
    private BigInteger m;
    public int getN() {
        return n;
    }
    public void read(Scanner in) {
        n = in.nextInt();
        m = in.nextBigInteger();
    }
    public BigInteger solve(BigInteger[] fib) {
        if (m.compareTo(BigInteger.ONE) == 0 || m.compareTo(new BigInteger("2")) == 0)
            return BigInteger.ZERO;
        int l = 0, r = n;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (fib[mid].compareTo(m.add(BigInteger.ONE)) == 1)
                r = mid;
            else
                l = mid;
        }
        return m.subtract(fib[l - 1]);
    }
}

