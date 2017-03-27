import java.io.*;
import java.math.BigInteger;
import java.util.*;
 
public class Main
{
    BufferedReader in;
    PrintWriter out;
         
    public static void main(String[] args) throws IOException
    {
        new Main().run();
    }

    void run() throws IOException
    {
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter(new File("output.txt"));
        solve();
        out.flush();
    }
 
    void solve() throws IOException
    {
        String s = in.readLine();
        BigInteger val = new BigInteger(s);
        BigInteger two = BigInteger.valueOf(2);
        BigInteger r;
        BigInteger l;
        if (s.length()>10)
        {
            r = new BigInteger(s.substring(0, s.length()/2 + 1));
            if (s.length() % 2 == 1)
                l = new BigInteger(s.substring(0, s.length() / 2));
            else
                l = new BigInteger(s.substring(0, s.length() / 2 - 1));
        }
        else
        {
            r = new BigInteger(val.divide( two ).toString());
            l = new BigInteger("1");
        }
        BigInteger p = new BigInteger("1");
        while(l.compareTo(r) == -1)
        {
            if (r.pow(2).compareTo(val) <= 0)
            {
                l = r;
                r = p.add(l).divide(two);
            }
            else
            {
                p = r;
                r = r.add(l).divide(two);
            }
        }
        out.print(l);
    }
}
