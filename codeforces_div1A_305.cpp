#include <set>
#include <vector>
#include <cmath>
#include <stack>
#include <iostream>
#include <algorithm>
#include <cstdio>


using namespace std;


// for each ai, store li and ri 
/*
	LEARNING!
	li holds the idx of leftmost element such that ali < ai  (using stack O(n))
	ri holds the idx of rightmost element such that ari < ai (using stack O(n))
	clearly in range [li+1, ri-1] ai is the smallest.
	therefore ai can be the answer for all x from 1 to ri-li-1
*/



int main() {

	int n; scanf("%d", &n);
	vector<int> heights(n,0);

	for (int i=0; i < n; i++) 
		scanf("%d", &heights[i]);

	vector<int> l(n,-1);
	vector<int> r(n,n);

	stack<int> aux;
	aux.push(0);
	int i=1;
	//cout << "here\n";
	while (i < n) {
		while (!aux.empty() && heights[aux.top()] >= heights[i])
			aux.pop();
		if (!aux.empty())
			l[i]=aux.top();

		aux.push(i);
		i++;
	}

	while (!aux.empty())
		aux.pop();

	aux.push(n-1);
	i=n-2;
	while (i >= 0) {
		while (!aux.empty() && heights[aux.top()] >= heights[i])
			aux.pop();
		if (!aux.empty())
			r[i]=aux.top();

		aux.push(i);
		i--;
	}

	vector<int> ans(n+1,-1);
	for (int i=0; i < n; i++) {
		//cout << heights[i] << " " << l[i] << r[i] << "\n";
		int len = r[i]-l[i]-1;
		ans[len] = max(heights[i], ans[len]);
	}

	for (int i=n-1; i>=1; i--) {
		ans[i] = max(ans[i+1], ans[i]);
	}

	for (int i =1; i < n; i++) {
		printf("%d ", ans[i]);
	}

	printf("%d\n", ans[n]);
}