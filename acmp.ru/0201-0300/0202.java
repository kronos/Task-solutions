import java.io.*;
import java.util.*;
import java.math.BigInteger;

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
      out = new PrintWriter(new File("output.txt"));
      in = new BufferedReader(new FileReader("input.txt"));
      solve();
      out.flush();
   }

    private int[] pre_kmp(String x)
    {
        int i, j;
        int m = x.length()-1;
        int kmp_next[] = new int[m+1];

   i = 0;
   j = -1;
      kmp_next[0] = -1;
   while (i < m) {
      while (j > -1 && x.charAt(i) != x.charAt(j))
         j = kmp_next[j];
      i++;
      j++;
      if (x.charAt(i) == x.charAt(j))
         kmp_next[i] = kmp_next[j];
      else
         kmp_next[i] = j;
   }
    return kmp_next;
    }

void kmp2(String x, String y) {
   int i, j;
     int m = y.length()-1;
     int n = x.length();
   /* Preprocessing */
   int kmpNext[] = pre_kmp(y);
   /* Searching */
   i = 0;
     j = 0;
   while (j < n) {
      while (i > -1 && y.charAt(i) != x.charAt(j))
         i = kmpNext[i];
      i++;
      j++;
      if (i >= m) {
         out.print(j - i);
         out.print(' ');
         i = kmpNext[i];
      }
   }
}

    void kmp(String target, String pattern)
    {
        int n = target.length();
        int m = pattern.length() - 1;
        int q = 0;
        int pi[] = pre_kmp(pattern);
    }

    private int[] findPrefix(String pattern)
    {
        int m = pattern.length(), k = 0;
        int pi[] = new int[m];

        pi[0] = -1;
        for (int q=1; q<m; q++ )
        {
            while ((k > 0) && (pattern.charAt(k) != pattern.charAt(q)))
                k = pi[k];
        if (pattern.charAt(k) == pattern.charAt(q))
                k++;
            pi[q] = k;
        }

        return pi;
    }

    void solve() throws IOException
    {
        String s1 = in.readLine();
        String s2 = in.readLine();
        s2 += ' ';
        kmp2(s1, s2);
    }
}
