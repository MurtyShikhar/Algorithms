#include <set>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool canFit(vector<int>& s, int k, long long currSize) {
	int n = s.size();

	int i=0, j=n-1;
	int used=0;
	while (used < k){
		if (i > j)
			return true;

		else if (i==j) {
			if (s[i] <= currSize) 
				return true;
		}

		// i < j
		if (s[i] + (long long)s[j] <= currSize) {
			i++;
			j--;

		}

		else if (s[j] > currSize)
			return 0;
		else {
			j--;
		}

		used++;
	}

	return (i > j);

}


int main() {
	int n, k; 
	scanf("%d %d", &n, &k);
	vector<int> s(n,0);
	long long r = 0;
	for (int i=0; i < n; i++){
		scanf("%d", &s[i]);
		r += s[i];
	}

	long long ans = r;
	long long l = 0;
	while (l <= r) {
		long long mid = l + (r-l)/2;
		bool fit = canFit(s, k, mid);
		//printf("%d %d %d %d\n", l, r, mid, fit);
		if (fit){
			r = mid-1;
			ans = min(ans, mid);
		}
		else
			l = mid+1;
	}

	cout << ans << "\n";
}