import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    void solve() throws IOException {
        String s = in.nextString();
        StringBuffer t = new StringBuffer("");
        StringBuffer u = new StringBuffer("");
        Map<Character, Integer> rightmostPos = new HashMap<>();
        char c;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            rightmostPos.put(s.charAt(i), i);
        }

        for (int i = 0; i < len; i++) {
            c = s.charAt(i);
            if (t.length() == 0 || t.charAt(t.length() - 1) > c) {
                t.append(c);
            } else {
                boolean lowerToCome = false;
                char top = t.charAt(t.length() - 1);
                for (char j = 'a'; (j < top) && !lowerToCome; j++) {
                    lowerToCome = rightmostPos.getOrDefault(j, 0) > i;
                }

                while (!lowerToCome && t.length() > 0 && t.charAt(t.length() - 1) <= c) {
                    String tmp = t.toString();
                    int idx = tmp.length() -1;
                    while (idx >= 0 && tmp.charAt(idx) <= top ) {
                        idx--;
                    }

                    for (int j = tmp.length() - 1; j > idx; j--) {
                        u.append(t.charAt(j));
                    }

                    if (idx < 0) {
                        t.replace(0, t.length(), "");
                    } else {
                        t.replace(idx+1, t.length(), "");
                    }

                    if (t.length() > 0) {
                        top = t.charAt(t.length() - 1);
                        for (char j = 'a'; (j < top) && !lowerToCome; j++) {
                            lowerToCome = rightmostPos.getOrDefault(j, 0) > i;
                        }
                    }
                }
                t.append(c);
            }
        }

        for (int i = t.length() - 1; i >= 0; i--) {
            u.append(t.charAt(i));
        }
        out.println(u.toString());
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
