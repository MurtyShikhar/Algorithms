#include <stack>
#include <cstdio>
#include <iostream>

using namespace std;

/* O(n**2) time, and O(n) space to sort a stack*/

void transferStack(stack<int>& s, stack<int>& aux) {
	while (!aux.empty()) {
		int t = aux.top(); aux.pop();
		s.push(t);
	}
}

void exchangeTop(stack<int>& s, stack<int>& aux) {
	int sTop = s.top(); s.pop();
	int auxTop=aux.top(); aux.pop();
	s.push(auxTop);
	aux.push(sTop);
}

void sortStack(stack<int>& s) {
	stack<int> aux;
	while (true){
		bool flagSorted=true;
		while(!s.empty()) {
			int t = s.top(); s.pop();
			aux.push(t);
			if (s.empty())
				//transferStack(s, aux);
				break;
			else if (aux.top() > s.top()){
				flagSorted=false;
				exchangeTop(s, aux);
			}
		}
		transferStack(s, aux);
		if (flagSorted) break;
	}
}

void printStack(stack<int> s) {
	cout <<"printing stack.\n";
	while (!s.empty()) {
		int t = s.top(); s.pop();
		cout << t << " ";
	}
	cout << "\n";
}
 

int main() {
	int n;
	scanf("%d", &n);
	stack<int> s;
	for (int i=0; i < n; i++) {
		int j;
		scanf("%d", &j);
		s.push(j);
	}
	cout << "sorting stack\n";
	sortStack(s);
	printStack(s);
}