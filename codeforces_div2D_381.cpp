#include <cstdio>
#include <vector>
#include <iostream>


using namespace std;

typedef long long ll;

vector<int> vw; // vertex weights
vector<vector<pair<int,int> > > tree; 
vector<ll> root_dist; // stores distance from root. this array gets populated as we dfs
vector<int> ans; 
vector<ll> dp;


int visit(int curr, int parent ,ll dist) {
	ans.push_back(curr); 
	root_dist[curr] = dist;
	// ans contains a list of ancestor indices a1, a2, ..... an, curr such that root_dist[a1] < root_dist[a2] < root_dist[a3] ... < root_dist[curr]
	// we need the last ancestor ai such that root_dist[curr] - vw[curr] > root_dist[ai] or we need the closest ancestor such that its root_dist is less than target

	ll target = root_dist[curr] - vw[curr];
	int lo = 0, hi = ans.size() - 1;


	while (lo < hi) {
		int mid = lo + (hi-lo+1)/2;
		ll curr = root_dist[ans[mid]];
		if (curr >= target) /* everything from mid...hi is greater or equal */
			hi = mid-1;
		else lo = mid;	/* everything from lo...mid is a possibility */
	}

	/* lo is the closest ancestor such that its root_dist is less than target. 
	   hence we reduce its dp value by 1. (later when we fix cumulatives)
	   all the ancestors of lo will also get decremented by 1.
	 */

	if (ans.size() != 1 && target > root_dist[ans[lo]])
		dp[ans[lo]]--;

	/* increment the dp value of the parent regardless of anything. This might get decremented in the future. (or already has if ans[lo] == parent) */
	if (parent != -1)
		dp[parent]++;

	for (int i=0; i < tree[curr].size(); i++) {
		pair<int,int> aa = tree[curr][i];
		if (aa.first != parent)
			visit(aa.first, curr, dist+aa.second);
	}

	ans.pop_back();

}

void fix_cumulatives(int curr, int parent) {
	int num_children = tree[curr].size();
	for (int i = 0; i < num_children; i++) {
		int child = tree[curr][i].first;
		if (child != parent)
			fix_cumulatives(child, curr);
		dp[curr] += dp[child];
	}
}

int main() {
	int n; scanf("%d", &n);
	vw.resize(n);
	tree.resize(n);
	root_dist.resize(n);
	dp.resize(n);

	for (int i=0; i < n; i++) scanf("%d", &vw[i]);

	for (int i=0; i < n-1; i++) {
		int a, b; scanf("%d %d", &a, &b); a--;
		tree[a].push_back(make_pair(i+1, b));
	}

	visit(0, -1, 0);
	fix_cumulatives(0, -1);
	for (int i=0; i < n; i++)
		cout << dp[i] << " ";
	cout << "\n";	
}