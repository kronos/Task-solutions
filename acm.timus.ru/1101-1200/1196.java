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

   float nextFloat() throws IOException
   {
      in.nextToken();
      return (float)in.nval;
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
     int n = nextInt();
     TreeSet tree = new TreeSet();
     int i, x, m, r = 0, pos;
     int[] arr = new int[n];
     for (i = 0; i < n; i++)
     {
       arr[i] = nextInt();
     }
     Arrays.sort(arr);
     m = nextInt();
     for (i = 0; i < m; i++)
     {
        if (Arrays.binarySearch(arr, nextInt()) >= 0)
          r++;
     }
     out.println(r);
   }
}
