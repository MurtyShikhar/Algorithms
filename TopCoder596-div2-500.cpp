#include <vector>
#include <iostream>
using namespace std;


class ColorfulRoad{
public:
	int getMin(string& road){
		const int INF=(1<<20);
		int n = road.size();
		// dp[j] = ans for 0...j
		vector<int> dp(n);
		dp[0] = 0;
		for (int i=1; i < n; i++) {
			int res= INF;
			for (int j=0; j < i; j++) {
				int stepCost = (i-j)*(i-j);
				if (road[i]=='B' && road[j]=='G'|| road[i]=='G' && road[j]=='R' || road[i]=='R' && road[j]=='B')
					res = min(res, dp[j] + stepCost);
			}

			dp[i] = res;
		}

		if (dp[n-1]==INF) return -1;
		else return dp[n-1];
	}
};

int main() {
	string s; cin >> s;
	ColorfulRoad obj;
	int ans = obj.getMin(s);
	cout << ans << "\n";
}