#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

#define INF 1<<20
#define MAXN 5000
using namespace std;

typedef vector<vector<int> > vvi;
/* paint(l, r, layer) =  (min(l,r) - layer) +  paint(l, min-1,  min(l,r)) + paint(r, min-1,  min(l,r)), l-r+1*/

int h[MAXN];

// layer = amount that has been painted so far in this range
int paint(int l, int r, int layer, vvi& minId){
	if (l > r) return 0;
	int min_range = minId[l][r];
	int h_strokes = paint(l, min_range-1, h[min_range], minId) + paint(min_range+1, r, h[min_range], minId) + h[min_range] -layer; 
	return min(r-l+1, h_strokes);
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i < n; i++) scanf("%d", &h[i]);

	vector<vector<int> > minId(n, vector<int>(n, 0));
	for (int i=0; i < n; i++) {
		minId[i][i] = i;
	}

	for (int i=0; i < n; i++) {
		for (int j=i+1; j < n; j++) {
			minId[i][j] = h[minId[i][j-1]] > h[j] ? j : minId[i][j-1];
		}
	}

	int ans = paint(0, n-1, 0, minId);
	cout << ans << "\n";
	
}	