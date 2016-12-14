#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;


int main() {
	int n,k;
	scanf("%d %d\n", &n,&k);
	string s; getline(cin, s);
	int hopper, insect;
	for (int i=0; i < n; i++) {
		if (s[i] == 'G') hopper = i;
		if (s[i] == 'T') insect = i;
	}

	if (abs(hopper - insect) % k){
		cout << "NO\n";
		return 0;
	}

	else {
		int dir;
		if (hopper > insect) 
			dir = -1;
		else 
			dir = 1;

		while (hopper != insect) {
			int curr = hopper + (dir*k);
			if (s[curr] == '#') {
				cout << "NO\n"; return 0;
			}
			hopper = curr;
		}
		cout << "YES\n"; return 0;
	}
}