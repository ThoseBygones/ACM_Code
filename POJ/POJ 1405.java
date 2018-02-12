import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		int n;
		n = cin.nextInt();
		BigInteger x = BigInteger.valueOf(2);
		for(int i = 1; i <= n; i++) {
			System.out.println(x);
			x = x.multiply(x.subtract(BigInteger.valueOf(1))).add(BigInteger.valueOf(1));
		}
		cin.close();
	}
}
