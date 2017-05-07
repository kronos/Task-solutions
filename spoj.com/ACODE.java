import java.io.*;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    void solve() throws IOException {
        String s = in.nextString();
        long ans;
        long doubled, q;
        int cur, prev;
        while (!s.equals("0")) {
            ans = 1;
            doubled = 0;
            prev = s.charAt(0) - '0';
            for (int i = 1; i < s.length(); i++) {
                cur = s.charAt(i) - '0';
                if (cur == 0) {
                    ans -= doubled;
                    doubled = ans;
                } else if (prev*10 + cur <= 26) {
                    q = (ans - doubled);
                    ans += q;
                    doubled = q;
                } else {
                    doubled = 0;
                }
                prev = cur;
            }
            s = in.nextString();
            out.println(ans);
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
