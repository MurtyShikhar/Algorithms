#include <set>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(double mid, int population, vector<pair<double,int> >& dist, vector<int>& aux) {
	int idx = upper_bound(dist.begin(), dist.end(), make_pair(mid, -1)) - dist.begin();
	if (idx == 0)
		return population >= 1e6;
	else
		return population + aux[idx-1] >= 1e6;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);

	vector<pair<double, int> > dist(n);

	for (int i=0; i < n; i++) {
		int a,b,c; scanf("%d %d %d", &a, &b,&c);
		double currDist = sqrt( (long long)a*a + (long long)b*b);
		dist[i] = make_pair(currDist,c);
	}

	double eps = 1.0e-8;
	sort(dist.begin(), dist.end());

	vector<int> aux(n,0);
	aux[0] = dist[0].second;
	for (int i=1; i < n;i++)
		aux[i] = aux[i-1]+dist[i].second;

	double r =  dist[n-1].first, l=0;
	if (m + aux[n-1] < 1e6)
		cout << -1 << "\n";
	else{
		while (r-l > eps) {
			double mid = l + (r-l)/2.0;
			bool possible = check(mid, m, dist, aux);
			if (possible)
				r = mid;
			else
				l = mid;
		}

		printf("%5.7f\n", r);
	}
}