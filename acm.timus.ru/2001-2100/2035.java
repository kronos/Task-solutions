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
        int x = nextInt();
        int y = nextInt();
        int c = nextInt();
        int a,b;
        if (x+y < c) {
            out.println("Impossible");
        } else {
            if (x > y) {
                if (x > c) {
                    a = c;
                    b = 0;
                } else {
                    a = x;
                    b = c - a;
                }
            }  else {
                if (y > c) {
                    b = c;
                    a = 0;
                } else {
                    b = y;
                    a = c - b;
                }
            }

            out.printf("%d %d\n", a, b);
        }
    }
}
