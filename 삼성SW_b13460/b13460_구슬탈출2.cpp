/*
#include <iostream>
#include <string.h>

using namespace std;

struct Ball {
	int x, y;
	char ch;
	bool sc;

	int findRoadFirst(char top, char bottom, char left, char right) {
		if (top == 'O' || bottom == 'O' || left == 'O' || right == 'O') {
			return 5;
		}
		else {
			if (top == '.') {
				return 1;
			}
			else if (bottom == '.') {
				return 2;
			}
			else if (left == '.') {
				return 3;
			}
			else if (right == '.') {
				return 4;
			}
			else return -1;
		}
	}

	int findRoadTB(char left, char right) {
		if (left == 'O' || right == 'O') {
			return 5;
		}
		else {
			if (left == '.') {
				return 3;
			}
			else if (right == '.') {
				return 4;
			}
			else return -1;
		}
	}

	int findRoadLR(char top, char bottom) {
		if (top == 'O' || bottom == 'O') {
			return 5;
		}
		else {
			if (top == '.') {
				return 1;
			}
			else if (bottom == '.') {
				return 2;
			}
			else return -1;
		}
	}
};

int main(void) {
	int n, m, rx, ry, ans = 1;
	Ball r;
	Ball b;
	Ball o;

	cin >> n >> m;

	char **arr;
	arr = new char*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 'R') {
				r.x = i;
				r.y = j;
			}
			else if (arr[i][j] == 'B') {
				b.x = i;
				b.y = j;
			}
			else if (arr[i][j] == 'O') {
				o.x = i;
				o.y = j;
			}
		}
	}

	int num = r.findRoadFirst(arr[r.x - 1][r.y], arr[r.x + 1][r.y], arr[r.x][r.y - 1], arr[r.x][r.y + 1]);

	do {
		if (num == 1) {
			rx = r.x; ry = r.y;
			if (arr[r.x - 1][r.y] == '#') {
				ans += 1;
				num = r.findRoadTB(arr[r.x][r.y - 1], arr[r.x][r.y + 1]);
			}
			else {
				r.x -= 1;
			}
		}

		else if (num == 2) {
			rx = r.x; ry = r.y;
			if (arr[r.x + 1][r.y] == '#') {
				ans += 1;
				num = r.findRoadTB(arr[r.x][r.y - 1], arr[r.x][r.y + 1]);
			}
			else {
				r.x += 1;
			}
		}

		else if (num == 3) {
			rx = r.x; ry = r.y;
			if (arr[r.x][r.y - 1] == '#') {
				ans += 1;
				num = r.findRoadLR(arr[r.x - 1][r.y], arr[r.x + 1][r.y]);
			}
			else {
				r.y -= 1;
			}
		}

		else if (num == 4) {
		rx = r.x; ry = r.y;
			if (arr[r.x][r.y + 1] == '#') {
				ans += 1;
				num = r.findRoadLR(arr[r.x - 1][r.y], arr[r.x + 1][r.y]);
			}
			else {
				r.y += 1;
			}
		}
		else if (num == 5) {
			break;
		}
		else {
			ans = -1;
			break;
		}
	} while (r.x != o.x || r.y != o.y);

	if (ans <= 10) {
		cout << ans;
	}
	else cout << "-1";

	for (int i = 0; i < n; i++)
		delete [] arr[i];
	delete [] arr;

	return 0;
}*/