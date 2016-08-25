#include <vector>
#include <iostream>
using namespace std;

class CoinReversing{
public:
	double expectedHeads(int N, vector<int>& a){
		int k = a.size();
		int i=1;
		double q = 1.0; // q is probability a coin is heads after i-1 flips

		for (;i <= k; i++) {
			// calcuate probability that a coin will be flipped
			int choose = a[i-1];
			// n-1Ck-1/nCk = probability a coin will be fl
			double flipProbab = choose/(double)N;
			q = flipProbab*(1.0-q) + (1.0 - flipProbab)*q;
		}

		return N*q;
	}
};


int main(){
	int N,k;
	cin >> N >> k; vector<int> b;
	for (int i=0; i < k; i++){
		int curr; cin >> curr;
		b.push_back(curr);
	}

	CoinReversing obj;
	double ans = obj.expectedHeads(N, b);
	cout << ans << "\n";
}