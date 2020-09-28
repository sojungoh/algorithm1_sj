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

// c++ 입출력함수 종류랑 뭐가 다른지 정확히 알기 - getline 함수는 개행부터 입력 받는 것 등
// cin.ignore 함수랑 cin.clear 함수 찾아보기
// 문자열 띄어쓰기 입력 받으려면 뭐가 좋은지, string 이랑 char 배열이랑 언제 쓰이는 게 좋은지 공부하기
