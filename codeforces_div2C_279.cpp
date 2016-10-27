#include <vector>
#include <cstdio>

using namespace std;
/* new problem. Had to take hints. Revise */
int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> arr(n,0);
	for (int i=0; i < n; i++)
		scanf("%d", &arr[i]);

	vector<int> nonDec(n,-1); // nonDec[i] stores the largest j such that arr[i]<=arr[i+1]...<=arr[j]
	vector<int> nonInc(n,-1); // nonInc[i] stores the smallest j such that arr[j]>=arr[j+1]>=...arr[i]

	nonDec[n-1]=n-1;
	for (int i=n-2; i >= 0; i--) {
		if (arr[i] <= arr[i+1])
			nonDec[i] = nonDec[i+1];
		else
			nonDec[i] = i;
	}

	nonInc[0]=0;
	for (int i=1; i < n; i++) {
		if (arr[i-1] >= arr[i])
			nonInc[i] = nonInc[i-1];
		else
			nonInc[i] = i;
	}


	for (int i=0; i < m; i++) {
		int l, r; scanf("%d %d", &l, &r);
		l--; r--;
		if (nonDec[l] >= nonInc[r])
			printf("Yes\n");
		else
			printf("No\n");
	}
}