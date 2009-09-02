import java.util.*;
public class ImportantTasks {
	public int maximalCost(int[] complexity, int[] computers) {
		Arrays.sort(complexity);
		Arrays.sort(computers);		
		int count = 0, i, j = computers.length-1;
		for (i = complexity.length-1; i>=0 && j>=0; i--)
			if (complexity[i] <= computers[j])
			{
				count++;
				j--;
			}
		return count;
	}
// BEGIN CUT HERE
     public static void main(String[] args) {
		if ( args.length == 0 ) {
			ImportantTasksHarness.run_test(-1);
		} else {
			for ( int i=0; i<args.length; ++i )
				ImportantTasksHarness.run_test(Integer.valueOf(args[i]));
		}
	}
// END CUT HERE
}

// BEGIN CUT HERE
class ImportantTasksHarness {
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
			int[] complexity          = {1,2,3};
			int[] computers           = {2,2,2};
			int expected__            = 2;

			return verifyCase( casenum, expected__, new ImportantTasks().maximalCost( complexity, computers ) );
		}
		case 1: {
			int[] complexity          = {1,2,3};
			int[] computers           = {3};
			int expected__            = 1;

			return verifyCase( casenum, expected__, new ImportantTasks().maximalCost( complexity, computers ) );
		}
		case 2: {
			int[] complexity          = {3,5,1,7};
			int[] computers           = {9,4,1,1,1};
			int expected__            = 3;

			return verifyCase( casenum, expected__, new ImportantTasks().maximalCost( complexity, computers ) );
		}
		case 3: {
			int[] complexity          = {5,2,7,8,6,4,2,10,2,3};
			int[] computers           = {4,1,3,6,2,10,11,1,1,3,4,2};
			int expected__            = 8;

			return verifyCase( casenum, expected__, new ImportantTasks().maximalCost( complexity, computers ) );
		}
		case 4: {
			int[] complexity          = {100};
			int[] computers           = {100,100};
			int expected__            = 1;

			return verifyCase( casenum, expected__, new ImportantTasks().maximalCost( complexity, computers ) );
		}

		// custom cases

/*      case 5: {
			int[] complexity          = ;
			int[] computers           = ;
			int expected__            = ;

			return verifyCase( casenum, expected__, new ImportantTasks().maximalCost( complexity, computers ) );
		}*/
/*      case 6: {
			int[] complexity          = ;
			int[] computers           = ;
			int expected__            = ;

			return verifyCase( casenum, expected__, new ImportantTasks().maximalCost( complexity, computers ) );
		}*/
/*      case 7: {
			int[] complexity          = ;
			int[] computers           = ;
			int expected__            = ;

			return verifyCase( casenum, expected__, new ImportantTasks().maximalCost( complexity, computers ) );
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
