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
        String answer = "NO";

        while (n > 1 && n % 2 == 0)  {
            n /= 2;
        }

        if (n == 1) {
            answer = "YES";
        }
        out.println(answer);
    }
}
