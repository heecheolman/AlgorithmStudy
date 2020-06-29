package beakjoon;

import java.io.*;

public class n18258 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        Queue queue = new Queue();

        int N = Integer.parseInt(reader.readLine());

        for (int i = 0; i < N; i++) {
            String line = reader.readLine();
            if (line.contains("push")) {
                String[] arr =  line.split(" ");
                queue.push(Integer.parseInt(arr[1]));
            } else if (line.contains("pop")) {
                writer.write(queue.pop() + "\n");
            } else if (line.contains("size")) {
                writer.write(queue.size() + "\n");
            } else if (line.contains("empty")) {
                writer.write(queue.empty() + "\n");
            } else if (line.contains("front")) {
                writer.write(queue.front() + "\n");
            } else if (line.contains("back")) {
                writer.write(queue.back() + "\n");
            }
            // writer.newLine();;
            // writer.flush();
        }
        writer.flush();
        reader.close();
        writer.flush();
        writer.close();
    }
}


class Queue {
    // LinkedList<Integer> q = new LinkedList<>();
    int size = 0;
    Node firstN;
    Node lastN;
    // Node currentN;

    void push(int n) {
        if (size == 0) {
            this.firstN = new Node(null, n, null);
            this.lastN = this.firstN;
        } else {
            Node newN = new Node(lastN, n, null);
            this.lastN.nextN = newN;
            this.lastN = newN;
        }
        this.size ++;
    }
    int pop() {
        if (size == 0) {
            return -1;
        }

        this.size--;
        int n = this.firstN.num;
        Node newFirstN = this.firstN.nextN;

        if (newFirstN == null) {
            return n;
        }
        
        newFirstN.prevN = null; // 바로 뒷 노드에서 맨 앞 노드로의 연결 제거
        this.firstN.nextN = null; // 맨 앞노드에서 뒷 노드로의 연결 제거
        this.firstN = newFirstN;

        return n;
    }
    int size() {
        return this.size;
    }
    int empty() {
        return this.size > 0 ? 0 : 1;
    }
    int front() {
        if (size == 0) {
            return -1;
        }
        return this.firstN.num;
    }
    int back() {
        if (size == 0) {
            return -1;
        }
        return this.lastN.num;
    }

    static class Node {
        Node prevN;
        int num;
        Node nextN;

        Node (Node prevN, int num, Node nextN) {
            this.prevN = prevN;
            this.num = num;
            this.nextN = nextN;
        }
    }
}