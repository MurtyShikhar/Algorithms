#include <set>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdio>


using namespace std;

/*
	learnt how to efficiently find out the interval in which a point lies.
	firstly, store all the right ends of the intervals in a set.
	then find the first right end that is greater than or equal to the point
	using lower_bound. 
 */

int main() {
	int n,k,a;
	scanf("%d %d %d", &n, &k, &a);

	int m; scanf("%d", &m);
	set<pair<int,int> > intervals;
	int possible= (n+1)/(a+1);

	// intervals are always non intersecting
	intervals.insert(make_pair(n, 1));
	for (int i=0; i < m; i++) {
		int curr; scanf("%d", &curr);
		int leftContrib=0, rightContrib=0;
		// gives the first interval such that curr <= itr1->first
		auto itr1 = intervals.lower_bound(make_pair(curr, -1));
		int left = itr1->second, right = itr1->first;

		int prev = (right-left+2)/(a+1);

		if (left < curr){ 
			// left... curr-1
			leftContrib = (curr-left + 1)/(a+1);
			intervals.insert(make_pair(curr-1, left));
		}

		if (right > curr) {
			// curr+1...right
			rightContrib = (right-curr+1)/(a+1);
			intervals.insert(make_pair(right, curr+1));
		}

		possible += (leftContrib + rightContrib - prev);
		intervals.erase(itr1);
		if (possible < k){
			printf("%d\n", i+1);
			return 0;
		}
	}

	printf("-1\n");
}