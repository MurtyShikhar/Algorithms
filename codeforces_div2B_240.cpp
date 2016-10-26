#include <set>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
/* learn to see thru the example test cases!!
	in none of the example test cases a>1, so x*a == x, and therefore,
	I missed out dividing by a. 
 */

int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	vector<int> x(n,0);
	for (int i=0; i < n; i++)
		scanf("%d", &x[i]);

	// for day i -> x_i*a % b
	for (int i=0; i < n; i++) {
		cout << ((x[i]*(long long)a) % (long long)b )/ (long long) a<< " ";
	}

	cout << "\n";
}