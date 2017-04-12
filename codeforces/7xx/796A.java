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
            int m = in.nextInt() - 1;
            int k = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            int left = 1000000;
            int right = 1000000;
            for (int i = m - 1; i >= 0; i--) {
                if (a[i] > 0 && a[i] <= k) {
                    left = (m - i) * 10;
                    break;
                }
            }

            for (int i = m + 1; i < n; i++) {
                if (a[i] > 0 && a[i] <= k) {
                    right = (i - m) * 10;
                    break;
                }
            }

            out.println(left < right ? left : right);
        }

    }
}
