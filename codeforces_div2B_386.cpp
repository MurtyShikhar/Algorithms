#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n; string s; scanf("%d\n", &n); getline(cin, s);
	vector<char> out(n);
	//int dir = -1;
	int mid = (n-1)/2;

	int idx = 1, cnt = 1;
	out[mid] = s[0];

	int flag = 1;
	if (n%2 == 0) {
		flag = -1;
	}

	while (idx < n) {
		int off = mid - (flag*cnt);
		out[off] = s[idx];
		idx++;

		if (idx < n) {off = mid + (flag*cnt); out[off] = s[idx]; cnt++; idx++;}
	}

	string res(out.begin(), out.end());
	cout << res << "\n";

}