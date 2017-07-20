//�׾��dp... 1719ms...
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		BigInteger[][] dp = new BigInteger[105][1005];	//��i��Ǯ�ճ����j���ܷ�����
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
					for(int j = k; j <= n; j++) {	//���� for(int j = n; j >= k; j--)
						dp[i][j] = dp[i][j].add(dp[i-1][j-k]);
					}
				}
			}
			System.out.println(dp[m][n]);
		}
		cin.close();
	}
}


//��ν�Ż����ƹ�ϵ�Ժ�... 1500ms...
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		BigInteger[][] dp = new BigInteger[105][1005];	//��i��Ǯ�ճ����j���ܷ�����
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