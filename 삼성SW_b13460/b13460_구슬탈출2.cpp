#include <iostream>
#include <string.h>

using namespace std;

struct Ball {
	int x, y;
	char ch;

	int findRoadFirst(char top, char bottom, char left, char right) {
		if (top == 'O') {
			return 1;
		}
		else if (bottom == 'O') {
			return 2;
		}
		else if (left == 'O') {
			return 3;
		}
		else if (right == 'O') {
			return 4;
		}
		else if (top == '.') {
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

	int findRoadTB(char left, char right) {
		if (left == '.') {
			return 3;
		}
		else if (right == '.') {
			return 4;
		}
		else return -1;
	}

	int findRoadLR(char top, char bottom) {
		if (top == '.') {
			return 1;
		}
		else if (bottom == '.') {
			return 2;
		}
		else return -1;
	}
};

int main(void) {
	int n, m, rx, ry, t = 0, ans = 1;
	int trace[10];
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
				rx = r.x;
				ry = r.y;
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
			if (arr[r.x - 1][r.y] == '#') {
				ans += 1;
				trace[t] = num; t++;
				num = r.findRoadTB(arr[r.x][r.y - 1], arr[r.x][r.y + 1]);
			}
			else if (arr[r.x - 1][r.y] == 'O') {
				trace[t] = num;
				r.x -= 1;
			}
			else {
				r.x -= 1;
			}
		}
		else if (num == 2) {
			if (arr[r.x + 1][r.y] == '#') {
				ans += 1;
				trace[t] = num; t++;
				num = r.findRoadTB(arr[r.x][r.y - 1], arr[r.x][r.y + 1]);
			}
			else if (arr[r.x + 1][r.y] == 'O') {
				trace[t] = num;
				r.x += 1;
			}
			else {
				r.x += 1;
			}
		}
		else if (num == 3) {
			if (arr[r.x][r.y - 1] == '#') {
				ans += 1;
				trace[t] = num; t++;
				num = r.findRoadLR(arr[r.x - 1][r.y], arr[r.x + 1][r.y]);
			}
			else if (arr[r.x][r.y - 1] == 'O') {
				trace[t] = num;
				r.y -= 1;
			}
			else {
				r.y -= 1;
			}
		}
		else if (num == 4) {
			if (arr[r.x][r.y + 1] == '#') {
				ans += 1;
				trace[t] = num; t++;
				num = r.findRoadLR(arr[r.x - 1][r.y], arr[r.x + 1][r.y]);
			}
			else if (arr[r.x][r.y + 1] == 'O') {
				trace[t] = num;
				r.y += 1;
			}
			else {
				r.y += 1;
			}
		}
		else if (num == 5) {
			trace[t] = num; t++;
			ans = 1;
			break;
		}
		else {
			ans = -1;
			break;
		}
	} while (r.x != o.x || r.y != o.y);

	if (ans > 0) {
		for (int i = 0; i < ans; i++) {
			if (trace[i] == 1) {
				while (arr[b.x - 1][b.y] != '#'&&arr[rx - 1][ry] != '#') {
					if (rx + 1 == b.x&&ry == b.y) {
						if (arr[b.x - 1][b.y] == 'O') {
							ans = -1;
							break;
						}
					}
					b.x -= 1;
					rx -= 1;
				}
			}
			else if (trace[i] == 2) {
				while (arr[b.x + 1][b.y] != '#'&&arr[rx + 1][ry] != '#') {
					if (rx - 1 == b.x&&ry == b.y) {
						if (arr[b.x + 1][b.y] == 'O') {
							ans = -1;
							break;
						}
					}
					b.x += 1;
					rx += 1;
				}
			}
			else if (trace[i] == 3) {
				while (arr[b.x][b.y - 1] != '#'&&arr[rx][ry - 1] != '#') {
					if (rx == b.x&&ry + 1 == b.y) {
						if (arr[b.x][b.y - 1] == 'O') {
							ans = -1;
							break;
						}
					}
					b.y -= 1;
					ry -= 1;
				}
			}
			else if (trace[i] == 4) {
				while (arr[b.x][b.y + 1] != '#'&&arr[rx][ry + 1] != '#') {
					if (rx == b.x&&ry - 1 == b.y) {
						if (arr[b.x][b.y + 1] == 'O') {
							ans = -1;
							break;
						}
					}
					b.y += 1;
					ry += 1;
				}
			}
		}
	}

	if (ans <= 10) {
		cout << ans;
	}
	else cout << "-1";

	for (int i = 0; i < n; i++)
		delete [] arr[i];
	delete [] arr;

	return 0;
}