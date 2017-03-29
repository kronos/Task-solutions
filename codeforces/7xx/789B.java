import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

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
            long b1 = in.nextLong();
            long q = in.nextLong();
            long l = in.nextLong();
            int m = in.nextInt();
            long e;
            String answer;

            if (Math.abs(b1) > l) {
                answer = "0";
            } else if (b1 == 0) {
                boolean zero = false;
                for (int i = 0; (i < m) && !zero; i++) {
                    zero = in.nextInt() == 0;
                }

                if (zero) {
                    answer = "0";
                } else {
                    answer = "inf";
                }
            } else if (q == 0) {
                boolean zero = false;
                boolean b1_present = false;
                for (int i = 0; (i < m); i++) {
                    e = in.nextInt();
                    zero |= e == 0;
                    b1_present |= e == b1;
                }

                if (zero) {
                    if (b1_present) {
                        answer = "0";
                    } else {
                        answer = "1";
                    }
                } else {
                    answer = "inf";
                }
            } else if (Math.abs(q) == 1) {
                boolean has_minus = q < 0 || b1 < 0;
                boolean no_one = false;
                boolean no_minus_one = false;

                for (int i = 0; (i < m); i++) {
                    e = in.nextInt();
                    no_one |= e == Math.abs(b1);
                    no_minus_one |= e == -Math.abs(b1);
                }

                if (has_minus) {
                    if (q < 0) {
                        if (no_one && no_minus_one) {
                            answer = "0";
                        } else {
                            answer = "inf";
                        }
                    } else {
                        if (no_minus_one) {
                            answer = "0";
                        } else {
                            answer = "inf";
                        }
                    }
                } else {
                    if (no_one) {
                        answer = "0";
                    } else {
                        answer = "inf";
                    }
                }
            } else {
                long ans;
                Set<Long> values = new HashSet<>();
                values.add(b1);
                e = b1 * q;
                while (Math.abs(e) <= l) {
                    values.add(e);
                    e = e * q;
                }
                ans = values.size();
                for (int i = 0; (i < m) && (ans > 0); i++) {
                    e = in.nextLong();
                    if (values.contains(e)) {
                        ans--;
                        values.remove(e);
                    }
                }
                answer = Long.toString(ans);
            }
            out.println(answer);
        }

    }
}
