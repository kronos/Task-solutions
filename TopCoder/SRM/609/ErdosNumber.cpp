#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;

template <class T>
string to_s(T num)
{
	stringstream ss;
	ss << num;
	return ss.str();
}

class ErdosNumber
 {
    public:
    vector <string> calculateNumbers(vector <string> p)
    {
        vector <string> result, arr,arr2;
        map<string, vector<string> > matrix;
        map<string, int> data;
        map<string, int>::iterator it;
        map<string, bool> visit;
        int i,j,k,count,size;
        size = p.size();
        string s,q;
        for(i = 0; i < size; i++)
        {
        	s = p[i];
        	while (!s.empty())
        	{
        		for (j=0;j<s.length() && s[j] != ' '; j++){}
        		if (j == s.length())
        		{
        			q = s;
        			s = "";
        		}
        		else
        		{
        			q = s.substr(0,j);
        			s = s.substr(j+1,s.length()-j);
        		}
        		arr.push_back(q);
        		data[q] = 1000000;
        		visit[q] = false;
        	}

        	for(j = 0; j < arr.size(); j++)
        		for(k = 0; k < arr.size(); k++)
        			if (j!=k)
        				matrix[arr[j]].push_back(arr[k]);

        	arr.clear();
        }
        arr.push_back("ERDOS");
        count = 0;
        while (!arr.empty())
        {
        	while (!arr.empty())
        	{
						s = arr.back();
						arr.pop_back();
						if (visit[s])
							continue;
						visit[s] = true;
						data[s] = count;
						for(i = 0; i < matrix[s].size(); i++)
						{
							if (!visit[matrix[s][i]])
							{
								//cout << matrix[s][i] << ' ';
								arr2.push_back(matrix[s][i]);
							}
						}
        	}
        	//cout << endl;
        	arr = arr2;
        	arr2.clear();
          count++;
        }
        for(it = data.begin(); it != data.end(); it++)
        	result.push_back(it->first);
        sort(result.begin(), result.end());
        for (i = 0; i < result.size(); i++)
        {
        	if (data[result[i]] != 1000000)
        	{
        		s = " " + to_s<int>(data[result[i]]);
        		result[i]+=s;
        	}
        }
        return result;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) {
	if ((Case == -1) || (Case == 0)) test_case_0();
	if ((Case == -1) || (Case == 1)) test_case_1();
	if ((Case == -1) || (Case == 2)) test_case_2();
	if ((Case == -1) || (Case == 3)) test_case_3();
	if ((Case == -1) || (Case == 4)) test_case_4();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ERDOS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ERDOS 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, calculateNumbers(Arg0)); }
	void test_case_1() { string Arr0[] = {"KLEITMAN LANDER", "ERDOS KLEITMAN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ERDOS 0", "KLEITMAN 1", "LANDER 2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, calculateNumbers(Arg0)); }
	void test_case_2() { string Arr0[] = {"ERDOS A", "A B", "B AA C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A 1", "AA 3", "B 2", "C 3", "ERDOS 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, calculateNumbers(Arg0)); }
	void test_case_3() { string Arr0[] = {"ERDOS B", "A B C", "B A E", "D F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A 2", "B 1", "C 2", "D", "E 2", "ERDOS 0", "F" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, calculateNumbers(Arg0)); }
	void test_case_4() { string Arr0[] = {"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN",
 "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ALON 2", "CHUNG 2", "DEAN 2", "ERDOS 0", "GODDARD 2", "KLEITMAN 1", "STURTEVANT 2", "WAYNE 2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, calculateNumbers(Arg0)); }

// END CUT HERE

 };

    // BEGIN CUT HERE
    int main()
        {
        ErdosNumber ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
