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
			String ans = res.stripTrailingZeros().toPlainString();	//ȥ��С����ͺ��������㲢ֱ��ת��Ϊ�ַ���
			if(ans.startsWith("0")) {	//�����0.xxxx...����ʽ
				ans = ans.substring(1);	//ֻȥ����ͷ���㣬����С�����С�������ַ�
			}
			System.out.println(ans);
		}
		in.close();
	}
}
