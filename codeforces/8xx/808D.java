import java.io.*;
import java.util.*;

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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = new long[n];
            long all = 0, d, sum = 0;
            boolean good = false;
            for (int i = 0; i < n; i++) {
                a[i] = in.nextLong();
                all += a[i];
            }

            if (n > 1 && all % 2 == 0) {
                Map<Long, Integer> l = new HashMap<>();
                Map<Long, Integer> r = new HashMap<>();
                l.put(a[0], 1);
                for (int i = 1; i < n; i++) {
                    r.put(a[i], r.getOrDefault(a[i], 0) + 1);
                }

                for (int i = 0; i < n && !good; i++) {
                    sum += a[i];
                    if (i > 0) {
                        l.put(a[i], l.getOrDefault(a[i], 0) + 1);
                        r.put(a[i], r.getOrDefault(a[i], 0) - 1);
                    }
                    d = all - 2 * sum;
                    if (d > 0) {
                        good = d % 2 == 0 && r.getOrDefault(d / 2, 0) > 0;
                    } else if (d < 0) {
                        good = d % 2 == 0 && l.getOrDefault(-d / 2, 0) > 0;
                    } else {
                        good = true;
                    }
                }
            }

            if (good) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
