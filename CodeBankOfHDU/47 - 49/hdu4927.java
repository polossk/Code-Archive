// <!--encoding UTF-8 UTF-8±àÂë--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   1007                                                     *
*****************************************************************************/

import java.util.*;
import java.io.*;
import java.math.*;
public class Main
{
    static int MaxN = 3005;
    static BigInteger x[] = new BigInteger[MaxN];
	static BigInteger C[] = new BigInteger[MaxN];
    static BigInteger cef = new BigInteger("-1");
    static int t = 0;
    static int n = 0;
    
	public static void main(String args[])
    {
		Scanner cin = new Scanner(System.in);
        t = cin.nextInt();
        C[0] = BigInteger.ONE;
        for (int tt = 0; tt < t; tt++)
        {
        	n = cin.nextInt();
        	if (n % 2 == 1)
        		cef = BigInteger.valueOf(-1);
        	else
        		cef = BigInteger.ONE;
        	for (int i = 0; i < n; i++)
        		x[i] = cin.nextBigInteger();
        	for (int i = 1; i < n - 1; i++)
        	{
        		BigInteger tmp = BigInteger.valueOf(n - i);
        		C[i] = C[i - 1].multiply(tmp).divide(BigInteger.valueOf(i));
        	}
        	C[n - 1] = C[0];
        	/*
        	for (int i = 0; i < n; i++)
        	{
        		System.out.print(x[i]);
        		System.out.print(" ");
        		System.out.println(C[i]);
        	}
        	*/
        	BigInteger ans = BigInteger.ZERO;
        	for (int i = 0; i < n; i++)
        	{
        		cef = cef.multiply(BigInteger.valueOf(-1));
        		BigInteger p = cef.multiply(C[i]);
        		BigInteger q = p.multiply(x[i]);
        		/*
        		System.out.print("adding ");
        		System.out.println(q);
        		*/
        		ans = ans.add(q);
        	}
        	System.out.println(ans);
        }
    }
}