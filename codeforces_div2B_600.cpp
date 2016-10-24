#include <vector>
#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(vector<int>& a, vector<int>& b) {
	sort(a.begin(), a.end());
	int m = b.size();
	vector<int> possible(m,0);
	for (int i=0; i < m; i++) {
		int ss = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
		possible[i] =  ss;
	}

	for (int i=0; i < m-1; i++)
		cout << possible[i] << " ";

	cout << possible[m-1] << "\n";
}

int main()
{
	int n, m; 
	scanf("%d", &n);
	scanf("%d", &m);
	vector<int> a(n);
	vector<int> b(m);
	for (int i=0; i <n; i++) 
		scanf("%d", &a[i]);

	for (int i=0; i < m; i++)
		scanf("%d", &b[i]);

	solve(a,b);
	return 0;
}