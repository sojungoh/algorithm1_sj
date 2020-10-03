#include <iostream>
using namespace std;

int main(void) {
	int n;
	int k = 2;

	cin >> n;

	while (n != 1) {
		if (n % k != 0) {
			k++;
		}
		else {
			cout << k << endl;
			n = n / k;
		}
	}
	return 0;
}