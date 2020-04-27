import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		BigInteger[] ans = new BigInteger[10005];
		ans[0] = BigInteger.ONE;
		ans[1] = BigInteger.ONE;
		for(int i = 2; i <= 10000; i++) {
			ans[i] = ans[i-1].multiply(BigInteger.valueOf(i));
		}
		while(in.hasNextInt()) {
			int x = in.nextInt();
			System.out.println(ans[x]);
		}
		in.close();
	}
}
