import java.io.*;
import java.math.BigInteger;

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
        int x = nextInt();
        BigInteger ans = new BigInteger("1");
        if (x<5)
        {
            ans = BigInteger.valueOf(x);
        }
        else
        {
            while (x>4)
            {
                ans = ans.multiply( BigInteger.valueOf(3));
                x-= 3;
            }
            ans = ans.multiply(BigInteger.valueOf(x));
        }
        out.println(ans);
    }
}
