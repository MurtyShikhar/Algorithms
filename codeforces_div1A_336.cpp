#include <set>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


int main() {
	int n; scanf("%d", &n);

	vector<pair<int,int> > obj(n);
	for (int i=0; i < n; i++) {
		int a,b; scanf("%d %d", &a, &b);
		obj[i] =make_pair(a,b);
	}


	sort(obj.begin(), obj.end());
	vector<int> possible(n,0); // possible[i]..i-1 are the beacons that can get eliminated
	possible[0] = 0;

	for (int i=1; i <n; i++) {
		int idx = lower_bound(obj.begin(), obj.begin() + i, make_pair(obj[i].first - obj[i].second, -1)) - obj.begin();
		possible[i] = idx;
	}

	vector<int> dp(n, 0); // dp[i] = max ships destroyed starting from ship i
	for (int i=1; i < n; i++) {
		dp[i] = i -possible[i];
		if (possible[i] > 0)
			dp[i] += dp[possible[i]-1];
	}

	int ans = dp[n-1]; // if external ship doesn't destroy anything
	for (int i=n-2; i >=0; i--) {
		// destroyed from n-1 to i+1 -> n - (i+1)
		ans = min(ans, n - i-1 + dp[i]);
	}

	cout << ans << "\n";
}