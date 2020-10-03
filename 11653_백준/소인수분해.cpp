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
			n = n / k;
			cout << k << endl;
		}
	}
	return 0;
}