import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner (new BufferedInputStream(System.in));
        BigInteger a = in.nextBigInteger();
        BigInteger b = in.nextBigInteger();
        a = a.add(b);
        System.out.println(a);
        in.close();
    }
}
