package beakjoon;

import java.util.Scanner;

public class n9012 {

    static Stack stack;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();

        for (int i=0; i<N; i++) {
            String text = sc.nextLine();
            System.out.println(isVps(text) ? "YES" : "NO");
        }
        sc.close();
    }
    
    // 올바른 괄호 문자열인지 판단하는 메서드
    public static boolean isVps(String text) {
        int j = 0;
        boolean isVps = true;
        stack = new Stack(new char[text.length()]);

        while(isVps && text.length() > j) {
            if (text.charAt(j) == '(') {
                stack.push(text.charAt(j));
            } else { // = ")"
                if (stack.top() == '(') {
                    stack.pop();
                } else {
                    isVps = false;
                    break;
                }
            }
            j++;
        }

        if (stack.size > 0) {
            isVps = false;
        }

        return isVps;
    }
}

class Stack {
    char[] arr;
    int size=0;

    public Stack (char[] arr) {
        this.arr = arr;
    }

    void push(char bracket) {
        arr[size] = bracket;
        size++;
    }

    char pop() {
        if (size == 0) {
            return 'n';
        }
        size--;
        return arr[size];
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

    char top() {
        if (size == 0) {
            return 'n';
        }
        return arr[size-1];
    }
}