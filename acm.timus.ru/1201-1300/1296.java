import java.io.*;
import java.util.*;

public class Main {
    private final Scanner in;
    private final PrintWriter out;

    class Pair {
        public int left, right;
        Pair (int left, int right) {
            this.left = left;
            this.right = right;
        }
    }

    public Main() {
        in = new Scanner(System.in);
        out = new PrintWriter(new OutputStreamWriter(System.out));
    }

    public static void main(String[] args) throws IOException {
      new Main().run();
    }

    int nextInt() throws IOException {
        return in.nextInt();
    }

    String nextString() throws IOException {
        String s = in.next();
        return s.isEmpty() ? in.nextLine() : s;
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

    void run() throws IOException {
        solve();
        out.flush();
    }

    void solve() throws IOException {
        int n = nextInt();
        int e;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            e = nextInt();
            sum = max(sum, 0);
            sum += e;
            ans = max(ans, sum);
        }
        out.println(ans);
    }
}
