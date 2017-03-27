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
        int w = nextInt();
        int h = nextInt();
        int n = nextInt();
        int data[][] = new int[h][w];
        int x1,y1,x2,y2,i,j;

        for (int k = 0;k<h; k++)
            Arrays.fill(data[k], 0);
        for (int k = 0;k < n; k++)
        {
            x1 = nextInt();
            y1 = nextInt();
            x2 = nextInt();
            y2 = nextInt();
            for (i=y1;i<y2;i++)
                for (j=x1;j<x2;j++)
                    data[i][j]++;
        }
        int ans = 0;
        for (i=0;i<h;i++)
            for (j=0;j<w;j++)
                if (data[i][j]==0)
                    ans++;

        out.print(ans);
    }
}
