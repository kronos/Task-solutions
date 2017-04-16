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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s = in.next();
            int len = s.length();
            s = s + "_";
            boolean changed = false;
            int answer = 0;
            boolean[] used = new boolean[105];
            for (int i = 1; i < len; i++) {
                if (s.charAt(i - 1) == 'V' && s.charAt(i) == 'K') {
                    answer++;
                    used[i - 1] = true;
                    used[i] = true;
                } else if (s.charAt(i) == 'K' && !used[i - 1] && !changed) {
                    changed = true;
                    answer++;
                } else if (s.charAt(i - 1) == 'V' && !changed && s.charAt(i + 1) != 'K') {
                    answer++;
                    changed = true;
                }
            }
            out.print(answer);
        }

    }
}
