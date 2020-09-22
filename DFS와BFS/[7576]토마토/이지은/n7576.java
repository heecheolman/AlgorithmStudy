package beakjoon;

import java.util.*;
import java.util.Queue;
import java.util.concurrent.atomic.AtomicInteger;

public class n7576 {
    static int[] dy = {0, 0, -1, 1};
    static int[] dx = {-1, 1, 0, 0};

    static int underripeTomatoesCount = 0; // 덜 익은 토마토
    static int ripeTomatoesCount = 0; // 익은 토마토
    static int[][] tomatoBox;
    static Queue<int[]> tomatoQueue = new LinkedList<>();
    static int M;
    static int N;
    static int x;
    static int y;
    static int aroundX;
    static int aroundY;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] inputArr = Arrays.stream(sc.nextLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();

        M = inputArr[0]; // 상자의 가로
        N = inputArr[1]; // 상자의 세로
        int[] inputLine;

        tomatoBox =  new int[N][M];

        for (int i = 0; i < N; i++) {
            inputLine = Arrays.stream(sc.nextLine().split(" "))
                    .mapToInt(Integer::parseInt).toArray();

            tomatoBox[i] = inputLine;

            for (int j = 0; j < M; j++) {
                if (inputLine[j] == 0) {
                    underripeTomatoesCount += 1;
                } else if (inputLine[j] == 1) {
                    ripeTomatoesCount += 1;
                    tomatoQueue.offer(new int[]{i, j});
                }

            }
        }

        System.out.println(necessaryPeriod());
    }

    /*
        1 : 익은 토마토
        0 : 익지 않은 토마토
        -1 : 토마토가 없는 칸

        M : 상자의 가로
        N : 상자의 세로
    */

    static int necessaryPeriod() {
        int day = 0;
        int oneDayTomatoSize = tomatoQueue.size();

        if (underripeTomatoesCount == 0 && ripeTomatoesCount == 0) {
            return 0;
        } else if (underripeTomatoesCount == 0) {
            return 0;
        } else if (ripeTomatoesCount == 0) {
            return -1;
        }

        while (!tomatoQueue.isEmpty()) {
            oneDayTomatoSize -= 1;

            x = tomatoQueue.peek()[0];
            y = tomatoQueue.peek()[1];
            tomatoQueue.poll();

            for (int i = 0; i < 4; i ++) {
                aroundX = x + dx[i];
                aroundY = y + dy[i];

                if (
                        aroundX >= 0 && aroundY >= 0 && aroundX < N && aroundY < M
                        && tomatoBox[aroundX][aroundY] == 0
                ) {
                    tomatoBox[aroundX][aroundY] = 1;
                    tomatoQueue.offer(new int[]{aroundX, aroundY});
                }
            }

            if (tomatoQueue.isEmpty()) {
                break;
            }

            if (oneDayTomatoSize == 0) {
                day += 1;
                oneDayTomatoSize = tomatoQueue.size();
            }
        }

        AtomicInteger containZero = new AtomicInteger();

        Arrays.stream(tomatoBox).forEach(
                line -> containZero.addAndGet((int) Arrays.stream(line).filter(tomato -> tomato == 0).count()));

        return containZero.get() > 0 ? -1 : day;
    }
}
