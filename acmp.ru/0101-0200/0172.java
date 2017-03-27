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

   BufferedReader in;
   PrintWriter out;

   void run() throws IOException
   {
      in = new BufferedReader(new FileReader(new File("input.txt")));
      out = new PrintWriter(new File("output.txt"));
      solve();
      out.flush();
   }

   void solve() throws IOException
   {
       String s1 = in.readLine();
       int k = s1.lastIndexOf(" ");
       String s2 = s1.substring(0,k);
       s1 = s1.substring(k+1);
       BigInteger a = new BigInteger(s2);
       BigInteger b = new BigInteger(s1);
       out.print(a.mod(b));
   }
}
