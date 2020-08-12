#include <iostream>

using namespace std;

struct Ball {
	int x, y;
	char ch;

	char findRoadFirst(char top, char bottom, char left, char right) {
		if (top == '.') {
			return 't';
		}
		else {
			if (bottom == '.') {
				return 'b';
			}
			else {
				if (left == '.') {
					return 'l';
				}
				else {
					if (right == '.') {
						return 'r';
					}
					else cout << "-1";
				}
			}
		}
	}

	char findRoad(char c) {
		if (c == 't') {

		}
		else if (c == 'b') {

		}
		else if (c == 'l') {

		}
		else {

		}
	}
};

int main(void) {
	int n, m;
	Ball r, b, o;

	cin >> n >> m;

	char **arr = new char*[n];
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
	char ch = r.findRoadFirst(arr[r.x - 1][r.y], arr[r.x + 1][r.y], arr[r.x][r.y - 1], arr[r.x][r.y + 1]);
	
	if (ch == 't') {
		int rx = r.x;
		while (arr[rx - 1][r.y] != '#') {
			rx-=rx;
		}
		r.x = rx;
		r.findRoad('t');
	}



	for (int i = 0; i < n; i++)
		delete[] arr;
	delete[] arr;

	return 0;
}