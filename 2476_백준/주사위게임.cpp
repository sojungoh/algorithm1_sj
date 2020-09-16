#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> v;
multimap<int, int> k;
multimap<int, int>::iterator iter;
pair<multimap<int, int>::iterator, multimap<int, int>::iterator> pair_iter;

int sortVal(int key) {
	iter = k.find(key);
	pair_iter = k.equal_range(key);
	int max = pair_iter.first->second;
	for (iter = pair_iter.first; iter != pair_iter.second; ++iter) {
		if (iter->second > max) {
			max = iter->second;
		}
	}
	return max;
}

int main(void) {
	int N, a, b, c, max;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(), v.end());

		if (a == b && b == c) {
			k.insert(pair<int, int>(1, v[0]));
		}
		else if (a != b && a != c && b != c) {
			k.insert(pair<int, int>(3, v[2]));
		}
		else k.insert(pair<int, int>(2, v[1]));
		v.clear();
	}
	if (k.find(1) == k.end()) {
		if (k.find(2) == k.end()) {
			if (k.find(3) == k.end()) {
				cout << "ERROR";
			}
			else {
				max = sortVal(3);
				cout << max * 100;
			}
		}
		else {
			max = sortVal(2);
			cout << 1000 + max * 100;
		}
	}
	else {
		max = sortVal(1);
		cout << 10000 + max * 1000 << endl;
	}
	return 0;
}

