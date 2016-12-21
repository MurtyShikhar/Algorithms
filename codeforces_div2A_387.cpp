#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n; scanf("%d", &n);

	int sqrtn = sqrt(n);
	int a = sqrtn;
	while (a >= 1) {
		if (n % a == 0) break; 
		a--;
	}

	int b = n/a;
	printf("%d %d\n", a, b);

}