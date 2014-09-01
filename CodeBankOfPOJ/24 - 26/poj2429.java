// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   H                                                        *
*****************************************************************************/

import java.util.*;
import java.io.*;
import java.lang.Math;
public class Main
{
    static long gcd(long a, long b)
    {
        return (b == 0)? a: gcd(b, a % b);
    }
    static long lcm(long a, long b)
    {
        return a / gcd(a, b) * b;
    }
    public static void main(String args[])
	{
        Scanner cin = new Scanner(System.in);
        long g, l, c, a, b;
        while (cin.hasNext())
        {
            g = cin.nextLong();
            l = cin.nextLong();
            c = l / g;
            for (long i = (long)Math.sqrt(c); i >= 1; i--)
                if (c % i == 0 && gcd(i, c / i) == 1)
            {
                a = g * i; b = l / i;
				System.out.println(a + " " + b);
                break;
            }
        }
    }
}
