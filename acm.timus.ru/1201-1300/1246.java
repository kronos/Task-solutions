import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author kronos
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task1246 solver = new Task1246();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1246 {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt() - 1;
            long z = 0, fx, fy;
            long x1, y1, x2 = 0, y2 = 0;//,x3,y3;
            fx = x1 = in.nextLong();
            fy = y1 = in.nextLong();
            while (n > 0) {
                x2 = in.nextLong();
                y2 = in.nextLong();
                z += x1 * y2 - x2 * y1;
                x1 = x2;
                y1 = y2;
                n--;
            }

            z += x2 * fy - fx * y2;

            if (z < 0) {
                out.println("cw");
            } else {
                out.println("ccw");
            }
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
