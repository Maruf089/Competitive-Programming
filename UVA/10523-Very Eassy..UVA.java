import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while(s.hasNextInt()){
         int N = s.nextInt();
         int K = s.nextInt();
         BigInteger sum = BigInteger.ZERO;
         BigInteger A = BigInteger.valueOf(K);
            for (int i = 1; i <=N; i++)
               sum = sum.add(BigInteger.valueOf(i).multiply(A.pow(i)));
            System.out.println(sum);
        }
    }
}
