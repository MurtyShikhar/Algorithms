#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class BinaryCards{
public:
	long largestNumber(long A, long B){
		for (int i = 60; i >= 0; i--) {
			if (A^B & (1LL << i))
				return (A | (1LL << (i+1) -1));
		}

		return A;
	}
};