import java.io.*;
import java.net.Inet4Address;
import java.util.*;
import java.util.concurrent.ArrayBlockingQueue;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    void solve() throws IOException {
        int n = in.nextInt();
        int l = in.nextInt();
        int r = in.nextInt();
        int[] a = new int[n];
        long ans = 0, m;
        Set<Integer> s = new HashSet<>();
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        for (int i = 0; i < n; i++) {
            if (s.contains(a[i])) {
                if (q.size() >= l) {
                    m = Integer.min(q.size(), r);
                    ans += (2*q.size()-l-m+2) * (m-l+1)/2;
                }

                while (q.peek() != a[i]) {
                    s.remove(q.peek());
                    q.poll();
                }
                q.poll();
                if (q.size() >= l) {
                    m = Integer.min(q.size(), r);
                    ans -= (2*q.size()-l-m+2) * (m-l+1)/2;
                }
                q.add(a[i]);
            } else {
                q.add(a[i]);
                s.add(a[i]);
            }
        }

        if (q.size() >= l) {
            m = Integer.min(q.size(), r);
            ans += (2*q.size()-l-m+2) * (m-l+1)/2;
        }

        out.println(ans);
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
