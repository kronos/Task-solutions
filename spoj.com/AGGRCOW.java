import java.io.*;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;
    int n, c;
    int []a;

    boolean check(int d) {
        int prev = a[0];
        int l, r, mid;
        int left = c-1;
        for (int i = 1; (left > 0) && (left <= n-i); i++) {
            l = i-1;
            r = n;
            while (r-l > 1) {
                mid = (l + r) >>> 1;
                if (a[mid] - prev >= d) {
                    r = mid;
                } else {
                    l = mid;
                }
            }

            if (r < n && a[r] - prev >= d) {
                prev = a[r];
                i = r;
                left--;
            } else {
                break;
            }
        }

        return left == 0;
    }

    void solve() throws IOException {
        int r, l, mid;
        a = new int[100000];
        for (int t = in.nextInt(); t > 0; t--) {
            n = in.nextInt();
            c = in.nextInt();
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a, 0, n);
            l = -1;
            r = a[n-1] - a[0] + 1;
            while (r - l > 1) {
                mid = (l + r) >>> 1;
                if (check(mid)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            out.println(l);
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
