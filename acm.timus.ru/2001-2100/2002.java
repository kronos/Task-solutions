import java.io.*;
import java.util.*;

public class Main {
    private final Scanner in;
    private final PrintWriter out;
    private final String REGISTER = "register";
    private final String LOGIN    = "login";
    private final String LOGOUT   = "logout";

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
        String s = in.next();
        return s.isEmpty() ? in.nextLine() : s;
    }

    void run() throws IOException {
        solve();
        out.flush();
    }

    void solve() throws IOException {
        int n = nextInt();
        String s, login, pwd, r = "";
        Map<String, String> users = new HashMap<>();
        Set<String> loggedIn = new HashSet<>();
        for (int i = 0; i < n; i++) {
            s = nextString();
            switch (s) {
                case REGISTER:
                    login = nextString();
                    pwd = nextString();
                    if (users.containsKey(login)) {
                        r = "fail: user already exists";
                    } else {
                        users.put(login, pwd);
                        r = "success: new user added";
                    }
                    break;
                case LOGIN:
                    login = nextString();
                    pwd = nextString();
                    if (!users.containsKey(login)) {
                        r = "fail: no such user";
                    } else if (!users.get(login).equals(pwd)) {
                        r = "fail: incorrect password";
                    } else if (loggedIn.contains(login)) {
                        r = "fail: already logged in";
                    } else {
                        r = "success: user logged in";
                        loggedIn.add(login);
                    }
                    break;
                case LOGOUT:
                    login = nextString();
                    if (!users.containsKey(login)) {
                        r = "fail: no such user";
                    } else if (!loggedIn.contains(login)) {
                        r = "fail: already logged out";
                    } else {
                        r = "success: user logged out";
                        loggedIn.remove(login);
                    }
                    break;
            }
            out.println(r);
        }
    }
}
