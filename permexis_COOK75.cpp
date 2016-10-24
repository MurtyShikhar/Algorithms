#include <vector>
#include <cstdio>
#include <unordered_map>
#include <algorithm>

using namespace std;


void solve2(vector<int>& arr) {
	int n = arr.size();
	sort(arr.begin(), arr.end());
	for (int i=0; i < n-1; i++) {
		int diff = arr[i+1] - arr[i];
		if (diff > 1){
			printf("NO\n");
			return;
		}
	}

	printf("YES\n");
}

int main() {
	int tc; scanf("%d\n", &tc);
	while (tc--) {
		int n; scanf("%d\n", &n);
		vector<int> arr(n,0);
		for (int i=0; i < n; i++)
			scanf("%d", &arr[i]);
		solve2(arr);
	}
}