#include <set>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


int main()
{
	int n; scanf("%d", &n);
	map<int, int> up;
	map<int,int> down;

	set<int> colors;
	for (int i=0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if (a == b) {
			up[a]++;
		}

		else{
			up[a]++; down[b]++;
		}
		colors.insert(a); colors.insert(b);
	}

	int reqd = (n+1)/2;
	int minMoves = 1<<29;

	for (auto it = colors.begin(); it != colors.end(); it++) {
		int curr = *it;
		int possible = up[curr] + down[curr];
		if (possible < reqd)
			continue;
		else if (up[curr] >= reqd){
			cout << 0 << "\n";
			return 0;
		}

		else
			minMoves = min(minMoves, reqd - up[curr]);
	} 

	if (minMoves == 1<<29)
		cout << -1 << "\n";
	else
		cout << minMoves << "\n";
	return 0;
}