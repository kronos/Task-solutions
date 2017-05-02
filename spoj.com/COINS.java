import java.io.*;
import java.util.*;

public class Main {
    private Scanner in;
    private PrintWriter out;
    Map<Integer, Long> m;

    long gold(int n) {
        Long ans = m.get(n);

        if (ans == null) {
            ans = Long.max(n, gold(n/2) + gold(n/3) + gold(n/4));
            m.put(n, ans);
        }

        return ans;
    }

    void solve() throws IOException {
        m = new HashMap<>();
        m.put(0, 0L);
        m.put(1, 1L);

        while (in.hasNextInt()) {
            out.println(gold(in.nextInt()));
        }

        out.flush();
    }

    Main() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);
    }

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}
