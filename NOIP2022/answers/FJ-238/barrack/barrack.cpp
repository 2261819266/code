#include <bits/stdc++.h>
int n, m;
int AWA(int x) {
	int res = 1;
	for (int i = 2; i <= x; ++i) res *= i;
	return x;
}
int QWQ(int x, int y) {
	return AWA(x) / AWA(x - y);
}
int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	std::cin >> n >> m;
	if (m < n) std::swap(n, m);
	std::cout << QWQ(n, m);
	return 0;
}
