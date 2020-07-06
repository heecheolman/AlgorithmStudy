package beakjoon;

import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class n1021 {

    static LinkedList<Integer> d;
    static int[] requestArr;
    static int sum = 0;
    static int N = 0; // 처음 큐의 크기
    static int M = 0; // 요청 숫자 크기

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int requestNum;

        N = sc.nextInt();
        M = sc.nextInt();

        d = new LinkedList<>();
        requestArr = new int[M];

        // 큐 1~N 까지 초기화
        settingDefaultArray(N);

        // Request Number List
        for(int i=0; i < M; i++) {
            requestArr[i] = sc.nextInt(); // TODO: 입력을 버퍼로 받아서 split해도 되는지 테스트
        }

        for(int i=0; i < M; i++) {
            sum += getCount(requestArr[i]);
        }
        System.out.println(sum);

        // reader.close();
        sc.close();
        writer.flush();
        writer.close();
    }

    static void settingDefaultArray(int N) {
        for(int i = 1; i <= N; i++) {
            d.offer(i);
        }
    }

    static int elementLocation(int requestNum) {
        int num = 0;
        while (d.size() > num) {
            if (requestNum == d.get(num)) return num + 1;
            num++;
        }
        return 0;
    }

    static boolean arrayContains(int n) {
        for (int i=0; i<M; i++) {
            if (requestArr[i] == n) return true;
        }
        return false;
    }

    static int getCount(int requestNum) {
        int count = 0;

        int requestNumLocation = elementLocation(requestNum);

        if (!d.isEmpty() && (d.size()/2) >= requestNumLocation) { // 2번 작업

            while (!d.isEmpty() && d.peekFirst() != requestNum) {
                int pollFirst = d.removeFirst(); // 1번
                if (d.isEmpty() || pollFirst == requestNum) {
                    return count;
                }
                if (arrayContains(requestNum)) {
                    d.addLast(pollFirst);
                    count++;
                }
            }
            d.removeFirst();
        } else { // 3번 작업
            while (!d.isEmpty() && d.peekLast() != requestNum) {
                int pollLast = d.removeLast(); // 1번
                count++;
                if (d.isEmpty() || pollLast == requestNum) {
                    return count;
                }
                if (arrayContains(requestNum)) {
                    d.addFirst(pollLast);
                }
            }
            d.removeLast();
        }

        return count;
    }
}