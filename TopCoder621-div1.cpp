#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<double,double> pdd;

/* [D-r, D+r] */
class RadioRange{
public:
	/* i1.first < i2.first */
	bool intersects(pdd& i1, pdd& i2) {
		return i2.first < i1.second;
	}

	double RadiusProbability(vector<int>& X, vector<int>& Y, vector<int>& R, int Z){
		int n = X.size();
		vector<pair<double, double> > intervals(n);
		for (int i=0; i < n; i++) {
			double distances_i = sqrt( X[i]*(double)X[i] + Y[i]*(double)Y[i] );
			intervals[i] = make_pair(max(distances_i - R[i],0.0), min(distances_i + R[i], (double)Z));
		}

		sort(intervals.begin(), intervals.end());

		pdd curr = intervals[0];
		double ans=0; /* all the unsafe zone */
		for (int i=1; i<n; i++) {
			if (intersects(curr, intervals[i])) {
				curr.second = max(intervals[i].second, curr.second);
			}
			else {
				ans += curr.second - curr.first;
				curr = intervals[i];
			}
		}

		ans += (curr.second - curr.first);
		return (1.0 - ans/Z);
	}
};


int main() {
	int n; scanf("%d", &n);
	vector<int> x(n),y(n),r(n);
	for (int i=0; i < n;i++) {
		scanf("%d %d %d", &x[i], &y[i], &r[i]);
	}

	int z; scanf("%d", &z);

	RadioRange rad;
	printf("%5.6f\n", rad.RadiusProbability(x,y,r, z));
}