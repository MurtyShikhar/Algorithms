#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long dp[20][20][20];

void reset(){
	for (int i=0; i < 20; i++) {
		for (int j=0; j < 20; j++){
			for (int k=0; k < 20; k++)
				dp[i][j][k]=-1;
		}
	}
}

string itos2(long long number){
	string s;
	while (number/10) {
		s.push_back((number%10)+'0');
		number /=10;
	}

	s.push_back( (number%10) + '0');
	reverse(s.begin(), s.end());
	return s;
}

long long func(int i, int lo, int hi, string& Y) {
	if (dp[i][lo][hi] != -1) return dp[i][lo][hi];
	if (i == Y.length()-1){
		if (lo <= hi) return 1; // the new number created is <= Y
		else return 0;
	}

	long long res = 0;
	int start;
	if (i==0) start=1; // don't start with a 0
	else start=0;

	for (int d=start; d <= 9; d++) {
		int lo1=lo, hi1=hi;
		if (d < Y[i]-'0') lo1=min(lo1, i);
		// fix both 0th and the last 
		if ((i==0) && (d < (Y[Y.length()-1]-'0')) && Y.length()-1 < lo1) lo1=Y.length()-1;

		if ((d > Y[i]-'0') && i < hi1) hi1=i;
		if ((i==0) && (d > (Y[Y.length()-1]-'0')) && Y.length()-1 < hi1) hi1=Y.length()-1;

		res += func(i+1, lo1, hi1, Y);
	}

	dp[i][lo][hi]=res;
	return res;
}


long long count(long long x) {
	long long res =0;
	if (x <= 9) return x+1;
	else if (x >= 10) {
		res += 10;
		for (int i=2; i < 19; i++) {
			long long curr = pow(10, i);
			if (x >= curr)
				res += 9*(curr/100); 
			else break;
		}

		reset();
		string temp = itos2(x);
		res += func(0, temp.length(), temp.length(), temp);
	}

	return res;
}

int main() {
	long long l, r; 
	cin >> l >> r;
	//cout << itos(l) << "\n";
	//cout << itos(r) << "\n";

	cout << count(r) - count(l-1) << "\n";
}