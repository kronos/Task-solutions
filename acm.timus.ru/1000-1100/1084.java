import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author kronos
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task1084 solver = new Task1084();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1084 {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            double a = in.nextDouble();
            double l = in.nextDouble();
            double pi = 3.1415926535;
            if (a / 2.0 - l >= 1e-6) {
                out.printf("%.3f", pi * l * l);
            } else if ((double) l - Math.sqrt(2 * a * a) / 2.0 >= 1e-6) {
                out.printf("%.3f", a * a);
            } else {
                double d = a / 2.0;
                double segment = l * l * Math.acos(d / l) - d * Math.sqrt(l * l - d * d);
                out.printf("%.3f", pi * l * l - segment * 4.0);
            }
        }

    }
}

