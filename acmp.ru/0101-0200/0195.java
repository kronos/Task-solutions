import java.io.*;
import java.math.BigDecimal;
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
       int a = nextInt(), b = nextInt(), c=nextInt();
       out.print(a*b*c*2);
   }
}
