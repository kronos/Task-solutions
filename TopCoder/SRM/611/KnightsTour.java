import java.util.*;
public class KnightsTour
{
	private 		int arr[][];
	final int moves[][] = {
		{-2,-1},
		{-2, 1},
		{-1,-2},
		{-1, 2},
		{ 1,-2},
		{ 1, 2},
		{ 2,-1},
		{ 2, 1}
	};

	public KnightsTour()
	{
		arr = new int[8][8];
	}

	public int visitedPositions(String[] board) {
		int count = 1;
		boolean can_move = true, f = false;
		int i,j, ik =0 , jk = 0,k;
		for (i=0;(i<8);i++)
			for (j=0;(j<8);j++)
				switch(board[i].charAt(j))
				{
					case '.':
						arr[i][j] = 0;
					break;
					case 'K':
						arr[i][j] = 1;
						ik = i;
						jk = j;
					break;
					case '*':
						arr[i][j] = 1;
					break;
				}
		int min, imin, access_count;
		while (can_move)
		{
			 can_move = false;
			 imin = 0;
			 min = accessibility(ik+moves[0][0], jk+moves[0][1]);
			 can_move = min < 100;
			 for(k = 1; k<8; k++)
			 {
				 access_count = accessibility(ik+moves[k][0], jk+moves[k][1]);
				 if (access_count < min)
				 {                          
					 min = access_count;
					 imin = k;
				 }
				 can_move |= access_count < 100;
			 }

			 if (can_move)
			 {
				 count++;
				 arr[ik][jk] = 1;
				 ik += moves[imin][0];
				 jk += moves[imin][1];
			 }
		}
		return count;
	}

	private int accessibility(int i, int j)
	{
		 if (i< 0 || j<0 || i>7 || j>7 || arr[i][j] != 0)
		   return 100;
		 int count = 0;
		 for (int k = 0; k < 8; k++)
		   if (
			     i+moves[k][0]>= 0 && i+moves[k][0] < 8 &&
				   j+moves[k][1]>= 0 && j+moves[k][1] < 8 &&
				   arr[i+moves[k][0]][j+moves[k][1]] == 0
			  )
			   count++;
		 return count;
	}
// BEGIN CUT HERE
     public static void main(String[] args) {
		if ( args.length == 0 ) {
			KnightsTourHarness.run_test(-1);
		} else {
			for ( int i=0; i<args.length; ++i )
				KnightsTourHarness.run_test(Integer.valueOf(args[i]));
		}
	}
// END CUT HERE
}

// BEGIN CUT HERE
class KnightsTourHarness {
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

	static boolean compareOutput(int expected, int result) { return expected == result; }
	static String formatResult(int res) {
		return String.format("%d", res);
	}

	static int verifyCase( int casenum, int expected, int received ) {
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
			String[] board            = {"........" ,".*.*...." ,".*......" ,"..K...*." ,"*...*..." ,"...*...." ,"...*.*.." ,"........"};
			int expected__            = 39;

			return verifyCase( casenum, expected__, new KnightsTour().visitedPositions( board ) );
		}
		case 1: {
			String[] board            = {"K......." ,"........" ,"........" ,"........" ,"........" ,"........" ,"........" ,"........"};
			int expected__            = 64;

			return verifyCase( casenum, expected__, new KnightsTour().visitedPositions( board ) );
		}
		case 2: {
			String[] board            = {"********" ,"*******." ,"********" ,"**.***.*" ,"********" ,"***.*.**" ,"********" ,"****K***"};
			int expected__            = 3;

			return verifyCase( casenum, expected__, new KnightsTour().visitedPositions( board ) );
		}
		case 3: {
			String[] board            = {"*.*....*" ,".......*" ,"**...*.." ,"..***..." ,".**.*..." ,"..*.*..K" ,"..***.*." ,"**...*.."};
			int expected__            = 17;

			return verifyCase( casenum, expected__, new KnightsTour().visitedPositions( board ) );
		}
		case 4: {
			String[] board            = {"..*...*." ,"**.....*" ,"*..*...." ,"*..*...." ,".....*.." ,"....*..K" ,"**.*...*" ,"..**...."};
			int expected__            = 27;

			return verifyCase( casenum, expected__, new KnightsTour().visitedPositions( board ) );
		}

		// custom cases

/*      case 5: {
			String[] board            = ;
			int expected__            = ;

			return verifyCase( casenum, expected__, new KnightsTour().visitedPositions( board ) );
		}*/
/*      case 6: {
			String[] board            = ;
			int expected__            = ;

			return verifyCase( casenum, expected__, new KnightsTour().visitedPositions( board ) );
		}*/
/*      case 7: {
			String[] board            = ;
			int expected__            = ;

			return verifyCase( casenum, expected__, new KnightsTour().visitedPositions( board ) );
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
