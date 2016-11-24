#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	string st;
	cin >> st;
	int b =0, s=0, c=0;
	for (int i=0;i<st.length();i++)
	{
		if (st[i]=='B') b++;
		if (st[i]=='S') s++;
		if (st[i]=='C') c++;
	}

	int ib, is, ic;
	scanf("%d %d %d", &ib, &is, &ic);
	int pb, ps, pc;
	scanf("%d %d %d", &pb, &ps, &pc);
	long long r;
	cin >> r;

	long long curr = 0;
	long long b1=1<<20, s1=1<<20, c1=1<<20;
	if (b > 0)
		b1 = ib/b;
	if (s > 0)
		s1 = is/s;
	if (c > 0)
		c1 = ic/c;

	curr = min(b1, min(s1, c1));
	long long lo = curr;
	long long hi = r+curr;
	/* find max number that is within r price */
	while (lo < hi) {
		long long mid = lo + (hi - lo+1)/2;
		long long price = max(0LL, mid*b - (long long)ib)*pb + max(0LL, mid*s - (long long)is)*ps + max(0LL, mid*c - (long long)ic)*pc;
		if (price <= r)
			lo = mid;
		else
			hi = mid-1;
 	}

 	cout << lo << "\n";

}