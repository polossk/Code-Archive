import java.math.BigInteger;
import java.util.*;
import java.math.*;
public class Main {
	public static void main(String args[]){
    	  Scanner cin = new Scanner(System.in);
    	  while (true){
    		  BigInteger a = cin.nextBigInteger();
    		  if (a.equals(BigInteger.ZERO)){
    			  break;
    		  }
    		  BigInteger ans ;
    		  BigInteger b = a.mod(BigInteger.valueOf(10));
    		  a = a.divide(BigInteger.valueOf(10));
    		  a = a.subtract(b.multiply(BigInteger.valueOf(5)));
    		  a = a.abs();
    		  ans = a.mod(BigInteger.valueOf(17));
    		  if (ans.equals(BigInteger.ZERO))
    			  System.out.println(1);
    		  else
    			  System.out.println(0);
    	  }
      }
}