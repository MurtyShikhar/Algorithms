#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <iostream>

#define MOD 1000000007

using namespace std;

long long dp[51][20][20][20][2];

void reset() {
	for (int i=0; i < 51; i++) {
		for (int j=0; j <20; j++){
			for (int k=0; k <20; k++){
				for (int l=0; l < 20; l++){
				for (int lo=0; lo <2;lo++){
					dp[i][j][k][l][lo] = -1;
				}
				}
			}
		}
	}
}

long long digitDP(int i, int n3, int n6, int n9, int lo, string& Y){
	int n = Y.length();
	if (i == n){
		return n3 > 0 && n3 == n6 && n6 == n9;
	}
	else if (n3 > 16 || n6 > 16 || n9 > 16 )
		return 0;

	if (dp[i][n3][n6][n9][lo] != -1)
		return dp[i][n3][n6][n9][lo];

	long long ret =0;
	int maxD = lo ? 9 : Y[i]-'0';
	for (int d=0; d <= maxD;  d++) {
		long long tmp=digitDP(i+1,n3+(d==3),n6+(d==6),n9+(d==9),lo||(Y[i]-'0')>d, Y);
		ret = (ret + tmp)%MOD;
	}

	ret %= MOD;
	dp[i][n3][n6][n9][lo]=ret;
	return ret;
}

long long solve(string& s) {
	reset();
	return digitDP(0, 0, 0, 0,0,s);
}


int main() {
	int tc; scanf("%d\n", &tc);
	while(tc--) {
		stringstream ss; string s;
		getline(cin, s);
		ss << s;
		string a,b;
		ss >> a >> b;

		int curr = a.length()-1;
		while (curr >= 0 && a[curr]=='0')
			curr--;

		if (curr == -1)
			cout << solve(b) << "\n";
		
		else {
			a[curr] = ((a[curr] - '0')-1) + '0';
			curr++;
			while (curr < a.size()){
				a[curr] = '9';
				curr++;
			}
			//cout << a << "\n";
			cout << (MOD + solve(b) - solve(a))%MOD << "\n";
		}

	}
}