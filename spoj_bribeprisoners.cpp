#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;


int main(){
	int tc; scanf("%d", &tc);
	for (int t=1; t <= tc; t++){
		int p, q; scanf("%d %d", &p, &q);
		vector<int> release(q,0);
		for (int i=0; i < q; i++){
			scanf("%d", &release[i]);
			release[i]--;
		}

		// dp[i][j] = min number of coins = j-i + dp[i][p[i]-1] + dp[p[i]+1][j]
		// dp[i][j] = 0 if j > i

		vector<vector<int> > dp(p, vector<int>(p, 0));

		for (int sz = 2; sz <= p; sz++) {
			for (int i=0; i <= p-sz; i++){
				int j = i+sz-1;
				int ans = 1<<20;
				for (int k=0; k < q; k++) {
					if (release[k] == i)
						ans = min(ans, dp[i+1][j]);
					else if (release[k]==j)
						ans = min(ans, dp[i][j-1]);
					else if (release[k] > i && release[k] < j)
						ans = min(ans, dp[i][release[k]-1] + dp[release[k]+1][j]);
				}

				if (ans == 1<<20)
					dp[i][j] = 0;
				else
					dp[i][j] = (j-i)+ans;
			}
		}

		printf("Case#%d: %d\n", t, dp[0][p-1]);

	}
}