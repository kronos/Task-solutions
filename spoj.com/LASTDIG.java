import java.util.*;

public class Main {
    int modpow(int a, int b) {
        if (b == 0) {
            return 1;
        }

        int x = modpow(a,b/2);
        if ((b & 1) == 1) {
            return (x*x*a) % 10;
        } else {
            return (x*x) % 10;
        }
    }

    void solve() {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt(), a ,b;
        for (int i = 0; i < cases; i++) {
            a = in.nextInt();
            b = in.nextInt();
            System.out.println(modpow(a, b));
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}
