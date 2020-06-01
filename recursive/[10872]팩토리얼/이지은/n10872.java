package beakjoon;

import java.util.Scanner;

public class n10872 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println(getResult(sc.nextInt()));
        sc.close();
    }
    static long getResult (long n) {
        if (n == 1 || n == 0) {
            return 1;
        }
        return n * getResult(n-1);
    }
}
