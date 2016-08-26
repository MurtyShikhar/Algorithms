#include <vector>
#include <iostream>
#include <map>

using namespace std;

class TheTicketsDivTwo{
public:
	double find(int n, int m, int k){
		vector<vector<vector<double> > > dp(n+1, vector<vector<double> >(n+1, vector<double>(k+1)));

		for (int lineSize=1; lineSize <= n; lineSize++)
			dp[lineSize][1][0] = 1.0;

		for (int turn=1; turn <= k; turn++) {
			dp[1][1][turn]=1.0;
			for (int lineSize=2; lineSize <= n; lineSize++) {
				dp[lineSize][1][turn] = (1.0/6.0) + (0.5*dp[lineSize][lineSize][turn-1]);
				for (int idx=2; idx <= lineSize; idx++) {
					dp[lineSize][idx][turn] = ((2.0/6.0)*dp[lineSize-1][idx-1][turn-1])+ ((0.5)*dp[lineSize][idx-1][turn-1]);

				}
			}
		}

		return dp[n][m][k];

	}
};


int main() {
	int n,m,k;
	cin >> n >> m >> k;
	TheTicketsDivTwo obj;
	double ans = obj.find(n,m,k);
	cout << ans << "\n";
}