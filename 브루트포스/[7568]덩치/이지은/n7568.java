package beakjoon;

import java.util.Scanner;

public class n7568 {
    public static void main(String[] args) {
        int[][] people;
        int[] rank;
        int size;

        Scanner sc = new Scanner(System.in);

        size = sc.nextInt();
        people = new int[size][2];
        rank = new int[size];

        for (int i=0; i<size; i++) {
            people[i][0] = sc.nextInt();
            people[i][1] = sc.nextInt();
        }

        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                if (i != j && people[i][0] > people[j][0] && people[i][1] > people[j][1]) {
                    // i != j : 같은 사람을 비교하지 않아 도 되기 때문에 제외.
                    rank[j]++; // 작은 덩치에 +1 해줘서 등수를 밀리게 한다.
                }
            }
        }

        StringBuilder result = new StringBuilder();

        for (int i=0; i<size; i++) {
            result.append(rank[i]+1); // 배열이 1이아닌 0으로 초기화 되기 때문에 +1 해준다 
            if (i != size-1) {
                result.append(" ");
            }
        }

        System.out.println(result);

        sc.close();
    }
}