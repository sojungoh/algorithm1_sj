#include <iostream>

using namespace std;

typedef struct Ball {
	int x, y;
	char top, bottom, left, right;

	void rightDown() {
		if (right != '#') {
			y += 1;
		}
		else if (bottom != '#') {
			x += 1;
		}
		else {

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


	if (o.y - r.y >= 0 && o.x - r.x >= 0) {
		while (r.x != o.x || r.y != o.y) {
			r.top = arr[r.x - 1][r.y];
			r.bottom = arr[r.x + 1][r.y];
			r.left = arr[r.x][r.y - 1];
			r.right = arr[r.x][r.y + 1];

			r.rightDown(); //이 함수는 방향 바꿀 때 불러오면 좋겠다
		}
	}
	else if (o.y - r.y < 0 && o.x - r.x >= 0) {
		leftDown();
	}
	else if (o.y - r.y >= 0 && o.x - r.x < 0) {
		rightUp();
	}
	else {
		leftUp();
	}
}