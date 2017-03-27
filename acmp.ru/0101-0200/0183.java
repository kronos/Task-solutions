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
      //in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
      //out = new PrintWriter(new OutputStreamWriter(System.out));
      solve();
      out.flush();
   }


   void solve() throws IOException
   {
       int k = nextInt();
       int p = nextInt();
       if (k<2)
       {
           out.print(0);
           return;
       }
       long table[] = new long[k/2+2];
       long pr = 1;
       long val = 1;
       table[2] = 1;
       for (int i=3;i<=k;i++)
       {
           val = pr;
           if (i%2==0)
           {
               val = (pr+table[i/2])%p;
               pr = val;
           }
           if (i<=k/2)
               table[i] = val;
       }
       out.print( val%p );
   }
}
