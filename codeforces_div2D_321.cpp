#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

#define MAXN 18

using namespace std;

typedef map<pair<int,int>, int> hashT;

/* solve(bitmask, last, so_far) = if (so_far == 0) return 0
								  otherwise return solve(bitmask - last, i, so_far-1) + additional profits 	
 */


long long dp[1<<18][MAXN];
int a[MAXN];
int n;

long long solve(int taken, int last, hashT& rules){
	if (taken == 0) return 0;
	if ((taken & (1<<last)) ==0) return -1;
	if (dp[taken][last] != -1)
		return dp[taken][last];

	int price_last = a[last];
	long long ans = -1;
	int curr_mask = taken^(1<<last);
	for (int i=0; i < n; i++) {
		if (taken & (1<<i)) {
			int incr=0;
			auto it = rules.find(make_pair(i, last));
			if (it != rules.end())
				incr = it->second;
			ans = max(ans,solve(curr_mask, i, rules) + a[last] + incr);
		}
	}

	dp[taken][last] = ans;
	return ans;
}

void init() {
	for (int i=0; i < (1<<n); i++) {
		for (int j=0; j < n; j++) 
			dp[i][j] = -1;
	}
}

int main() {
	int m, k;
	scanf("%d %d %d\n", &n, &m, &k);
	for (int i=0; i < n; i++) scanf("%d", &a[i]);
	hashT rules;

	init();
	for (int i=0; i < k; i++) {
		int a,b,c; scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		rules[make_pair(a,b)] = c;
	}

	long long ans = -1;
	for (int i=0; i < (1<<n); i++) {
		int on_bits=0;
		for (int j=0; j < n; j++) {
			if (i & (1<< j)) on_bits += 1;
		}

		if (on_bits == m){
			for (int j=0; j < n; j++){

				ans = max(ans, solve(i, j, rules));
			}
		}
	}

	cout << ans << "\n";
}