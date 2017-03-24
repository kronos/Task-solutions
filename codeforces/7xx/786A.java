import java.io.*;
import java.util.Arrays;

public class Main {
    private StreamTokenizer in;
    private PrintWriter out;

    private String playground[][];
    private int n;
    private int sets[][];

    int nextInt() throws IOException {
        in.nextToken();
        return (int)in.nval;
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    void run() throws IOException {
        in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        solve();
        out.flush();
    }

    void simulate_all() {
        final String WIN = "Win ";
        final String LOSE = "Lose ";
        final String LOOP = "Loop ";
        boolean changed = true;
        int i,j;

        Arrays.fill(playground[0], LOOP);
        Arrays.fill(playground[1], LOOP);

        for (i = 0; i < 2; i++) {
            for (int e : sets[i]) {
                playground[i][n - e] = WIN;
            }
        }
        while (changed) {
            changed = false;
            for (i = n - 1; i > 0; i--) {
                for (j = 0; j < 2; j++) {
                    if (playground[j][i] == LOOP) {
                        boolean win = false;
                        boolean loop = false;
                        for (int e : sets[j]) {
                            int idx = (i + e) % n;
                            if (playground[1-j][idx] == LOSE) {
                                win = true;
                                break;
                            } else if (playground[1-j][idx] != WIN) {
                                loop = true;
                            }
                        }

                        if (win) {
                            changed = true;
                            playground[j][i] = WIN;
                        } else if (!loop) {
                            changed = true;
                            playground[j][i] = LOSE;
                        }
                    }
                }
            }
        }
    }

    void solve() throws IOException {
        int i;
        n = nextInt();
        int k1 = nextInt();
        sets = new int[2][];
        sets[0] = new int[k1];
        for (i = 0; i < k1; i++) {
            sets[0][i] = nextInt();
        }
        int k2 = nextInt();
        sets[1] = new int[k2];
        for (i = 0; i < k2; i++) {
            sets[1][i] = nextInt();
        }
        playground = new String[2][];
        playground[0] = new String[n];
        playground[1] = new String[n];

        simulate_all();

        StringBuilder b1 = new StringBuilder();
        StringBuilder b2 = new StringBuilder();

        for (i = 1; i < n; i++) {
            b1.append(playground[0][i]);
            b2.append(playground[1][i]);
        }

        out.println(b1.toString());
        out.println(b2.toString());
    }
}
