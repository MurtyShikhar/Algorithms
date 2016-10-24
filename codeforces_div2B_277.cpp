#include <vector>
#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(vector<int>& b, vector<int>& g) {
	sort(b.begin(), b.end());
	sort(g.begin(), g.end());
	int bi=0,gi=0;
	int bsz = b.size(), gsz = g.size();
	int ans=0;
	while (bi < bsz &&  gi < gsz) {
		if (abs(b[bi] - g[gi]) <= 1){
			ans +=1;
			bi++; gi++;
		}

		else if (b[bi] > g[gi]) gi++;
		else bi++;
	}

	cout << ans << "\n";
}

int main() {
	int n, m; scanf("%d", &n);
	vector<int> b(n);
	for (int i=0; i < n; i++) scanf("%d", &b[i]);

	scanf("%d", &m);
	vector<int> g(m);
	for (int i=0; i < m; i++) scanf("%d", &g[i]);
	solve(b,g);	
}