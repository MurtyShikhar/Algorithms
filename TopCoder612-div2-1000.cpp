#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
/* numbers that can be formed using an array of powers of 2 
   Since powers of two, look at the possibilities of making 1s and 0s, and make it
   greediliy.  
*/
class PowersOfTwo{
public:
	long solve(int idx, int carry, vector<int>& pow, vector<vector<long> >& dp) {
		if (idx == pow.size())
			return 1;
		else {
			if (dp[carry][idx] != -1) return dp[carry][idx];
			int x_idx = pow[idx] + carry;
			long ans = solve(idx+1, x_idx/2, pow, dp);
			if (x_idx > 0)
				ans += solve(idx+1, (x_idx-1)/2, pow, dp);

			return dp[carry][idx] = ans;
		}
	}

	long count(vector<long>& powers){
		vector<int> pow(60, 0);
		// dp[i][j] = number of ways with  
		vector<vector<long> > dp(50, vector<long>(60, -1));

		int n = powers.size();
		for (int i=0; i < n; i++) {
			int curr = log2(powers[i]);
			pow[curr] += 1;
		}

		// dp[x_k][k] = dp[x_(k+1) + ][k+1] + dp[x_(k-1) ][k-1]

		return solve(0, 0, pow, dp);
	}
};


int main() {
	int n; scanf("%d", &n);
	vector<long> powers(n);
	for (int i=0; i < n; i++) {
		long curr; cin >> curr; 
		powers[i] = curr;
	}
	PowersOfTwo p;
	cout << p.count(powers) << "\n";
}
