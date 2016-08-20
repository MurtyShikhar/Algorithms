// dp tricky

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

#define mp make_pair
#define INF (1<<20)

using namespace std;
typedef map<int, int> mii;

class EmoticonsDiv2{
public:
	int func(int smiles, mii& memo) {
		if (smiles ==1) return 0;
		mii::iterator itr = memo.find(smiles);
		if (itr != memo.end()) return itr->second;
		int ret = INF;
		for (int i=1; i < smiles; i++) {
			if (smiles%i == 0)
				ret = min((func(i, memo) + smiles/i), ret);
		}

		memo.insert(mp(smiles, ret));
		return ret;
	}

	int printSmiles(int smiles) {
		mii memo;
		return func(smiles, memo);
	}
};


int main() {
	int n; cin >> n;
	EmoticonsDiv2 obj;
	int ans = obj.printSmiles(n);
	cout << ans << "\n";
}