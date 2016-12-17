#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <vector>

#define mp make_pair
using namespace std;

typedef long long ll;


int n,k;
vector<int> is_gov;
vector<vector<int> > graph;
vector<int> visited;
int flag;
int num_edges;

int dfs(int curr, int parent) {
	int size_comp = 1;
	visited[curr] = 1;
	if (is_gov[curr])
		flag = 1;

	int num_children = graph[curr].size();
	for (int i=0; i < num_children; i++) {
		int child = graph[curr][i];

		if (visited[child] != 2 && child != parent)
			num_edges +=1;

		if (!visited[child]){
			size_comp += dfs(child, curr);
		}
	}

	visited[curr] = 2;
	return size_comp;
}


int main() {
	int m;
	scanf("%d %d %d", &n,&m,&k);
	is_gov.resize(n,0);
	graph.resize(n, vector<int>());
	visited.resize(n,0);

	for (int i=0; i < k; i++) {
		int a; scanf("%d", &a); a--;
		is_gov[a] = 1;
	}

	for (int i=0; i < m; i++) {
		int a, b; scanf("%d %d", &a,&b); a--; b--;
		graph[a].push_back(b); graph[b].push_back(a);
	}


	vector<pair<int,int> > gov_components;
	vector<pair<int,int> > non_gov_components;
	int largest_gov=-1;
	ll non_gov_sum = 0;

	for (int i=0; i < n; i++) {
		if (visited[i] == 0) {
			flag = 0;
			num_edges = 0;
			int size_comp = dfs(i, -1);
			//cout << num_edges << "\n";
			if (flag) {
				largest_gov = max(largest_gov, size_comp);
				gov_components.push_back(mp(size_comp, num_edges));
			}
			else{
				non_gov_sum += size_comp;
				non_gov_components.push_back(mp(size_comp, num_edges));
			}
		}
	}


	ll ans = (ll)largest_gov*non_gov_sum;
	int csize = non_gov_components.size();
	for (int i=0; i < csize; i++) {
		ll curr_size = non_gov_components[i].first;
		ll curr_edges = non_gov_components[i].second;
		ans += (curr_size*(curr_size-1)/2) - curr_edges;
		for (int j= i+1; j < csize; j++) {
			ll size_2 = non_gov_components[j].first;
			ans += curr_size*size_2;
		}
	}

	csize = gov_components.size();
	for (int i=0; i < csize; i++) {		
		ll curr_size = gov_components[i].first;
		ll curr_edges = gov_components[i].second;
		ans += (curr_size*(curr_size-1)/2) - curr_edges;
	}


	cout << ans << '\n';
}