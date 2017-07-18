import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		while(cin.hasNext()) {
			BigInteger a = cin.nextBigInteger();
			BigInteger b = cin.nextBigInteger();
			a = a.multiply(b);
			System.out.println(a);
		}
		cin.close();
	}
}
