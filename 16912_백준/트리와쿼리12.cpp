#include <iostream>
using namespace std;

int N, M, root;
int *arr;

void setN(int N) {
	arr = (int *)malloc(sizeof(int) * (N + 1));
	for (int i = 0; i < N + 1; i++) {
		arr[i] = i;
	}
}

void unionFind(int a, int b) {
	if (arr[b] != b) {
		do {
			root = arr[b];
			arr[b] = a;
			a = b;
			b = root;
		} while (arr[root] != root);
		arr[root] = a;
	}
	else arr[b] = a;
}

void del(int a, int b) {
	if (a == arr[b]) {
		arr[b] = b;
	}
	else {
		arr[a] = a;
	}
}

bool connection(int a, int b) {
	while (arr[a] != a) {
		a = arr[a];
	}
	while (arr[b] != b) {
		b = arr[b];
	}
	if (arr[a] == arr[b]) return true;
	else return false;
}

int main(void) {
	cin >> N >> M;
	int q, a, b, l;

	setN(N);

	for (int i = 0; i < M; i++) {
		cin >> q >> a >> b;

		if (q == 1) {
			unionFind(a, b);
		}
		else if (q == 2) {
			del(a, b);
		}
		else if (q == 3) {
			l = connection(a, b);
			cout << l << endl;
		}
	}
	free(arr);
	return 0;
}