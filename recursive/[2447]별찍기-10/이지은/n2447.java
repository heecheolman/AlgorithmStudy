package beakjoon;

import java.util.Arrays;
import java.util.Scanner;

public class n2447 {
    static char[][] arr;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        arr = new char[N][N];
        StringBuilder result = new StringBuilder();

        // 빈 칸으로 기본 배열 세팅
        for (int i=0; i< N; i++) {
            Arrays.fill(arr[i], ' ');
        }

        // 반복되는 패턴의 모양 구하기
        getPattern(0, 0, N);

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                // System.out.print(arr[i][j]);
                result.append(arr[i][j]);
            }
            result.append('\n');
        }
        System.out.println(result);
        sc.close();
    }

    static void getPattern (int x, int y, int N) {
        if (N == 1) {
            arr[x][y] = '*';
        } else {
            for (int i=0; i<3; i++) {
                for (int j=0; j<3; j++) {
                    if (i != 1 || j != 1) {
                        getPattern(x+(i*(N/3)),y+( j*(N/3)), N/3);
                    }
                }
            }
        }
    }
}
