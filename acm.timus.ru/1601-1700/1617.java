import java.io.*;
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
      in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
      out = new PrintWriter(new OutputStreamWriter(System.out));
      solve();
      out.flush();
   }

   void solve() throws IOException
   {
      int n = nextInt();
      int arr[] = new int[n];
      for (int i=0;i<n;i++)
        arr[i] = nextInt();
      Arrays.sort(arr);
      int r=0;
      for(int i=0;i<n-3;)
      {
          if (arr[i]==arr[i+1] && arr[i]==arr[i+2] && arr[i]==arr[i+3])
          {
              r++;
              i+=4;
          } else
              i++;
      }
      out.print(r);
   }
}
