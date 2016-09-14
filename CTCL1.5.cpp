#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool editDist(string& a, string& b) {
	int l = a.size(), m = b.size();
	if (l!=m) {
		if (abs(l-m) >1) return false;
		vector<int> freqA(256,0);
		vector<int> freqB(256,0);
		for (int i=0; i < l; i++)
			freqA[a[i]]+=1;

		for (int i=0; i < m; i++)
			freqB[b[i]]+=1;

		int diff=0;
		for (int i=0; i < 256; i++) {
			int freqDiff = abs(freqA[i] - freqB[i]);
			if (freqDiff > 1) return false;
			else if (freqDiff==1) diff++;
		}
		return diff <= 1;
	} 

	else {
		int diff=0;
		for (int i=0; i < l; i++){
			if (a[i] != b[i]) diff++;
		}
		return diff<=1;
	}
}


int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	cout << editDist(a,b) << "\n";
}