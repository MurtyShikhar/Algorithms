#include <vector>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
#define MAX 500
/* very interesting problem.
   note that the exact dp state is 
   dp(lines, bugs, i) = dp(lines, bugs, i-1)      + dp(lines-1, bugs-a[i], i)
					(ith guy doesn't write code)    (ith guy wrote atleast one line)
	
	can collapse the table though and get rid of the last dimension to avoid memory blowup
 */

int main() {
	int n, m, b, mod;
	scanf("%d %d %d %d", &n,&m,&b,&mod);
	vector<int> bugs(n,0);

	for (int i=0; i < n; i++) 
		scanf("%d", &bugs[i]); 

	long long dp[MAX+1][MAX+1];
	for (int i=0; i <=MAX; i++){
		for (int j=0; j <=MAX; j++){
				dp[i][j]=0;
		}
	}

	dp[0][0]=1;
	for (int i=0; i < n; i++) {
		for (int numLines=1; numLines <= m; numLines++){
			for (int numBugs=bugs[i]; numBugs <= b; numBugs++) {
				dp[numLines][numBugs] = (dp[numLines][numBugs] + dp[numLines-1][numBugs-bugs[i]])%mod;
			}
		}
	}

	long long ans=0;
	for (int i=0; i <= b; i++) {
		ans = (ans + dp[m][i])%mod;
	}

	cout << ans << "\n";
}