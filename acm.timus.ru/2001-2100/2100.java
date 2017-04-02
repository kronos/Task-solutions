import java.io.*;
import java.util.Scanner;

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
        String s = in.nextLine();
        return s.isEmpty() ? in.nextLine() : s;
    }

    void run() throws IOException {
        solve();
        out.flush();
    }

    void solve() throws IOException {
        int n = nextInt();
        int answer = n+2;
        String s;
        for (int i = 0; i < n; i++) {
            s = nextString();
            if (s.endsWith("+one")) {
                answer += 1;
            }
        }
        if (answer == 13) {
            answer += 1;
        }
        System.out.println(answer*100);
    }
}
