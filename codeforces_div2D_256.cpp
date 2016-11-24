#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

/* print kth number in an n x m multiplication table ( (i,j) entry is i*j) */

long long find(long long x, int n, int m) {
	long long less_than =0;
	for (int i=1; i <= n; i++) less_than += min((long long)m, (x-1)/i);
	return less_than;
}

int main() {
	int n,m;
	long long k;
	scanf("%d %d", &n,&m);
	cin >> k;
	long long lo = 1, hi = (long long)n*m+1;
	/* answer is between [lo, hi) */
	while (lo < hi) {
		long long mid = lo + (hi - lo)/2;
		if (find(mid, n, m) < k) lo = mid+1;
		else hi = mid; 
	}

	cout << lo - 1 << "\n";
}