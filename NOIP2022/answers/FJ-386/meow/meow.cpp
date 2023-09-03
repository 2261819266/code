#include <bits/stdc++.h>

using namespace std;

int t, n, m, k;

int s[2000001];

int deq[4][2000001], head[4], tail[4];

void init() {
	for (int i = 1; i <= 3; i++)
		head[i] = 1, tail[i] = 0;
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	cin.tie();
	cout.tie();
	cin >> t;
	while (t--) {
		init();
		cin >> n >> m >> k;
		for (int i = 1; i <= m; i++)
			cin >> s[i];
		if (n == 2) {
			deq[1][++tail[1]] = s[1];
			cout << "1 1" << endl;
			for (int i = 2; i <= m; i++) {
				if (s[i] == deq[1][tail[1]])
					cout << "1 1" << endl, tail[1]--;
				else if (s[i] == deq[2][tail[2]])
					cout << "1 2" << endl, tail[2]--;
				else if (s[i] == deq[1][head[1]] && tail[2] - head[2] < 0)
					cout << "1 2" << endl << "2 1 2" << endl, head[1]++;
				else if (s[i] == deq[2][head[2]] && tail[1] - head[1] < 0)
					cout << "1 1" << endl << "2 1 2" << endl, head[2]++;
				else if (tail[1] - head[1] < 0)
					cout << "1 2" << endl, deq[2][++tail[2]] = s[i];
				else if (tail[2] - head[2] < 0)
					cout << "1 1" << endl, deq[1][++tail[1]] = s[i];
			}
		} else if (n == 3) {
			deq[1][++tail[1]] = s[1];
			cout << "1 1" << endl;
			for (int i = 2; i <= m; i++) {
				if (s[i] == deq[1][tail[1]])
					cout << "1 1" << endl, tail[1]--;
				else if (s[i] == deq[2][tail[2]])
					cout << "1 2" << endl, tail[2]--;
				else if (s[i] == deq[3][tail[3]])
					cout << "1 3" << endl, tail[3]--;
				else if (s[i] == deq[1][head[1]] && tail[2] - head[2] < 0)
					cout << "1 2" << endl << "2 1 2" << endl, head[1]++;
				else if (s[i] == deq[1][head[1]] && tail[3] - head[3] < 0)
					cout << "1 3" << endl << "2 1 3" << endl, head[1]++;
				else if (s[i] == deq[2][head[2]] && tail[1] - head[1] < 0)
					cout << "1 1" << endl << "2 1 2" << endl, head[2]++;
				else if (s[i] == deq[2][head[2]] && tail[3] - head[3] < 0)
					cout << "1 3" << endl << "2 1 3" << endl, head[2]++;
				else if (s[i] == deq[3][head[3]] && tail[1] - head[1] < 0)
					cout << "1 1" << endl << "2 1 3" << endl, head[3]++;
				else if (s[i] == deq[3][head[3]] && tail[2] - head[2] < 0)
					cout << "1 2" << endl << "2 2 3" << endl, head[3]++;
				else if (tail[1] - head[1] < 0)
					cout << "1 2" << endl, deq[2][++tail[2]] = s[i];
				else if (tail[2] - head[2] < 0)
					cout << "1 1" << endl, deq[1][++tail[1]] = s[i];
			}
		}
	}
	return 0;
}

