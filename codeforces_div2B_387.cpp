#include <iostream>
#include <string>
#include <cstdio>


using namespace std;

int main() {
	int n; scanf("%d\n", &n);
	string genome; getline(cin, genome);
	if (n % 4) {printf("===\n"); return 0;}
	int a=0, g=0, c=0, t=0;
	for (int i=0; i < n; i++) {
		if (genome[i] == 'A') a++;
		else if (genome[i] == 'G') g++;
		else if (genome[i] == 'C') c++;
		else if (genome[i] == 'T') t++;
	}

	int i = 0;
	while (i < n && a != n/4) {
		if (genome[i] == '?') {genome[i] = 'A'; a++;}
		i++;
	}

	if (a != n/4) {printf("===\n"); return 0;}
	i = 0;
	while (i < n && g != n/4) {
		if (genome[i] == '?') {genome[i] = 'G'; g++;}
		i++;
	}

	if (g != n/4) {printf("===\n"); return 0;}
	i = 0;
	while (i < n && c != n/4) {
		if (genome[i] == '?') {genome[i] = 'C'; c++;}
		i++;
	}
	if (c != n/4) {printf("===\n"); return 0;}
	i = 0;
	while (i < n && t != n/4) {
		if (genome[i] == '?') {genome[i] = 'T'; t++;}
		i++;
	}
	if (t != n/4) {printf("===\n"); return 0;}

	cout << genome << "\n"; return 0;
}