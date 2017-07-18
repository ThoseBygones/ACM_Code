import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		while(cin.hasNext()) {
			BigInteger a = cin.nextBigInteger();
			String op = cin.next();
			BigInteger b = cin.nextBigInteger();
			BigInteger c = BigInteger.valueOf(0);
			if(op.equals("/"))
				c = a.divide(b);
			else if(op.equals("%"))
				c = a.mod(b);
			System.out.println(c);
		}
		cin.close();
	}
}