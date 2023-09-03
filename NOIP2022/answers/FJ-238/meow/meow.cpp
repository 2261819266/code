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
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	std::cin >> n >> m;
	if (m < n) std::swap(n, m);
	std::cout << QWQ(n, m);
	std::cerr << "Never gonna give you up, never gonna let you down, never gonna run around and desert you.";
	return 0;
}
