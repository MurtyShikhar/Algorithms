#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

class NumbersChallenge{
public:
	int MinNumber(vector<int>& S) {
		int MAX = 20*100000+1;
		vector<int> possible(MAX+1, 0);
		int k = S.size();
		int n = 1<< k;
		for (int i=1; i < n; i++) {
			int s = 0;
			for (int j=0; j <k; j++){
				if (i & (1<<j))
					s += S[j];
			}

			possible[s]=1;
		}

		int ans=-1;
		for (int i=1; i <= MAX; i++) {
			if (!possible[i]){
				ans = i;
				break;
			}
		}

		return ans;

	}
};

int main() {
	int n; cin>>n;
	vector<int> S(n);
	for (int i=0; i < n; i++) scanf("%d", &S[i]);
	NumbersChallenge obj;
	int ans = obj.MinNumber(S);
	cout << ans << "\n";
}