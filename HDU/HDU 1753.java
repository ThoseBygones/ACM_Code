import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		BigDecimal a, b, sum;
		while(in.hasNextBigDecimal()) {
			a = in.nextBigDecimal();
			b = in.nextBigDecimal();
			sum = a.add(b);
			String ans = sum.stripTrailingZeros().toPlainString();
			System.out.println(ans);
		}
		in.close();
	}
}
