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
        int d1 = nextInt() * 2;
        int d2 = nextInt() * 2;
        int d3 = nextInt() * 2;
        String answer;

        if (d1 >= d2+d3) {
            answer = "YES";
        } else {
            answer = "NO";
        }

        out.println(answer);
    }
}
