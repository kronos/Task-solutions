import java.io.*;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    void solve() throws IOException {
        int n = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = in.nextInt();
        }

        int pos = 0;
        int cnt = 0;
        for (int i = 1; (i <= 2500) && (pos < n); i++) {
            if (cnt < n && t[cnt] <= i) {
                cnt++;
                if (cnt-pos == a) {
                    int p = (cnt-pos) / 2 + (cnt-pos) % 2;
                    for (int j = 0; j < p; j++) {
                        out.printf("%d ", i);
                        pos++;
                    }
                }
            }

            if (cnt - pos > 0 && (i - t[pos]) >= b) {
                int p = (cnt-pos) / 2 + (cnt-pos) % 2;
                for (int j = 0; j < p; j++) {
                    out.printf("%d ", i);
                    pos++;
                }
            }
        }

        out.flush();
    }

    Main() {
        this.in = new FastScanner();//"input.txt");
        try {
            this.out = new PrintWriter(System.out);
        } catch (Exception e) {
            e.printStackTrace();
        }
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
                // TODO Auto-generated catch block
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
