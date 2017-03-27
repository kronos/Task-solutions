import java.io.*;
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
       String a = in.readLine();
       String b = in.readLine();
       BigInteger ans = new BigInteger(a);
       ans = ans.add(new BigInteger(b));
       out.println(ans.toString());
   }
}
