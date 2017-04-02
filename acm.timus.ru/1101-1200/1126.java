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
        int m = nextInt();
        Stack<Pair> st1 = new Stack<>();
        Stack<Pair> st2 = new Stack<>();
        int e = nextInt(), r;
        st1.push(new Pair(e, e));
        for (int i = 1; i < m; i++) {
            e = nextInt();
            st1.push(new Pair(e, max(e, st1.peek().right)));
        }
        while (e > -1) {
            if (st1.isEmpty()) {
                r = st2.peek().right;
            } else if (st2.isEmpty()) {
                r = st1.peek().right;
            } else {
                r = max(st1.peek().right, st2.peek().right);
            }
            out.println(r);
            if (st2.isEmpty()) {
                st2.push(new Pair(st1.peek().left, st1.peek().left));
                st1.pop();
                while (!st1.isEmpty()) {
                    st2.push(new Pair(st1.peek().left, max(st1.peek().left, st2.peek().right)));
                    st1.pop();
                }
            }
            st2.pop();
            e = nextInt();
            if (st1.isEmpty()) {
                st1.push(new Pair(e, e));
            } else {
                st1.push(new Pair(e, max(e, st1.peek().right)));
            }
        }
    }
}
