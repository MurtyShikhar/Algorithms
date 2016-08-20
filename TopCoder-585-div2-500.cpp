// dp easy

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class TrafficCongestionDivTwo {
public:
	long theMinCars(int treeHeight) {
		long curr = 4;
		long fOdd = 1;
		long fEven= 3;
		for (int i=3; i <= treeHeight; i++) {
			if (i%2)
				fOdd += curr;
			else
				fEven += curr;

			curr *= 2;
		}

		if (treeHeight%2)
			return fOdd;
		else
			return fEven;
	}
};

int main() {
	int n; cin >> n;
	TrafficCongestionDivTwo obj;
	long ans = obj.theMinCars(n);
	cout << ans << "\n";
}