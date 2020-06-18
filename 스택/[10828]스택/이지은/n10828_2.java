package beakjoon;

import java.util.Scanner;


public class n10828_2 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Stack stack = new Stack(new int[10000]);
        int N = sc.nextInt();

        for (int i=0; i<=N; i++) {
            String message = sc.nextLine();

            if (message.contains("push")) {
                String[] pushArr = message.split(" ");
                stack.push(Integer.parseInt(pushArr[1]));
            } else if (message.contains("pop")) {
                System.out.println(stack.pop());
            } else if (message.contains("size")) {
                System.out.println(stack.size());
            } else if (message.contains("empty")) {
                System.out.println(stack.empty());
            } else if (message.contains("top")) {
                System.out.println(stack.top());
            }
        }

        sc.close();
    }
}

class Stack {
    int[] arr;
    int size=0;

    public Stack (int[] arr) {
        this.arr = arr;
    }

    void push(int num) {
        arr[size] = num;
        size++;
    }

    int pop() {
        if (size == 0) {
            return -1;
        }
        size--;
        int n = arr[size];
        return n;
    }

    int size() {
        return size;
    }

    int empty() {
        if (size == 0) {
            return 1;
        }
        return 0;
    }

    int top() {
        if (size == 0) {
            return -1;
        }
        return arr[size-1];
    }
}