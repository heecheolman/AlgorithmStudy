package beakjoon;

import java.io.*;
import java.util.*;
import java.util.Stack;

public class n2606 {

    static Stack<Integer> stack = new Stack<>();
//    static int[] graph = new int[101];
//    static int[][] graph = new int[101][100];
    static List<List<Integer>> graph = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        // graph 빈배열로 초기화
        for (int i=0; i <= 100; i++) {
            graph.add(new ArrayList<>());
        }

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int computerCount = Integer.parseInt(reader.readLine());
        int linkedCount = Integer.parseInt(reader.readLine());

        int currentNode;
        List<Integer> linkedNodes;
        int virus = -1;

        // graph의 index는 각 컴퓨터를 지칭.
        // index의 값은 연결된 모든 컴퓨터 숫자를 가진 배열.
        for (int i = 0; i < linkedCount; i++) {
            String input = reader.readLine();
            int[] couple = Arrays.stream(input.split(" "))
                    .mapToInt(Integer::parseInt).toArray();
            setLinkedComputer(couple[0], couple[1]);
        }

        stack.push(1);

        while (!stack.isEmpty()) {
            virus += 1;
            currentNode = stack.pop();

            linkedNodes = graph.get(currentNode);

            for (Integer linkedNode : linkedNodes) {
                if (!stack.contains(linkedNode)) {
                    stack.push(linkedNode);
                }
                graph.get(linkedNode).remove((Integer) currentNode);
            }
        }

        writer.write(virus + "\n");
        writer.flush();

        reader.close();
        writer.close();
    }
    static void setLinkedComputer (int a, int b) {
        graph.get(a).add(b);
        graph.get(b).add(a);
    }
}
