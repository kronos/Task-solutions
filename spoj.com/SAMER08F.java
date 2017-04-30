import java.io.*;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    void solve() throws IOException {
        int ans;
        int n = in.nextInt();
        while (n > 0) {
            ans = 0;
            for (int i = 0; i < n; i++) {
                ans += (n-i)*(n-i);
            }
            out.println(ans);
            n = in.nextInt();
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
