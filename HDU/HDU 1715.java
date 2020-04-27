import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		BigInteger[] fib = new BigInteger[1005];
		fib[1] = BigInteger.ONE;
		fib[2] = BigInteger.ONE;
		for(int i = 3; i <= 1000; i++)
			fib[i] = fib[i-1].add(fib[i-2]);
		int n = in.nextInt();
		while(n-- > 0) {
			int x = in.nextInt();
			System.out.println(fib[x]);
		}
		in.close();
	}
}
