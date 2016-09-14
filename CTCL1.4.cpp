#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

bool palindrome(string& s) {
	vector<int> words(256, 0);
	int sz = s.size();
	for (int i=0;i<sz; i++) {
		if (s[i] != ' '){
			if (isupper(s[i]))
				words[s[i]-'A']+=1;
			else
				words[s[i]-'a']+=1;
		}
	}

	int odds=0;
	for (int i=0;i<256;i++){
		if (words[i]%2)
			odds+=1;
	}

	return odds<=1;
}

int main() {
	string s;
	getline(cin, s);
	cout << palindrome(s) << "\n";
}