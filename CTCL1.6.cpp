#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string compress(string& a) {
	stringstream ss;
	ss << a[0];
	int sz = a.size();
	int acc=1;
	for (int i=1; i < sz; i++) {
		if (a[i] != a[i-1]){
			ss << acc;
			ss << a[i];
			acc=1;
		}
		else
			acc++;
	}

	ss << acc;
	string ret = ss.str();
	if (ret.size() >= sz)
		return a;
	else 
		return ret;
}


int main() {
	string s; getline(cin, s);
	string compressed = compress(s);
	cout << compressed << "\n";
}