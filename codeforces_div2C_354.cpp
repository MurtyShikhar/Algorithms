#include <vector>
#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(string& s, int k) {
	int n = s.size();
	int l=0, r=0;
	int ans=0;
	int countA=0, countB=0;
	while (r < n && min(countA+(s[r]=='a'), countB + (s[r]=='b')) <= k) {
		countA += (s[r]=='a');
		countB += (s[r]=='b');
		ans = countA+ countB;
		r++;
	}

	// if (r == n && min(countA, countB) <= k) {
	// 	cout << countA + countB << "\n";
	// 	return;
	// }

	while (l < n && r < n) {

		while (l < n && min(countA, countB) > k){
			countA -= (s[l]=='a');
			countB -= (s[l]=='b');		
			l++;
		}

		if (l < n)
			ans = max(ans, countA + countB);
		countA += (s[r]=='a');
		countB += (s[r]=='b');
		if (min(countA, countB) <= k)
			ans = max(ans, countB+countA);
		r++;
	}

	cout << ans << "\n";

}

int main() {
	int n, k; scanf("%d %d\n", &n, &k);
	string s;
	getline(cin, s);
	solve(s, k);
}