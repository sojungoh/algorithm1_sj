#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char> v;
vector<char> v_test;

int main(void) {
	int n, k;
	string str;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> k;
		if (k == 0) {
			k = 32;
			v.push_back(k);
		}
		else if (1 <= k && k <= 26) {
			k += 64;
			v.push_back(k);
		}
		else if (27 <= k && k <= 52) {
			k += 70;
			v.push_back(k);
		}
	}
	cin.ignore(256, '\n');
	getline(cin, str);

	sort(v.begin(), v.end());
	sort(str.begin(), str.end());

	for (int i = 0; i < str.size(); ++i) {
		v_test.push_back(str.at(i));
	}
	v == v_test ? (cout << 'y') : (cout << 'n');

	return 0;
}

// c++ ������Լ� ������ ���� �ٸ��� ��Ȯ�� �˱� - getline �Լ��� ������� �Է� �޴� �� ��
// cin.ignore �Լ��� cin.clear �Լ� ã�ƺ���
// ���ڿ� ���� �Է� �������� ���� ������, string �̶� char �迭�̶� ���� ���̴� �� ������ �����ϱ�
