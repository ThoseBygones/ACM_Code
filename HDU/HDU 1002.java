import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		int T;
		T = in.nextInt();
		for(int i = 1; i <= T; i++) {
			BigInteger a, b, c;
			a = in.nextBigInteger();
			b = in.nextBigInteger();
			c = a.add(b);
			System.out.println("Case " + i + ":");
			System.out.println(a + " + " + b + " = " + c);
			if(i != T) {
				System.out.println("");
			}
		}
		in.close();
	}
}
