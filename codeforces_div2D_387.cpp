#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> temps(n,0);
	int negs=0;
	for (int i=0; i < n; i++) {scanf("%d", &temps[i]); if (temps[i] < 0) negs+=1;}
	if (negs > k) {printf("-1\n"); return 0;}
	
	int leeway = k - negs;	
	int i=0;
	while (i < n && temps[i] >= 0) i++; //ignore the first positive segment
	if (i == n) {cout << "0\n"; return 0;}
	vector<int> pos_segs;
	while (i < n) {
		int len = 0;
		while (i< n && temps[i] >= 0) {i++; len++;}
		if (len == 0) i++;
		else pos_segs.push_back(len);
	}

	int sz = pos_segs.size();
	if (sz == 0) {cout << "1\n"; return 0;}

	int	en_len = temps[n-1] >= 0 ? pos_segs[sz-1] : 0;	
	int ans = (2*sz)+1;

	if (en_len){
		ans -=1;
		pos_segs.pop_back();
		sz--;
	}

	sort(pos_segs.begin(), pos_segs.end());

	for (int i=0; i < sz; i++) {
		if (pos_segs[i] <= leeway) {
			leeway -= pos_segs[i]; ans -=2;
		}
	}


	if (en_len && en_len <= leeway) ans--;

	cout << ans << "\n";

}