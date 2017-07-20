import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		BigInteger[] a = new BigInteger[105];
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		while(cin.hasNext()) {
			BigInteger x = cin.nextBigInteger();
			BigInteger y = cin.nextBigInteger();
			BigInteger z = cin.nextBigInteger();
			a[0] = x;
			a[1] = y;
			a[2] = z;
			for(int i = 3; i <= 99; i++) {
				a[i] = BigInteger.valueOf(0);
				a[i] = a[i].add(a[i-1]);
				a[i] = a[i].add(a[i-2]);
				a[i] = a[i].add(a[i-3]);
			}
			System.out.println(a[99]);
		}
		cin.close();
	}
}
