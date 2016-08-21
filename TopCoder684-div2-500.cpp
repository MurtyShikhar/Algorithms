#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// learning: Came up with dp state on my own, but missed the fact that number of divisors of a number are much lesser than O(n). 
// Hence reduce O(n*k*k) to O(n*k*divisors(k))
class DivFreed2{
public:
	int count(int n, int k){
		if (n==1) return k;

		const int MOD = 1000000007;
		vector<vector<int> > dp(k+1, vector<int> (n, 0));
		vector<vector<int> > divisors(k+1);

		for (int i=1; i <= k; i++) {
			for (int j=2*i; j <= k; j +=i)
				divisors[j].push_back(i);
		}


		for (int i=1; i <=k; i++) {
			dp[i][n-1] = (k-divisors[i].size());
		}

		for (int j=n-2; j >=1; j--) {
			int sum=0;
			for (int p=1; p <= k; p++)
				sum = (sum + (long long) dp[p][j+1])%MOD;

			for (int i=1; i <= k; i++) {
				int curr = sum;
				for (int t=0; t < divisors[i].size(); t++){
					int divCurr = divisors[i][t];
					curr = curr - dp[divCurr][j+1];
					if (curr < 0) curr += MOD;
				}

				dp[i][j] = curr;
			}
		}

		int sum=0;
		for (int i=1; i <= k; i++)
			sum = (sum + (long long)dp[i][1])%MOD;
		return sum;
			
	}
};

int main() {
	int n,k; cin>>n>>k;
	DivFreed2 obj;
	int ans = obj.count(n,k);
	cout << ans << "\n";
}