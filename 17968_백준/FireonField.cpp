#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec_wrong;

void calculate(int(&a_ref)[1001], int i, int k) {
	int wrong = 2 * a_ref[i - k] - a_ref[i - 2 * k];
	vec_wrong.push_back(wrong);
}

int findValue(vector<int>& vec_wrong) {
	int test = 1;
	sort(vec_wrong.begin(), vec_wrong.end());

	for (int i = 0; i < vec_wrong.size(); ++i) {
		if (test == vec_wrong[i]) {
			test++;
		}
	}
	return test;
}

int main() {
	int n;
	int a[1001];
	a[0] = 1;
	a[1] = 1;

	cin >> n;

	for (int i = 2; i <= n; ++i) {
		for (int k = 1; k <= (i / 2); ++k) {
			calculate(a, i, k);
		}
		a[i] = findValue(vec_wrong);
		vec_wrong.clear();
	}
	cout << a[n] << endl;

	return 0;
}