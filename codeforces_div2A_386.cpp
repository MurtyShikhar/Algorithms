#include <cstdio>
#include <iostream>

using namespace std;
/* 7x where x <= a, 2*x <= b, 4x <= c */
int main() {
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	int t1 = 0, t2 = 0, t3 = 0;
	int x = a;
	for (; x >= 1; x--) {
		if (2*x <= b && 4*x <= c) break;
	}

	cout << 7*x << "\n";
}