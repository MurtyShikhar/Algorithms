#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int,int> > > tree; 
vector<int> special;
vector<int> ssum;
long long total;
int m;

int dfs(int v, int p) {
	ssum[v] = special[v] ? 1 : 0;

	int num_children = tree[v].size();
	for (int i=0; i < num_children; i++) {
		int curr_child = tree[v][i].first;
		if (curr_child == p) continue;

		int curr_dist = tree[v][i].second;
		dfs(curr_child, v);
		ssum[v] += ssum[curr_child];
		/* edge is v --- curr_child */
		total += 2*curr_dist*ssum[curr_child]*(m - ssum[curr_child]);
	}

}

long long gcd(long long a, long long b) {
	while (b) {
		a %= b;
		swap(a,b);
	}

	return a;
}

int main() {
	int n;
	cin >> n >> m;
	total = 0;
	tree.resize(n);
	special.resize(n,0); ssum.resize(n,0);

	for (int i=0; i < n-1; i++) {
		int a,b,c;
		cin >> a >> b >> c; --a; --b;
		tree[a].push_back(make_pair(b,c));
		tree[b].push_back(make_pair(a,c));
	} 

	for (int i=0; i < m; i++) {
		int v; cin >> v; special[--v] = 1;
	}

	dfs(0, -1);
	long long numer = total; long long denom = m*(long long)m;
	long long g = gcd(numer, denom);
	numer /= g; denom /= g;

	cout << numer << " " << denom << "\n";
}