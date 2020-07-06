package beakjoon;

import java.io.*;

public class n10866 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        Deque d = new Deque();
        String[] arr;

        int N = Integer.parseInt(reader.readLine());

        for (int i=0; i < N; i++) {
            String text = reader.readLine();

            if (text.contains("push_front")) {
                arr =  text.split(" ");
                d.push_front(Integer.parseInt(arr[1]));
            } else if (text.contains("push_back")) {
                arr =  text.split(" ");
                d.push_back(Integer.parseInt(arr[1]));
            } else if (text.contains("pop_front")) {
                writer.write(d.pop_front() + "\n");
            } else if (text.contains("pop_back")) {
                writer.write(d.pop_back() + "\n");
            } else if (text.contains("size")) {
                writer.write(d.size() + "\n");
            } else if (text.contains("empty")) {
                writer.write((d.empty() ? 1 : 0) + "\n");
            } else if (text.contains("front")) {
                writer.write(d.front() + "\n");
            } else if (text.contains("back")) {
                writer.write(d.back() + "\n");
            }
        }

        reader.close();
        writer.flush();
        writer.close();
    }

    private static class Deque {

        Node frontNode;
        Node backNode;
        int size;

        Node currentNode; // 생성 노드.

        void push_front(int X) {
            if (size == 0) {
                this.currentNode = new Node(null, X, null);
                this.backNode = this.currentNode;
            } else {
                this.currentNode = new Node(null, X, frontNode);
                this.frontNode.prev = this.currentNode;
            }
            this.frontNode = this.currentNode;
            this.size++;
        }

        void push_back(int X) {
            if (size == 0) {
                this.currentNode = new Node(null, X, null);
                this.frontNode = this.currentNode;
            } else {
                this.currentNode = new Node(backNode, X, null);
                this.backNode.next = this.currentNode;
            }
            this.backNode = this.currentNode;
            this.size++;
        }

        int pop_front() {
            if (size == 0) {
                return -1; // 정수가 없는 경우
            }
            if (size == 1) {
                size--;
                return this.frontNode.n;
            }

            this.currentNode = this.frontNode;
            this.frontNode = currentNode.next;
            this.currentNode.next = null;
            this.frontNode.prev = null;

            size--;
            return this.currentNode.n;
        }

        int pop_back() {
            if (size == 0) {
                return -1; // 정수가 없는 경우
            }
            if (size == 1) {
                size--;
                return this.backNode.n;
            }

            this.currentNode = this.backNode;
            this.backNode = currentNode.prev;
            this.currentNode.prev = null;
            this.backNode.next = null;

            size--;
            return this.currentNode.n;
        }

        int size() {
            return this.size;
        }

        boolean empty() {
            return this.size == 0;
        }

        int front() {
            if (size == 0) {
                return -1; // 정수가 없는 경우
            }
            return this.frontNode.n;
        }

        int back() {
            if (size == 0) {
                return -1; // 정수가 없는 경우
            }
            return this.backNode.n;
        }

        private class Node {
            Node prev; // 앞 노드
            int n; // 노드가 가지고 있는 숫자
            Node next; // 뒷 노드

            public Node(Node prev, int n, Node next) {
                this.prev = prev;
                this.n = n;
                this.next = next;
            }
        }
    }
}
