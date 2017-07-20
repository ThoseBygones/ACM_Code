//最笨拙的dp... 1719ms...
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		BigInteger[][] dp = new BigInteger[105][1005];	//用i种钱凑出金额j的总方案数
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		while(cin.hasNext()) {
			int n = cin.nextInt();
			int m = cin.nextInt();
			for(int i = 0; i <= m; i++) {
				for(int j = 0; j <= n; j++) {
					dp[i][j] = BigInteger.valueOf(0);
				}
			}
			dp[0][0] = BigInteger.valueOf(1);
			for(int i = 1; i <= m; i++) {
				for(int k = 0; k <= n ; k += i) {
					for(int j = k; j <= n; j++) {	//或者 for(int j = n; j >= k; j--)
						dp[i][j] = dp[i][j].add(dp[i-1][j-k]);
					}
				}
			}
			System.out.println(dp[m][n]);
		}
		cin.close();
	}
}


//所谓优化递推关系以后... 1500ms...
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		BigInteger[][] dp = new BigInteger[105][1005];	//用i种钱凑出金额j的总方案数
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		while(cin.hasNext()) {
			int n = cin.nextInt();
			int m = cin.nextInt();
			for(int i = 0; i <= m; i++) {
				dp[i][0] = BigInteger.valueOf(1);
				for(int j = 1; j <= n; j++) {
					dp[i][j] = BigInteger.valueOf(0);
				}
			}
			for(int i = 1; i <= m; i++) {
				for(int j = 1; j <= n; j++) {
					if(j < i) {
						dp[i][j] = dp[i-1][j];
					}
					else {
						dp[i][j] = dp[i-1][j].add(dp[i][j-i]);
					}
				}
			}
			System.out.println(dp[m][n]);
		}
		cin.close();
	}
}