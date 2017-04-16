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
            int n = in.nextInt();
            int k = in.nextInt();
            int[] ans = new int[k];
            int cnt = 1;
            for (int i = 2; (i <= n / 2) && (cnt < k); i++) {
                while (n % i == 0 && n > 1 && cnt < k) {
                    ans[cnt++] = i;
                    n /= i;
                }
            }
            ans[0] = n;
            if (cnt == k && n > 1) {
                for (int i = 0; i < k; i++) {
                    out.printf("%d ", ans[i]);
                }
            } else {
                out.print(-1);
            }
        }

    }
}
