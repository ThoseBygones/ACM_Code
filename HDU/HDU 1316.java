import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		BigInteger fib[] = new BigInteger[505];	//fib[480] > 10 ^ 100
		//BigInteger Max = BigInteger.TEN.pow(100);
		fib[1] = BigInteger.ONE;
		fib[2] = BigInteger.valueOf(2);
		for(int i = 3; i <= 500; i++) {
			fib[i] = fib[i-1].add(fib[i-2]);
			/*if(fib[i].compareTo(Max) > 0) {
				System.out.println(i);
				break;
			}*/
		}
		while(in.hasNextBigInteger()) {
			BigInteger a = in.nextBigInteger();
			BigInteger b = in.nextBigInteger();
			if(a.equals(BigInteger.ZERO) && b.equals(BigInteger.ZERO)) {
				break;
			}
			int ans = 0;
			for(int i = 1; i <= 500; i++) {
				if(a.compareTo(fib[i]) <= 0 && b.compareTo(fib[i]) >= 0) {
					ans++;
				}
				if(b.compareTo(fib[i]) < 0) {
					break;
				}
			}
			System.out.println(ans);
		}
		in.close();
	}
}
