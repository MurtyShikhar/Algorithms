#include <vector>
#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(vector<int>& a, long long sum) {
	int n = a.size();
	int l=0, r=0; // 0..l-1 -> left, l...r -> mid, r+1...n-1 right
	long long ways =0;
	long long s3 = sum/3; 
	vector<long long> sums(n, 0);
	vector<long long> aux_sum(n,0);
	vector<int> cnts(n,0);
	sums[0] = a[0];
	for (int i=1; i < n; i++) {
		sums[i] = sums[i-1] + a[i];
	}

	aux_sum[n-1] = a[n-1];
	for (int i=n-2; i >= 0; i--) {
		aux_sum[i] = aux_sum[i+1] + a[i]; 
	}

	for (int i=0; i < n; i++) {
		if (aux_sum[i] == s3)
			aux_sum[i]=1;
		else
			aux_sum[i]=0;
	}

	cnts[n-1] = aux_sum[n-1];
	for (int i=n-2; i >= 0; i--) {
		cnts[i] = aux_sum[i] + cnts[i+1];
	}


	for (int i=0; i < n-2; i++) {
		if (sums[i] == s3) {
			ways += cnts[i+2];
		}
	}

	cout << ways << "\n";
}

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n);
	long long sum=0;
	for (int i=0; i <n;i++){ 
		scanf("%d", &a[i]);
		sum += a[i];
	}

	if (sum%3)
		cout << 0 << "\n";
	else
		solve(a, sum);
}