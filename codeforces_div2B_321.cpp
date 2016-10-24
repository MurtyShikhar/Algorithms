#include <vector>
#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(vector<pair<int,int> >& fr, int d){
	sort(fr.begin(), fr.end());
	int l=0, r=0;
	int n = fr.size();
	long long ans =0;
	while (r < n && fr[r].first - fr[l].first < d) {
		ans += fr[r].second;
		r++;
	}

	long long curr = ans;
	curr -= fr[l].second;
	curr += fr[r].second;
	l++; // consider 1...r

	while (l < n && r < n) {
		if (fr[r].first - fr[l].first < d){
			if (curr > ans) {
				ans = curr;
			}

			r++;
			if (r < n)
				curr += fr[r].second;
		}

		else {
			curr -= fr[l].second;
			l++;
		}

	}

	cout << ans << "\n";
}

int main() {
	int n,d; scanf("%d %d", &n, &d);
	vector<pair<int,int> > fr(n);
	for (int i=0; i< n; i++) {
		int a,b; scanf("%d %d", &a, &b);
		fr[i] = make_pair(a,b);
	}

	solve(fr, d);
}