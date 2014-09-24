import static java.lang.System.*;
import java.util.*;
import java.util.regex.*;

public class Solution {
	static int t = 0;
	public static void main(String[] args) {
		Scanner cin = new Scanner(in);
		String prefix = "(\\w|-)+(\\.(\\w|-)+)*";
		String address = prefix + "@" + prefix + "\\.[A-Za-z]{2,3}";
		Pattern judge = Pattern.compile(address);
		t = Integer.parseInt(cin.nextLine());
		for (int tt = 0; tt < t; tt++) {
			String data = cin.nextLine();
			out.println(judge.matcher(data).matches()? "YES": "NO");
		}
	}
}
