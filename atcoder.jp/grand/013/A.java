import java.io.*;

public class Main {
    private StreamTokenizer in;
    private PrintWriter out;

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }

    String nextString() throws IOException {
        in.nextToken();
        if (in.sval.isEmpty()) {
            in.nextToken();
        }
        return in.sval;
    }

    void run() throws IOException {
        out = new PrintWriter(new OutputStreamWriter(System.out));
        in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        solve();
        out.flush();
    }

    void solve() throws IOException {
        int n = nextInt();
        int answer = 1;
        int order = -1; // -1 unclear, 0 - decreasing, 1 - increasing
        int a = nextInt(), b;
        for (int i = 1; i < n; i++) {
            b = nextInt();
            if (a != b) {
                if (a < b) {
                    if (order == -1) {
                        order = 1;
                    } else if (order == 0) {
                        answer++;
                        order = -1;
                    }
                } else {
                    if (order == -1) {
                        order = 0;
                    } else if (order == 1) {
                        answer++;
                        order = -1;
                    }
                }
            }
            a = b;
        }
        out.print(answer);
    }
}
