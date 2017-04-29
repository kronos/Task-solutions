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

    void run() throws IOException {
        solve();
        out.flush();
    }

    void solve() throws IOException {
        int t = in.nextInt();
        int k,a,b,ans,p;
        for(;t>0;t--) {
            k = in.nextInt();
            a = in.nextInt();
            b = in.nextInt();
            if (a < b) {
                p = a;
                a = b;
                b = p;
            }
            if (a >= k) {
                if (a-b > 1) {
                    ans = 0;
                } else if (a == b) {
                    ans = 2;
                } else {
                    ans = 1;
                }
            } else {
                ans = k - a;
                if (ans + a - b == 1) {
                    ans++;
                } else if (ans + a - b == 0) {
                    ans += 2;
                }
            }
            out.println(ans);
        }
    }
}
