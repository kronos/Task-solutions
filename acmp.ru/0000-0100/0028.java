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
        //in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter(new File("output.txt"));
        //in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        //out = new PrintWriter(new OutputStreamWriter(System.out));
        solve();
        out.flush();
    }

    void solve() throws IOException
    {
        int x1 = nextInt();
        int y1 = nextInt();
        int x2 = nextInt();
        int y2 = nextInt();
        int px = nextInt();
        int py = nextInt();
        int ax,ay;
        if (y1==y2)
        {
            ax = px;
            if (py>y1)
                ay = y1 - (py-y1);
            else
                ay = y1 + (y1-py);
        }
        else
        {
            if (px>x1)
                ax = x1 - (px-x1);
            else
                ax = x1 + (x1-px);
            ay = py;
        }
        out.print(ax+" "+ay);
    }
}
