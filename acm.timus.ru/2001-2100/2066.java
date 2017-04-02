import java.io.*;

public class Main {
    private final StreamTokenizer in;

    public Main() {
        this.in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    }

    public static void main(String[] args) throws IOException {
      new Main().solve();
    }
    int nextInt() throws IOException {
        in.nextToken();
        return (int)in.nval;
    }

    void solve() throws IOException {
        int a, b, c;
        a = nextInt();
        b = nextInt();
        c = nextInt();
        int answer = a + b + c;

        if (a-b-c < answer) {
            answer = a-b-c;
        }

        if (a*b*c < answer) {
            answer = a*b*c;
        }

        if (a-b*c < answer) {
            answer = a-b*c;
        }

        if (a*b-c < answer) {
            answer = a*b-c;
        }

        if (a+b*c < answer) {
            answer = a+b*c;
        }

        if (a*b+c < answer) {
            answer = a*b+c;
        }

        if (a+b-c < answer) {
            answer = a+b-c;
        }

        if (a-b+c < answer) {
            answer = a-b+c;
        }

        System.out.println(answer);
    }
}
