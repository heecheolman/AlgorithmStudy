package beakjoon;

import java.io.*;
import java.util.Collections;
import java.util.LinkedList;

public class n5430 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(reader.readLine());
        LinkedList<Integer> list;

        for (int i=1; i <= T; i++) {
            list = new LinkedList<>();
            char[] function = reader.readLine().toCharArray(); // 함수
            int n = Integer.parseInt(reader.readLine());
            String[] arr = reader.readLine()
                    .replace("[", "")
                    .replace("]","")
                    .split(",");

            if (isError(function, n)) {
                writer.write("error" + "\n");
                continue;
            }

            if (arr[0].equals("")) {
                writer.write(formatResult(list) + "\n");
                continue;
            }

            for (String s : arr) {
                list.offer(Integer.parseInt(s));
            }

            boolean isReverse = false;
            for (char c : function) {
                if (c == 'R') {
                    isReverse = !isReverse;
                } else if (c == 'D') {
                    if (isReverse) {
                        list.pollLast();
                    } else {
                        list.poll();
                    }
                }
            }

            if (isReverse) {
                Collections.reverse(list);
            }
            writer.write(formatResult(list) + "\n");
        }

        reader.close();
        writer.flush();
        writer.close();
    }

    private static String formatResult(LinkedList<Integer> list) {
        StringBuilder format = new StringBuilder();

        format.append("[");
        list.forEach(element -> format.append(element).append(","));
        format.append("]");

        return format.toString().replace(",]", "]");
    }

    private static boolean isError(char[] p, int n) {
        int count = 0;

        for (char s : p) {
            if (s == 'D') {
                count++;
            }
        }

        return n < count;
    }

}
