import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main
{
    StreamTokenizer in;
    PrintWriter out;

    public static void main(String[] args) throws IOException
    {
        new Main().run();
    }

    int nextInt() throws IOException
    {
        in.nextToken();
        return (int)in.nval;
    }

    void run() throws IOException
    {
        in = new StreamTokenizer(new BufferedReader(new FileReader(new File("input.txt"))));
        out = new PrintWriter(new File("output.txt"));
        solve();
        out.flush();
    }

    void solve() throws IOException
    {
        int x = nextInt();
        int data[] = new int[x];
        for (int i = 0;i < x; i++)
            data[i] = nextInt();
        double ans = nextInt();
        Arrays.sort(data);

        for (int i = 0; i<x;i++)
        {
            if ((ans+data[i])/2.0>ans)
                ans = (ans+data[i])/2.0;
        }
        out.printf(Locale.US,"%.6f",ans);
    }
}
