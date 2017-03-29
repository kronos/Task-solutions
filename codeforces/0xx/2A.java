import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;
import java.util.HashMap;

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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] scores = new int[n];
            String[] winners = new String[n];
            Map<String, Integer> r = new HashMap<>();
            for (int i = 0; i < n; i++) {
                winners[i] = in.next();
                scores[i] = in.nextInt();
                r.putIfAbsent(winners[i], 0);
                r.put(winners[i], r.get(winners[i]) + scores[i]);
            }

            Map.Entry<String, Integer> maxEntry = null;
            Set<String> possibleWinners = new HashSet<>();

            for (Map.Entry<String, Integer> entry : r.entrySet()) {
                if (maxEntry == null || entry.getValue() > maxEntry.getValue()) {
                    maxEntry = entry;
                    possibleWinners.clear();
                    possibleWinners.add(maxEntry.getKey());
                } else if (entry.getValue().equals(maxEntry.getValue())) {
                    possibleWinners.add(entry.getKey());
                }
            }


            if (possibleWinners.size() == 1) {
                out.println(possibleWinners.iterator().next());
            } else {
                Map<String, Integer> c = new HashMap<>();
                String winner = "";
                for (int i = 0; i < n; i++) {
                    if (possibleWinners.contains(winners[i])) {
                        c.putIfAbsent(winners[i], 0);
                        if (c.get(winners[i]) + scores[i] >= maxEntry.getValue()) {
                            winner = winners[i];
                            break;
                        }
                        c.put(winners[i], c.get(winners[i]) + scores[i]);
                    }
                }
                out.println(winner);
            }
        }

    }
}

