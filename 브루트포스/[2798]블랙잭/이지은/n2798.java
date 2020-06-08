
import java.util.Scanner;

public class n2798 {
    public static void main(String[] args) {
        int N, M;
        int[] arr;
        int a, b, c, max, sum;
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt(); // 카드의 개수
        M = sc.nextInt(); // 비교 대상 수
        max = 0;

        arr = new int[N];
        
        for (int i=0; i<N; i++) {
            arr[i] = sc.nextInt();
        }

        for (int i=0; i<N; i++) {
            a = arr[i];
            for (int j=i+1; j<N; j++) {
                b = arr[j];
                for (int k=j+1; k<N; k++) {
                    c = arr[k];
                    sum = a+b+c;
                    if (sum <= M && sum > max) {
                        max = sum;
                    }
                }
            }
        }

        System.out.println(max);

        sc.close();
    }
}