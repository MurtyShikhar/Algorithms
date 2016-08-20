#include <iostream>
#include <vector>
#include <set>

using namespace std;

class HandShaking{
public:
	long countPerfect(int n) {
		vector<int> f(n+1,0);
		f[2] = 1;
		f[0] = 1;
		for (int i=4; i <= n; i+=2) {
			for (int j=0; j <= i-2; j+=2)
				f[i] += (f[j]*f[i-j-2]);
		}

		return f[n];
	}
};


int main() {
	int n; cin >> n;
	HandShaking obj;
	int ans = obj.countPerfect(n);
	cout << ans << "\n";
}
