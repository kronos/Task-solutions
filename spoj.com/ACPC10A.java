import java.io.*;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    void solve() throws IOException {
        int a1 = in.nextInt();
        int a2 = in.nextInt();
        int a3 = in.nextInt();
        int d;

        while (a1 != 0 || a2 != 0 || a3 != 0) {
            if (a3 == 0 || a2 == 0 || a1 == 0) {
                out.printf("AP %d\n", 2 * a3 - a2);
            } else if (a1+a3 == 2*a2) {
                out.printf("AP %d\n", 2 * a3 - a2);
            } else if (a2 % a1 == 0 && a3 % a2 == 0 && a2/a1 == a3/a2) {
                d = a2 / a1;
                out.printf("GP %d\n", a3 * d);
            } else if (a1 % a2 == 0 && a2 % a3 == 0 && a1/a2 == a2/a3) {
                d = a1/a2;
                out.printf("GP %d\n", a3/d);
            }
            a1 = in.nextInt();
            a2 = in.nextInt();
            a3 = in.nextInt();
        }
        out.flush();
    }

    Main() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
    }

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        public String nextString() { return nextToken(); }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }
}
