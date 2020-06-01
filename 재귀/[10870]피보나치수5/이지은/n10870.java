package beakjoon;

import java.util.Scanner;

public class n10870 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println(getResult(sc.nextInt()));
        sc.close();
    }
    static long getResult (long n) {
        if (n == 0 || n == 1) {
            return n;
        }
        return getResult(n-1) + getResult(n-2);
    }
}
