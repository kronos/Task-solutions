import java.io.*;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;
    int primes[];
    int size = 0;

    boolean isPrime(int n) {
        int to = (int)Math.sqrt(n);
        for(int i = 0; primes[i] <= to; i++) {
            if (n % primes[i] == 0) {
                return false;
            }
        }

        return true;
    }

    void solve() throws IOException {
        primes = new int[3402];
        primes[0] = 2; primes[1] = 3;
        size = 2;
        for (int i = 5; i <= 31627; i+= 2) {
            if (isPrime(i)) {
                primes[size++] = i;
            }
        }

        int n, m;
        for(int t = in.nextInt(); t > 0; t--) {
            n = Integer.max(in.nextInt(), 2);
            m = in.nextInt();
            if (n < 3) {
                n = 3;
                if (m >= 2) {
                    out.println(2);
                }
            } else if (n % 2 == 0) {
                n++;
            }

            for (int i = n; i <= m; i += 2) {
                if (isPrime(i)) {
                    out.println(i);
                }
            }
            out.println();
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
