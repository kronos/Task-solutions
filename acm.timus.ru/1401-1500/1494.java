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

    void run() throws IOException {
        solve();
        out.flush();
    }

    void solve() throws IOException {
        int n = nextInt(), e;
        boolean bad = false;
        Set<Integer> was = new HashSet<>();
        boolean[] proved = new boolean[n+1];
        int last = nextInt();
        was.add(last);
        for (int j = 1; j < n && !bad; j++) {
            e = nextInt();
            if (was.contains(e)) {
                bad = true;
            } else {
                was.add(e);
                if (last - e > 1) {
                    for (int i = e + 1; (i < last) && !bad && !proved[i]; i++) {
                        bad = !was.contains(i);
                    }
                    proved[e] = true;
                }
            }
            last = e;
        }

        if (bad || was.size() != n) {
            out.println("Cheater");
        } else {
            out.println("Not a proof");
        }
    }
}
