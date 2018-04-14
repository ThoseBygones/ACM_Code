/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-14
 *  Subject: ACM-ICPC
 *  Language: Java8
 *  OJ: HDU
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int kase = 1;
		int t = cin.nextInt();
		while(t>0) {
			BigInteger n = cin.nextBigInteger();
			if(n.equals(BigInteger.ZERO))
			{
				System.out.println("Case #" + kase + ": 1");
			}
			else if(n.equals(BigInteger.ONE)) {
				System.out.println("Case #" + kase + ": 9");
			}
			else if(n.equals(BigInteger.valueOf(2))) {
				System.out.println("Case #" + kase + ": 41");
			}
			else if(n.equals(BigInteger.valueOf(3))) {
				System.out.println("Case #" + kase + ": 109");
			}
			else if(n.equals(BigInteger.valueOf(4))) {
				System.out.println("Case #" + kase + ": 205");
			}
			else {
				BigInteger ans = n.multiply(n).multiply(BigInteger.valueOf(14)).subtract(n.multiply(BigInteger.valueOf(6))).add(BigInteger.valueOf(5));
				System.out.println("Case #" + kase + ": " + ans);
			}
			kase++;
			t--;
		}
	}
}