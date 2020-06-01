import java.util.Scanner;

public class n10250 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T, H, W, N, Y, X;
        T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            H = sc.nextInt();
            W = sc.nextInt();
            N = sc.nextInt();

            Y = (int) Math.ceil((double) N / (double)H);
            X = N - (H * (Y -1));

            System.out.println(X * 100 + Y);
        }
    }
}