
import java.util.Scanner;

public class n2292 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println(getStep(sc.nextInt()));
    }
    static int getStep(int n) {
        int step = 1;
        int lastNumber = 1;
        while (n > lastNumber) {
            lastNumber += 6*(step);
            step++;
        }
        return step;
    }
}
