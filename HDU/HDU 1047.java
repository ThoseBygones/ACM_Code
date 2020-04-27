import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		int n;
		n = in.nextInt();
		while(n-- > 0) {
			BigInteger sum = BigInteger.ZERO;
			BigInteger x;
			while(in.hasNextBigInteger()) {
				x = in.nextBigInteger();
				sum = sum.add(x);
				if(x.equals(BigInteger.ZERO)) {
					System.out.println(sum);
					break;
				}
			}
			if(n != 0) {
				System.out.println("");
			}
		}
		in.close();
	}
}
