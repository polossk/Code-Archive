// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   zoj 3818                                                 *
*****************************************************************************/

import java.io.File;
import java.util.Scanner;
import java.util.regex.Pattern;

public class Main {
 
	public void solve() throws Exception
	{
		Scanner in = new Scanner(System.in);
		int t; t = in.nextInt();
		while (t-- > 0)
		{
			String str = in.next();
			boolean flag = false;
			str = str.replaceAll("\\W|_", "");
			for (int i = 1; i <= str.length(); i++)
			{
				String a = str.substring(0, i);
				for (int j = i+1; j <= str.length(); j++)
				{
					String b = str.substring(i, j);
					if (a.equals(b)) continue;
					Pattern pat = Pattern.compile(a+b+a+b+a);
					Pattern pat2 = Pattern.compile(a+b+a+b+"\\w+"+a+b);
					Pattern pat3 = Pattern.compile(a+b+a+b+b+a+b);
					Pattern pat4 = Pattern.compile(a+b+a+b+a+a+b);
					boolean ok1 = pat3.matcher(str).matches();
					ok1 = ok1 || pat4.matcher(str).matches();
					boolean ok2 = pat.matcher(str).matches();
					ok2 = ok2 || pat2.matcher(str).matches();
					if (!ok1 && ok2) flag = true;
				}
				
			}
			if (flag) System.out.println("Yes");
			else System.out.println("No");
		}
	}

	public static void main(String[] args) throws Exception
	{
		Main test = new Main();
		test.solve();
	}

}