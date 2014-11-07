import java.math.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int a, b;
        while(cin.hasNext())
        {
            a = cin.nextInt();
            b = cin.nextInt();
			BigInteger a_b = BigInteger.valueOf(a).pow(b);
			BigInteger b_a = BigInteger.valueOf(b).pow(a);
			BigInteger ans = a_b.subtract(b_a);
            System.out.println(ans);
        }
    }
}