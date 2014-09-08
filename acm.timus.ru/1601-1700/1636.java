import java.io.*;
import java.util.*;
import java.math.BigInteger;

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
      in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
      out = new PrintWriter(new OutputStreamWriter(System.out));
      solve();
      out.flush();
   }

   void solve() throws IOException
   {
      int T1, T2,i;
      T1 = nextInt();
      T2 = nextInt();
      int q = 0, p;
      for (i=0;i<10;i++)
      {
        p = nextInt();
        q+=p*20;
      }
      if (T2-q<T1 && T2>=T1)
        out.println("Dirty debug :(");
      else
        out.println("No chance.");
   }
}
