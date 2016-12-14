#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int n, n1, n2;
	scanf("%d %d %d", &n, &n1, &n2);
	vector<int> arr(n);
	for (int i=0; i < n; i++) scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());
	/* 
		n2*sum_of_n1 + n1*sum_of_n2
		if n2 > n1

	 */
	ll s1 = 0;
	ll s2 = 0;
	int idx = n-1;
	int taken=0;
	if (n2 > n1) {
		while (taken != n1) {
			s1 += arr[idx]; idx--; taken +=1;
		}
		taken=0;
		while (taken != n2) {
			s2  += arr[idx]; idx--; taken +=1;
		}

	}

	else {
		while (taken != n2) {
			s2 += arr[idx]; idx--; taken +=1;
		}
		taken=0;
		while (taken != n1) {
			s1  += arr[idx]; idx--; taken +=1;
		}
	}


	double avg = ((double)s1/n1 ) + ((double)s2/n2);
	printf("%5.8f\n", avg);
	//cout << avg << "\n"; return 0;
}