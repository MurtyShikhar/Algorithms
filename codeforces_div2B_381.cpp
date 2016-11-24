#include <vector>
#include <iostream>
#include <set>
#include <cstdio>


using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> f(n);
	for (int i=0; i < n; i++) scanf("%d", &f[i]);

	vector<long long> sums(n,0);
	sums[0] = f[0];
	for (int i=1; i < n; i++)
		sums[i] = sums[i-1] + f[i];

	long long happ=0;
	for (int i=0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		a--; b--;
		long long curr=0;
		if (a == 0)
			curr = sums[b];
		else
			curr = sums[b] - sums[a-1];

		if (curr > 0)
			happ += curr;
	}

	cout << happ << "\n";
}