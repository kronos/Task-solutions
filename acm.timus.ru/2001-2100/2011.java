import java.io.*;
import java.util.*;

public class Main {
    private final Scanner in;
    private final PrintWriter out;

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

    void run() throws IOException {
        solve();
        out.flush();
    }

    void solve() throws IOException {
        int n = nextInt();
        int[] a = {0,0,0,0};
        int e;
        String answer = "No";
        Set<Integer> cuts = new HashSet<>();
        for (int i = 0; i < n; i++) {
            e = nextInt();
            a[e]++;
            cuts.add(e);
        }
        if (a[1] + a[2] + a[3] < n || n < 2) {
            answer = "No";
        } else if (n==2) {
            if (cuts.size() == 3) {
                answer = "Yes";
            }
        } else if (n < 6) {
            Integer idx[] = cuts.toArray(new Integer[cuts.size()]);
            if (cuts.size() == 3 || (cuts.size() == 2 && a[idx[0]] > 1 && a[idx[1]] > 1)) {
                answer = "Yes";
            }
        } else if (cuts.size() > 1) {
            answer = "Yes";
        }
        out.println(answer);
    }
}
