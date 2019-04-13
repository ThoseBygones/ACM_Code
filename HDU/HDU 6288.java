import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	public static int log2(BigInteger val) {	//Çó³ö ceil(log2(x))
		if(val.equals(BigInteger.ONE)) {	//2 ^ 0 = 1 
			return 0;
		}
		BigInteger res = BigInteger.valueOf(2);
		int cnt = 1;
		while(res.compareTo(val) < 0) {
			res = res.multiply(BigInteger.valueOf(2));	//res *= 2
			cnt ++;
		}
		return cnt;
	}
	
	public static boolean check(BigInteger val, int a, int b, BigInteger k) {
		BigInteger x = val.pow(a);	//x ^ a
		BigInteger y = BigInteger.valueOf(log2(val)).pow(b);	//[log2(x)] ^ b
		x = x.multiply(y);
		if(x.compareTo(k) <= 0) {
			return true;
		}
		return false;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner (new BufferedInputStream(System.in));
		int t;
		t = in.nextInt();
		while(t-- > 0) {
			int a = in.nextInt();
			int b = in.nextInt();
			BigInteger k = in.nextBigInteger();
			BigInteger l = BigInteger.valueOf(1);
			BigInteger r = k;
			BigInteger ans = BigInteger.ONE;
			while(l.compareTo(r) <= 0) {
				BigInteger mid = l.add(r).divide(BigInteger.valueOf(2));
				if(check(mid,a,b,k) == true) {
					ans = mid;
					l = mid.add(BigInteger.ONE);
				}
				else {
					r = mid.subtract(BigInteger.ONE);
				}
			}
			System.out.println(ans);
		}
		in.close();
	}
}
