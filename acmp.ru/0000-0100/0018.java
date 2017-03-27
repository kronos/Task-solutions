import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main
{
   public static void main(String[] args) throws IOException
   {
      new Main().run();
   }

   StreamTokenizer in;
   PrintWriter out;

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
       int n = nextInt();
       BigInteger ans = new BigInteger("1");
       for(int i=2;i<=n;i++)
           ans = ans.multiply( BigInteger.valueOf(i) );

       out.println(ans.toString());
   }
}
