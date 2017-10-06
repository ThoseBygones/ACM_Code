import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		try{
			Scanner in = new Scanner(new File("input.txt"));
			FileWriter out = new FileWriter(new File("output.txt"));
			BigInteger a = BigInteger.valueOf(2);	//��ŵ���ĵ���
			while(in.hasNext()){
				int n = in.nextInt();
				BigInteger ans = BigInteger.valueOf(0);	//��¼�𰸵ı���
				if(n % 2 == 0)
					ans = (a.pow(2 * n / 3 - 1)).add(a.pow(n / 3 - 1)).subtract(BigInteger.valueOf(1));
				else
					ans = (a.pow(2 * n / 3 - 1)).add(a.pow(n / 3)).subtract(BigInteger.valueOf(2));
				out.write(ans.toString()+"\r\n");
				//out.write("\n");
			}
			in.close();
			out.close();
		}catch(Exception e){
		
		}
	}
}
