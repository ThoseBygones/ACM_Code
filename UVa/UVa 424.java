import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		BigInteger ans = BigInteger.valueOf(0);
		while(cin.hasNext()) {
			BigInteger n = cin.nextBigInteger();
			if(n.equals(BigInteger.valueOf(0)))
				break;
			ans = ans.add(n);
		}
		System.out.println(ans);
		cin.close();
	}
}
