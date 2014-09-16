import java.io.*;
import java.util.*;

public class Main {
  FastScanner in;
  PrintWriter out;

  void solve() throws IOException
  {
    int n = in.nextInt(), r = 0;
    String s;
    Set<String> dict = new HashSet<String>();

    for(int i = 0; i < n; ++i) {
      s = in.readLine();
      if (dict.contains(s)) {
        r++;
      } else {
        dict.add(s);
      }
    }
    out.println(r);
  }

  void run() throws IOException
  {
    in = new FastScanner(new InputStreamReader(System.in));
    out = new PrintWriter(new OutputStreamWriter(System.out));
    solve();
    out.flush();
  }

  class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    FastScanner(InputStreamReader stream) {
      br = new BufferedReader(stream);
    }

    String next() {
      while (st == null || !st.hasMoreTokens()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    String readLine() {
      String s = "";
      try {
        s = br.readLine();
      } catch (IOException e) {
        e.printStackTrace();
      }
      return s;
    }

    int nextInt() {
      return Integer.parseInt(next());
    }
  }

  public static void main(String[] args) throws IOException {
    new Main().run();
  }
}
