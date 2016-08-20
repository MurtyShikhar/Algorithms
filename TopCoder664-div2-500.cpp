#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define mp make_pair

using namespace std;
typedef set<pair<int,int> >  spii;
class BearPlaysDiv2{
public:
	bool equalPilesHelper(int A, int B, int S, spii& memo) {
		int C = S-A-B;
		vector<int> s; s.push_back(A); s.push_back(B); s.push_back(C);
		sort(s.begin(), s.end());
		A = s[0], B=s[1], C = s[2];
		if (A==B && B ==C) {
			return 1;
		}
		else {
			if (memo.find(mp(A, B)) != memo.end())
				return 0;
			else {
				memo.insert(mp(A,B));
				bool step, step2, step3;
				if (A < B) 
					if (equalPilesHelper(2*A, B-A, S, memo)) return 1;
				if (B < C) 
					if (equalPilesHelper(2*B, C-B, S, memo)) return 1;
				if (A < C)
					if (equalPilesHelper(2*A, C-A, S,memo)) return 1;

				return 0;
			}
		}
	}

	string equalPiles(int A, int B, int C) {
		spii memo;
		if ((A+B+C) % 3) return "impossible";
		bool possible = equalPilesHelper(A, B,A+B+C, memo);
		if (possible) return "possible";
		else return "impossible";
	}
};



int main() {
	int a, b, c;
	cin >> a >> b >> c;
	BearPlaysDiv2 obj;
	string s = obj.equalPiles(a,b,c);
	cout << s << "\n";
}