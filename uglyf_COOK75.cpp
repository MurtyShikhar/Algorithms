#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int evaluate(int curr, int a[]) {
	int ans =0;
	for (int i=0; i < 4; i++)
		ans += abs(a[i] - curr);
	return ans;
}

int bin_search(int ai, vector<int>& s2_idx, int a[]){

	int idx = lower_bound(s2_idx.begin(), s2_idx.end(), ai) - s2_idx.begin();
	if (idx == s2_idx.size())
		return evaluate(s2_idx[idx-1], a);
	else{
		if (s2_idx[idx] == ai)
			return evaluate(ai, a);
		else{
			if (idx == 0)
				return evaluate(s2_idx[idx], a);

			int ans1 = evaluate(s2_idx[idx-1], a);
			int ans2 = evaluate(s2_idx[idx], a);
			return min(ans1, ans2);
		}
	}
}


void solve(string& s1, string& s2) {
	//cout << s1 << " " << s2 << "\n";
	vector<vector<int> > s1_idx(26);
	vector<vector<int> > s2_idx(26);
	int s1_sz = s1.size(), s2_sz = s2.size();
	for (int i=0; i < s1_sz; i++) {
		s1_idx[s1[i]-'A'].push_back(i);
	}

	for (int i=0; i < s2_sz; i++) {
		s2_idx[s2[i]-'A'].push_back(i);
	}

	int a[] = {0,0,0,0};

	int ans = 1<<29;
	// assume happens at ith char
	for (int i = 0; i < 26; i++) {
		if (s2_idx[i].size() == 0)
			continue;
		for (int j=0; j < s1_idx[i].size(); j++) {

			int idx = s1_idx[i][j];
			a[0] = idx;
			a[1] = s2_sz - idx-1;
			a[2] = s2_sz - s1_sz + idx;
			a[3] = s1_sz - idx-1;
			if (a[2] < 0 || a[3] < 0 || a[0] < 0 || a[1] < 0) continue;

			for (int k=0; k < 4; k++){
				ans = min(bin_search(a[k], s2_idx[i], a), ans);
			}
		}
	}


	printf("%d\n", ans);
}

int main() {
	int tc; scanf("%d\n", &tc);
	while (tc--) {
		string s1,s2;
		getline(cin,s1); getline(cin, s2);
		solve(s1,s2);
	}
}