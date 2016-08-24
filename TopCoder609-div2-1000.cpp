#include <vector>
#include <iostream>
#include <map>
#include <tuple>

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,pii> p4i;
typedef map<p4i, int> memo;
#define mp make_pair

class VocaloidsAndSongs{
public:
	// f(S, a,b,c ) = if (S==0) return 1
	// else f(S, a, b, c) = 
	// f(S-1, a-1, b, c) + f(S-1, a, ,b-1, c) + f(S-1, a,b, c-1) + f(S-1, a-1, b-1, c) + f(S-1,a-1, b, c-1) + f(S-1, a, b-1, c-1)
	int f(int S, int a, int b, int c, memo& m) {
		if (S==0) {
			if (a+b+c == 0)
				return 1;
			else
				return 0;
		}
		else {
			int MOD = 1000000007;
			p4i key = mp(mp(S,a), mp(b,c));
			auto it = m.find(key);
			if (it != m.end()) return it->second;
			int ans =0;
			if (a != 0){
				ans = (ans + (long long)f(S-1, a-1, b,c, m))%MOD;
				if (b != 0){
					ans = (ans + (long long)f(S-1, a-1, b-1,c,m))%MOD;
					if (c != 0){
						ans = (ans + (long long)f(S-1, a-1, b-1,c-1,m))%MOD;
					}
				}

				if (c!=0)
					ans = (ans + (long long)f(S-1, a-1, b,c-1,m))%MOD;

			}

			if (c != 0){
				ans = (ans + (long long)f(S-1, a, b, c-1,m))%MOD;
				if (b != 0)
					ans = (ans + (long long)f(S-1, a, b-1, c-1,m))%MOD;					
			}

			if (b != 0)
				ans = (ans + (long long)f(S-1, a, b-1,c,m))%MOD;

			m.insert(mp(key,ans));
			return ans;
		}
	}

	int count(int S, int gumi, int ia, int mayu){
		memo m;
		return f(S, gumi, ia, mayu, m);
	}
};


int main() {
	int S,a,b,c;
	cin >> S >> a >> b >> c;
	VocaloidsAndSongs obj;
	int ans = obj.count(S,a,b,c);
	cout << ans << "\n";
}