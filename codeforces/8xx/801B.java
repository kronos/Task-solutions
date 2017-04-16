import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author kronos
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s1 = in.next();
            String s2 = in.next();
            boolean good = true;
            String s = "";
            int len = s1.length();
            for (int i = 0; (i < len) && good; i++) {
                if (s1.charAt(i) < s2.charAt(i)) {
                    good = false;
                } else {
                    s += s2.charAt(i);
                }
            }

            if (good) {
                out.print(s);
            } else {
                out.print(-1);
            }
        }

    }
}
