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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int w = in.nextInt();
            Friend[] f = new Friend[n];
            int sum = 0, q;
            for (int i = 0; i < n; i++) {
                f[i] = new Friend(in.nextInt(), i);
                sum += f[i].ans;
                w -= f[i].ans;
            }

            if (w < 0) {
                out.println(-1);
            } else {
                Arrays.sort(f, new Comparator<Friend>() {

                    public int compare(final Friend left, final Friend right) {
                        return left.a - right.a;
                    }
                });

                for (int i = n - 1; (i >= 0) && (w > 0); i--) {
                    q = Integer.min(f[i].left(), w);
                    f[i].ans += q;
                    w -= q;
                }

                Arrays.sort(f, new Comparator<Friend>() {

                    public int compare(final Friend left, final Friend right) {
                        return left.i - right.i;
                    }
                });

                for (int i = 0; i < n; i++) {
                    out.printf("%d ", f[i].ans);
                }
            }
            out.flush();
        }

        class Friend {
            public int a;
            public int ans;
            public int i;

            Friend(int a, int i) {
                this.a = a;
                this.ans = a / 2 + a % 2;
                this.i = i;
            }

            public int left() {
                return a - ans;
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

    }
}
