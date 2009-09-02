import java.util.*;
public class ImportsList {
	private int size, sort[], sort_index;
	private boolean used[], arr[][];
	int min, sum;
	
	public ImportsList()
	{
		arr  = new boolean[50][50];
		sort = new int[50];
		used = new boolean[50];
	}

	public int[] importsCount(String[] requires)
	{
		sort_index = 0;
		size = requires.length;
		int result[] = new int[size];
		int i, j, k, v;
		for (i = 0; i < size; i++)
		{
			result[i] = 0;
			used[i]   = false;
			for (j = 0; j < size; j++)
			{
				arr[i][j] = requires[i].charAt(j) == 'Y';

				if (arr[i][j])
				{
					result[i]++;
					sum++;
				}
			}
		}
		for (i = 0; i < size; i++)
		{
			if (!used[i])
				dfs(i);
		}

		for (i = 0; i < size; i++)
		{
			v = sort[i];
			for (j = 0; j < size; j++)
			{
				for (k = 0; k < size; k++)
					if (arr[j][v] && arr[k][v] && arr[j][k])
					{
						arr[j][v] = false;
						result[j]--;
					}
			}
			
		}
		return result;
	}

	private void dfs(int v)
	{
		used[v] = true;

		for(int u = 0; u < size; u++)
		{
			if (arr[v][u] && !used[u])
				dfs(u);
		}

		sort[sort_index] = v;
		sort_index++;
	}

	// BEGIN CUT HERE
     public static void main(String[] args) {
		if ( args.length == 0 ) {
			ImportsListHarness.run_test(-1);
		} else {
			for ( int i=0; i<args.length; ++i )
				ImportsListHarness.run_test(Integer.valueOf(args[i]));
		}
	}
// END CUT HERE
}

// BEGIN CUT HERE
class ImportsListHarness {
	public static void run_test( int casenum ) {
		if ( casenum != -1 ) {
			if ( runTestCase( casenum ) == -1 )
				System.err.println("Illegal input! Test case " + casenum + " does not exist.");
			return;
		}

		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = runTestCase(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}

		if ( total == 0 ) {
			System.err.println("No test cases run.");
		} else if ( correct < total ) {
			System.err.println("Some cases FAILED (passed " + correct + " of " + total + ").");
		} else {
			System.err.println("All " + total + " tests passed!");
		}
	}

	static boolean compareOutput(int[] expected, int[] result) { if ( expected.length != result.length ) return false; for ( int i=0; i<expected.length; ++i ) if ( expected[i] != result[i] ) return false; return true; }

	static String formatResult(int[] res) {
		String ret = "";
		ret += "{";
		for (int i=0; i<res.length; ++i) {
			if (i > 0) ret += ",";
			ret += String.format(" %d", res[i]);
		}
		ret += " }";
		return ret;
	}

	static int verifyCase( int casenum, int[] expected, int[] received ) {
		System.err.print("Example " + casenum + "... ");
		if ( compareOutput( expected, received ) ) {
			System.err.println("PASSED");
			return 1;
		} else {
			System.err.println("FAILED");
			System.err.println("    Expected: " + formatResult(expected));
			System.err.println("    Received: " + formatResult(received));
			return 0;
		}
	}

	static int runTestCase( int casenum ) {
		switch( casenum ) {
		case 0: {
			String[] requires         = {"NNN" ,"NNN" ,"NNN"};
			int[] expected__          = {0, 0, 0 };

			return verifyCase( casenum, expected__, new ImportsList().importsCount( requires ) );
		}
		case 1: {
			String[] requires         = {"NYYY" ,"NNYY" ,"NNNY" ,"NNNN"};
			int[] expected__          = {1, 1, 1, 0 };

			return verifyCase( casenum, expected__, new ImportsList().importsCount( requires ) );
		}
		case 2: {
			String[] requires         = {"NNNNY" ,"NNNNY" ,"YNNNY" ,"NNNNN" ,"NNNNN"};
			int[] expected__          = {1, 1, 1, 0, 0 };

			return verifyCase( casenum, expected__, new ImportsList().importsCount( requires ) );
		}
		case 3: {
			String[] requires         = {"NYYNYNYYYNYYNYNN" ,"NNNNNNNNNNNNNNNN" ,"NNNNNNNNNNYNNNNN" ,"NNNNNNNNNYNNYNNN" ,"NYNNNNYNNNYYNNNN" ,"NYNNYNYNYNYYNNNN" ,"NNNNNNNNNNYNNNNN" ,"NNYNNNYNYNYNNNNN" ,"NNNNNNYNNNYNNNNN" ,"NNNNNNNNNNNNYNNN" ,"NNNNNNNNNNNNNNNN" ,"NNNNNNNNNNNNNNNN" ,"NNNNNNNNNNNNNNNN" ,"NNNNNNYNNNYNNNNN" ,"YYYYYNYYYYYYYYNY" ,"NYYYNNYNNYYNYYNN"};
			int[] expected__          = {3, 0, 1, 1, 3, 2, 1, 2, 1, 1, 0, 0, 0, 1, 2, 4 };

			return verifyCase( casenum, expected__, new ImportsList().importsCount( requires ) );
		}

		// custom cases

/*      case 4: {
			String[] requires         = ;
			int[] expected__          = ;

			return verifyCase( casenum, expected__, new ImportsList().importsCount( requires ) );
		}*/
/*      case 5: {
			String[] requires         = ;
			int[] expected__          = ;

			return verifyCase( casenum, expected__, new ImportsList().importsCount( requires ) );
		}*/
/*      case 6: {
			String[] requires         = ;
			int[] expected__          = ;

			return verifyCase( casenum, expected__, new ImportsList().importsCount( requires ) );
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
