import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		while(in.hasNextBigDecimal()) {
			BigDecimal res = in.nextBigDecimal();
			int n = in.nextInt();
			res = res.pow(n);
			String ans = res.stripTrailingZeros().toPlainString();	//去掉小数点和后面多余的零并直接转换为字符串
			if(ans.startsWith("0")) {	//如果是0.xxxx...的形式
				ans = ans.substring(1);	//只去掉开头的零，保留小数点和小数点后的字符
			}
			System.out.println(ans);
		}
		in.close();
	}
}
