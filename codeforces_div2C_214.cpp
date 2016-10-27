#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct pairhash {
public:
  template <typename T, typename U>
  size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

typedef unordered_map<pair<int,int>, int, pairhash> hashMap;

int solve(int currCapacity, int idx, vector<int>& costs, vector<int>& value, vector<vector<int> >& memo) {
	//auto it = memo.find(make_pair(currCapacity, idx));
	//if (it != memo.end()) return it->second;
	int n = costs.size();
	if (idx == n) {
		if (currCapacity == 0) return 0;
		else return -(1<<20);
	}

	if (memo[idx][currCapacity + 100000] != -1)
		return memo[idx][currCapacity+100000];



	int c1 = solve(currCapacity, idx+1, costs, value, memo);
	int c2 = solve(currCapacity-costs[idx], idx+1, costs, value, memo) + value[idx];
	int ans = max(c1,c2);
	if (currCapacity == 0)
		ans = max(ans, 0);

	memo[idx][currCapacity+100000] = ans;
	return ans;
}

int main() {
	int n,k; scanf("%d %d", &n, &k);
	vector<int> cost(n,0);
	vector<int> value(n,0);

	for (int i=0; i < n; i++) 
		scanf("%d", &value[i]);

	for (int i=0; i < n; i++) {
		scanf("%d", &cost[i]);
		cost[i] = value[i] - k*cost[i];
	}

	vector<vector<int> > memo(n, vector<int>(210001, -1));
	int ans = solve(0, 0, cost, value, memo);
	if (ans == 0)
		printf("-1\n");
	else
		printf("%d\n", ans);
}