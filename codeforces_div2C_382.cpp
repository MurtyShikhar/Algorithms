#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

/* AVL tree worst case height analysis (sort of)
   recursion: N(h) = min number of nodes with height h in the worst case = N(h-1) + N(h-2)
   base case N(1) = 2, N(2) = 3
	
*/
int main() {
	ll n; cin >> n;

	if (n == 1) {printf("%d\n", 0); return 0;}
	if (n == 2) {printf("%d\n", 1); return 0;}

	int curr_height = 2;
	ll prev = 2;
	ll curr = 3;

	while (curr < n) {
		ll old_curr = curr;
		curr = prev + curr;
		prev = old_curr;
		curr_height += 1;
	} 

	if (curr > n) curr_height--;
	printf("%d\n", curr_height);
}