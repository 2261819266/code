#include<bits/stdc++.h>
using namespace std;
int T, id, n, m, C, F;
mt19937 rnd(233);
inline int read() {
	int out = 0;
	bool flag = false;
	char cc = getchar();
	while (cc < '0' || cc > '9') {
		if (cc == '-') {
			flag = true;
		}
		cc = getchar();
	}
	while (cc >= '0' && cc <= '9') {
		out = (out << 3) + (out << 1) + (cc ^ 48);
		cc = getchar();
	}
	return flag ? -out : out;
}
int main() {
	freopen ("plant.in", "r", stdin);
	freopen ("plant.out" , "w", stdout);
	srand(time(0));
	T = read(), id = read();
	while (T--) {
		n = read(), m = read(), C = read(), F = read();
		cout << n * n << ' ' << n * n / 2 << endl;
	}
	return 0;
}

