#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

/* decompose n into a sum of non primes, and minimize the number 
   n = 10^12!! so can't use a dp solution <----------- learning!!
   if N is a prime number, N-1 is a multiple of 2 or a non prime (except for 3) and is a composite number
 */
class MagicDiamonds{
public:
	bool prime(long n) {
		long lim = (long)sqrt(n);
		for (int i=2; i <= lim; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}
	long minimalTransfer(long n){
		if (!prime(n)) return 1;
		else if (n==3) return 1;
		else return 2;
	}
};