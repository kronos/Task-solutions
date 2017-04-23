import java.io.*;

public class Main  {
    private StreamTokenizer in;
    private PrintWriter out;

    Main() throws FileNotFoundException {
        in = new StreamTokenizer(new BufferedReader(new FileReader(new File("input.txt"))));
        out = new PrintWriter(new File("output.txt"));
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    int nextInt() throws IOException {
        in.nextToken();
        return (int)in.nval;
    }

    void run() throws IOException {
        solve();
        out.flush();
    }

    void solve() throws IOException {
        int n = nextInt();
        int answer = 0;

        if (n > 1) {
            if (n % 2 == 0) {
                answer = n / 2;
            } else {
                answer = n;
            }
        }
        out.println(answer);
    }
}
