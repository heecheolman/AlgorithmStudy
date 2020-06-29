package beakjoon;

import java.util.LinkedList;
import java.util.Queue;
import java.io.*;

public class n2164 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(reader.readLine());

        writer.write(getLastNumber(N) + "\n");

        writer.flush();
        writer.close();
        reader.close();
    }

    static int getLastNumber(int N) {
        if (N == 1) {
            return 1;
        }
        Queue<Integer> q = new LinkedList<>();

        // for (int i=2; i<=N; i = i+2) { // 2부터 짝수만 큐에 넣는다. 실패. 왜 안될까?
            // q.offer(i);
        // }
        for(int i=1; i<=N; i++) {
            q.offer(i);
        }

        while(q.size() > 1) {
                q.poll();
                q.offer(q.poll());
        }

        return q.poll();
    }
}