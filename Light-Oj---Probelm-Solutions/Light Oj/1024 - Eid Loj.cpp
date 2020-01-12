
import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

class eid {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int ts = sc.nextInt();
        for(int p = 1; p <= ts; p++){
            int n = sc.nextInt();
            BigInteger ans = sc.nextBigInteger();
            BigInteger ans2 = sc.nextBigInteger();
            BigInteger pre = (ans.multiply(ans2)).divide(ans.gcd(ans2));
            for(int i = 2; i <n; i++){
                BigInteger num = sc.nextBigInteger();
                pre = (pre.multiply(num)).divide(pre.gcd(num));
            }
            System.out.println("Case "+p+": "+pre);System.gc();
        }
    }

}

