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
        String answer = "";
        int e;
        boolean _3 = false;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            e = nextInt();
            _3 |= e < 4;
            sum += e;
        }

        if (_3) {
            answer = "None";
        } else {
            float avg = (float)sum / n;
            if (avg == 5.0) {
                answer = "Named";
            } else if (avg >= 4.5) {
                answer = "High";
            } else {
                answer = "Common";
            }
        }
        out.println(answer);
    }
}
