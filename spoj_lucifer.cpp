#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <iostream>

#define MOD 1000000007

using namespace std;

//int prms[29] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};

long long dp[12][51][51][2];

void reset() {
	for (int i=0; i< 12; i++) {
		for (int j=0; j < 51; j++) {
			for (int k=0; k < 51; k++) {
				for (int l=0; l < 2; l++)
					dp[i][j][k][l]=-1;
			}
		}
	}
}

// bool isPrime(long long x){
// 	if(x<0)
// 		return 0;
// 	for(int i=0;i<29;i++)
// 		if(prms[i]==x)
// 			return 1;
// 	return 0;
// }

bool isPrime(long long x) {
	if (x <= 0)
		return 0;
	else if (x == 1)
		return 0;

	for (long long i=2; i*i <= x; i++) {
		if ((x % i) == 0)
			return 0;
	}

	return 1;
}



long long digitDP(int i, int even, int odd, int lo, string& Y){
	int n = Y.length();
	if (i == n){
		return isPrime(even-odd);
	}

	if (dp[i][even][odd][lo] != -1)
		return dp[i][even][odd][lo];

	long long ret =0;
	int maxD = lo ? 9 : (Y[i]-'0');
	for (int d=0; d <= maxD;  d++) {
		int newOdd =odd, newEven = even;
		// 100
		if ((Y.size() - i)%2){
			newOdd += d;
		}
		else{
			newEven +=d;
		}
		int newLo = lo || (Y[i] - '0') > d;
		long long tmp= digitDP(i+1, newEven, newOdd,  newLo, Y);
		ret = (ret + tmp)%MOD;
	}

	ret %= MOD;
	dp[i][even][odd][lo]=ret;
	return ret;
}


long long solve(long long s) {
	reset();
	char buff[50];
	sprintf(buff,"%lld",s);
	string tmp(buff);
	//cout << "debug " << tmp << "\n";
	return digitDP(0, 0, 0,0,tmp);
}


int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		long long a,b;
		scanf("%lld", &a); scanf("%lld", &b);
		if (a==0)
			printf("%lld\n",solve(b));
		else
			printf("%lld\n",(MOD + solve(b)-solve(a-1)) %MOD);
	}
	return 0;
}    
