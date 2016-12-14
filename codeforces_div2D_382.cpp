#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int n) {
	int sqrtn = sqrt(n);
	if (n == 2) return 1;
	for (int i=2; i <= sqrtn; i++) 
		if (n % i == 0) return 0;
	return 1;
}

int main() {
	int n; scanf("%d", &n);
	int ans;
	if (is_prime(n)) ans = 1;

	else if (n%2 == 0) ans = 2;
	else if (is_prime(n-2)) ans = 2;
	else ans = 3;

	/*ans =2 for even; (using goldbach's conjecture -> every even number can be expressed as sum of 2 primes)
	  for any odd number k = 3 + (k-3) 
	 */
	
	cout << ans << "\n";
	return 0;

}