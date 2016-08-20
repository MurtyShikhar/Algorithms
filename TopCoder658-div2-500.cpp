// dp easy

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

#define mp make_pair
#define INF 1<<20
using namespace std;

typedef map<pair<int,pair<int,int> >, int> spiii;
class MutaliskEasy {
public:

	int func(int a,int b,int c, spiii& memo) {
		if (a==0 && b==0 && c==0) return 0;
		vector<int> hp; hp.push_back(a); hp.push_back(b); hp.push_back(c);
		sort(hp.begin(), hp.end());
		int af = hp[0], bf = hp[1], cf = hp[2];
		spiii::iterator itr = memo.find(mp(af, mp(bf,cf)));
		if (itr != memo.end()) return itr->second;
		int res = INF;
		do {
			a = hp[0], b = hp[1], c = hp[2];
			int a1 = max(a-9, 0);
			int b1 = max(b-3,0);
			int c1 = max(c-1, 0);
			res = min(func(a1, b1, c1, memo), res);
		} while (next_permutation(hp.begin(), hp.end()));

		memo.insert(mp( mp(af, mp(bf,cf)) , res +1));
		return res +1;

	}
	int minimalAttacks(vector<int> x) {
		spiii memo;
		if (x.size() < 3) {
			while (x.size() != 3) x.push_back(0);
		}

		return func(max(x[0],0), max(x[1],0), max(x[2],0), memo);
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> x;
	for (int i=0; i < n; i++) {
		int p; cin >> p;
		x.push_back(p);
	}

	MutaliskEasy obj;
	int ans = obj.minimalAttacks(x);
	cout << ans << "\n";
}


