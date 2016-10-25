#include <set>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

#define MAX 10000001

using namespace std;


int main() {
	int n; scanf("%d", &n);
	vector<int> cnt(MAX,0);


	for (int i=0; i < n; i++){
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}

	int q; scanf("%d", &q);
	vector<pair<int,int> > queries(q);
	for (int i=0; i < q; i++) {
		int a, b; scanf("%d %d", &a, &b);
		queries[i] = make_pair(min(a, MAX-1),min(b, MAX-1));
	}

	// f[n] = cnt[n] + cnt[2*n] + cnt[3*n] + cnt[4*n] + ...

	vector<long long> pre(MAX, 0);
	vector<int> primes(MAX,1);
	for (int j=2; j < MAX; j+=2) {
		primes[j] = 0;
		pre[2] += cnt[j];
	}

	for (int i=3; i < MAX; i++) {
		if (primes[i]) {
			for (int j=i; j < MAX; j+=i) {
				primes[j]=0;
				pre[i] += cnt[j];
			}
		}

		pre[i] += pre[i-1];
	}


	for (int i=0; i < q; i++) {
		int l = queries[i].first; 
		int r = queries[i].second;
		cout << pre[r] - pre[l-1] << "\n";
	}
}