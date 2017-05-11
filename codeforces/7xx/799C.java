import java.io.*;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;
    Tuple[] fc, fd;
    int cntc, cntd;

    public class Tuple {
        public final int b;
        public final int p;
        public Tuple(int b, int p) {
            this.b = b;
            this.p = p;
        }
    }

    int findMaxInC(int to, int price) {
        int l = -1;
        int r = to;
        int mid;
        while (r-l > 1) {
            mid = (r+l) >>> 1;
            if (fc[mid].p <= price) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return l;
    }

    int findMaxInD(int to, int price) {
        int l = -1;
        int r = to;
        int mid;
        while (r-l > 1) {
            mid = (r+l) >>> 1;
            if (fd[mid].p <= price) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return l;
    }

    void solve() throws IOException {
        int n = in.nextInt();
        int c = in.nextInt();
        int d = in.nextInt();
        int ans = 0;
        fc = new Tuple[n];
        fd = new Tuple[n];
        cntc = cntd = 0;
        int b, p, maxc = 0, maxd = 0;
        for (int i = 0; i < n; i++) {
            b = in.nextInt();
            p = in.nextInt();
            if (in.nextToken().charAt(0) == 'D') {
                if (p <= d) {
                    maxd = Integer.max(maxd, b);
                    fd[cntd++] = new Tuple(b, p);
                }
            } else {
                if (p <= c) {
                    maxc = Integer.max(maxc, b);
                    fc[cntc++] = new Tuple(b, p);
                }
            }
        }
        Arrays.sort(fc, 0, cntc, new Comparator<Tuple>() {
            @Override
            public int compare(final Tuple left, final Tuple right) {
                return left.p - right.p;
            }
        });

        Arrays.sort(fd, 0, cntd, new Comparator<Tuple>() {
            @Override
            public int compare(final Tuple left, final Tuple right) {
                return left.p - right.p;
            }
        });

        if (cntc + cntd >= 2) {
            int[] beautyC;
            int[] beautyD;
            int idx;

            if (cntc > 1) {
                beautyC = new int [cntc];
                beautyC[0] = fc[0].b;
                for (int i = 1; i < cntc; i++) {
                    beautyC[i] = Integer.max(fc[i].b, beautyC[i-1]);
                }

                for (int i = cntc-1; i > 0; i--) {
                    idx = findMaxInC(i, c - fc[i].p);
                    if (idx > -1) {
                        ans = Integer.max(ans, fc[i].b + beautyC[idx]);
                    }
                }
            }

            if (cntd > 1) {
                beautyD = new int [cntd];
                beautyD[0] = fd[0].b;
                for (int i = 1; i < cntd; i++) {
                    beautyD[i] = Integer.max(fd[i].b, beautyD[i-1]);
                }

                for (int i = cntd-1; i > 0; i--) {
                    idx = findMaxInD(i, d - fd[i].p);
                    if (idx > -1) {
                        ans = Integer.max(ans, fd[i].b + beautyD[idx]);
                    }
                }
            }


            if (cntc > 0 && cntd > 0) {
                ans = Integer.max(ans, maxc + maxd);
            }
        }

        out.println(ans);
        out.flush();
    }

    Main() {
        this.in = new FastScanner();
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
