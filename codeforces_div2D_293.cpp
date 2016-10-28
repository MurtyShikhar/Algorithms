#include <vector>
#include <iostream>
#include <cstdio>
#include <set>

#define MAX 2001

using namespace std;
/* 
	2 ways of solving expected value problems: 
	1)Indicator random variables
	2)Calculating explicit probabilities
*/
/* dp[i][j] = probability that j people in escalator after i seconds */
double dp[MAX][MAX];

void initDP() {
	for (int i=0; i < MAX; i++)
		for (int j=0; j < MAX; j++)
			dp[i][j] = 0;
}


int main() {
	int n,t;
	double p;
	scanf("%d %lf %d", &n, &p, &t);

	// dp[i][j] = p*dp[i-1][j-1] + (1-p)*dp[i-1][j];

	dp[0][0]=1.0;
	for (int currTime=1; currTime <= t; currTime++) {
		for (int currPeople=0; currPeople <= n; currPeople++) {
			if (currPeople==n)
				dp[currTime][currPeople] = dp[currTime-1][currPeople];
			else
				dp[currTime][currPeople] = (1.0-p)*dp[currTime-1][currPeople];
			if (currPeople > 0)
				dp[currTime][currPeople] += p*dp[currTime-1][currPeople-1];
		}
	}

	double ans = 0;
	for (int currPeople=1; currPeople <= n; currPeople++)
		ans += currPeople*dp[t][currPeople];

	printf("%5.7f\n", ans);
}

