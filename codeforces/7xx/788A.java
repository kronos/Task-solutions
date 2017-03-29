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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        long max(long a, long b) {
            return a > b ? a : b;
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = new long[n - 1];
            long x = in.nextLong(), y;
            for (int i = 1; i < n; i++) {
                y = in.nextLong();
                if (i % 2 == 0) {
                    a[i - 1] = -Math.abs(x - y);
                } else {
                    a[i - 1] = Math.abs(x - y);
                }

                x = y;
            }
            long ans = a[0];
            long sum = 0;
            for (int i = 0; i < n - 1; i++) {
                sum += a[i];
                ans = max(ans, sum);
                sum = max(sum, 0);
            }
            sum = 0;
            for (int i = 1; i < n - 1; i++) {
                sum += -a[i];
                ans = max(ans, sum);
                sum = max(sum, 0);
            }

            out.println(ans);
        }
    }
}
