#include <cstdio>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	set<string> perms;
	string s; getline(cin, s);
	perms.insert(s);

	int n = s.size();
	for (int i=0; i < n; i++) {
		s = s[n-1] + s.substr(0, n-1);
		perms.insert(s);
	}

	cout << perms.size() << "\n";
}