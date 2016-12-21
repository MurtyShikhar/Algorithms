#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// struct job{
// 	int st; 
// 	int servers;
// 	int dur;
// 	job(int a, int b, int c): st(a), servers(b), dur(c){}
// };

int main(){
	int n, q; scanf("%d %d", &n, &q);
	//vector<job> jobs;
	vector<int> servers(n,0);

	for (int i=0; i < q; i++) {
		int st, servs, dur; scanf("%d %d %d", &st, &servs, &dur);
		int j=0; int s = 0;
		while (j < n && s != servs) {
			if (servers[j] < st) {s+=1;}
			j+=1;
		}

		if (s != servs) printf("-1\n");
		else{
			int sum = 0; int j=0; int s = 0;
			while (j < n && s != servs) { if (servers[j] < st) {sum += (j+1); servers[j] = st + dur -1; s += 1;} j += 1;}
			printf("%d\n", sum);
		}
	}

}