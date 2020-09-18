#include <iostream>
#include <string>
using namespace std;

void printZero(int z) {
	for (int i = 0; i < z; i++) {
		cout << '0';
	}
}

int countZero(string x) {
	int count = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '0') {
			count++;
		}
	}
	return count;
}

int main(void) {
	char oper;
	string a, b;
	int m, n;
	cin >> a >> oper >> b;

	m = countZero(a);
	n = countZero(b);

	if (oper == '*') {
		cout << '1';
		printZero(m + n);
	}
	else {
		if (m == n) {
			cout << '2';
			printZero(m);
		}
		else if (m > n) {
			cout << '1';
			printZero(m - n - 1);
			cout << '1';
			printZero(n);
		}
		else {
			cout << '1';
			printZero(n - m - 1);
			cout << '1';
			printZero(m);
		}
	}
	return 0;
}