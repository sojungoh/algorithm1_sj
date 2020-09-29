#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int findPrime(int n, int k) {
	while ((n % k) != 0) {
		k++;
	}
	do {
		n = n % k;
		cout << k;
		if (n == 1) break;
	} while ((n % k) == 0);

	return n;
}

int main(void) {
	int n, k = 2;
	
	cin >> n;

	if (n == 1) {
		cout << "1 is not prime factor";
	}
	else {
		while (n != 1) {
			n = findPrime(n, k);
		}
	}

	return 0;
}