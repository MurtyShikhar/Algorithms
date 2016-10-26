#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <iostream>

#define MAX 100004
using namespace std;

int main() {
	vector<int> primes(MAX, 1);
	for (int i=4; i < MAX; i+=2) {
		primes[i]=0;
	}

	vector<int> primes_aux;
	primes_aux.reserve(MAX);

	primes_aux.push_back(2);
	for (int i=3; i < MAX; i+=2) {
		if (primes[i]) {
			primes_aux.push_back(i);
			long long j = (long long)i*i; // watch out for overflow here!
			for (; j < MAX; j+=i){
				primes[j]=0;
			}
		}

	}

	int n,m; scanf("%d %d", &n, &m);
	vector<vector<int> > mat(n, vector<int>(m,0));
	for (int i=0; i < n; i++) {
		for (int j=0; j < m; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	int minMoves=1<<30;
	for (int i=0; i < n; i++) {
		int check=0;
		for (int j=0; j < m; j++) {
			auto it = lower_bound(primes_aux.begin(), primes_aux.end(), mat[i][j]);
			check += (*it) - mat[i][j];
		}

		minMoves = min(minMoves, check);
	}

	for (int j=0; j < m; j++) {
		int check=0;
		for (int i=0; i < n; i++) {
			auto it = lower_bound(primes_aux.begin(), primes_aux.end(), mat[i][j]);
			check += (*it) - mat[i][j];
		}
		minMoves = min(minMoves, check);
	}

	printf("%d\n", minMoves);

}