#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s1, s2;

	getline(cin, s1);
	getline(cin, s2);

	int n2 = s2.size();
	vector<int> aux(n2, 0); // aux[i] = number of 1s from 0..i
	aux[0] = s2[0]=='1';
	for (int i=1; i < n2; i++)
		aux[i] = aux[i-1] + (s2[i]=='1');

	int n1 = s1.size();
	int numOnes=aux[n2-n1];
	int numZeros=(n2-n1+1) - numOnes;
	long long ans=0;
	if (s1[0]=='1')
		ans += numZeros;
	else
		ans += numOnes;

	for (int i=1; i < n1; i++) {
		// last one is (n2 - n1) .. (n2 -1)
		int numOnes = aux[n2-n1 + i] - aux[i-1];
		int numZeros = (n2 - n1 +1) - numOnes;
		if (s1[i] == '1')
			ans += numZeros;
		else 
			ans += numOnes;
	}

	cout << ans << "\n";

}