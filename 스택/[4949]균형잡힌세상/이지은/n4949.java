package beakjoon;

import java.io.*;
import java.util.Stack;

public class n4949 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Character> stack = new Stack<>();

        while(true) {
            stack.removeAllElements();
            String sentence = reader.readLine();
            if (sentence.equals(".")) {
                break;
            }
            for (char c : sentence.toCharArray()) {
                // char c = sentence.charAt(i);
                boolean isNotBlanck = c != '(' &&  c != ')' && c != '[' && c != ']';
                boolean isStart = c == '(' || c == '[';
                boolean isNotCouple = (stack.peek() != '(' && c == ')') || (stack.peek() != '[' && c == ']');

                if (isNotBlanck) {
                    continue;
                }
                if (isStart) { // 열림괄호
                    stack.push(c);
                    continue;
                }
                // 닫힘괄호
                if (stack.empty() || isNotCouple) {
                    stack.push('('); // * 방어코드 *
                    break;
                }
                stack.pop();
            }

            System.out.println(stack.empty() ? "yes" : "no");
        }

        reader.close();
        writer.flush();
        writer.close();
    }
}
