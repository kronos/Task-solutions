import java.io.*;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    int lcp_length(String a, String b) {
        if (a.length() > b.length()) {
            return lcp_length(b, a);
        }

        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                return i;
            }
        }

        return a.length();
    }

    void solve() throws IOException {
        String s = in.nextToken();
        String[] suffixes = new String[s.length()];
        for (int i = 0; i < s.length(); i++) {
            suffixes[i] = s.substring(i);
        }
        Arrays.sort(suffixes);
        long ans = suffixes[0].length();
        for (int i = 1; i < s.length(); i++) {
            ans += suffixes[i].length() - lcp_length(suffixes[i], suffixes[i-1]);
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
