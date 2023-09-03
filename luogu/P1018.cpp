#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

const int maxn = 50;

using Vector = std::vector<int>;

struct BigInteger {
	Vector a;

	BigInteger() { a.clear(); }

	BigInteger(int x) {
		*this = x;
	}

	BigInteger operator=(int x) {
		a.clear();
		if (!x) a.push_back(0);
		else while (x) {
			a.push_back(x % 10);
			x /= 10;
		}
		return *this;
	}

	using cb = const BigInteger &;

	BigInteger operator+(cb x) const {
		BigInteger ans;
		int n = std::max(a.size(), x.a.size());
		for (int i = 0, t = 0; i < n || t; i++) {
			int y = t;
			if (i < a.size()) y += a[i];
			if (i < x.a.size()) y += x.a[i];
			t = y / 10;
			ans.a.push_back(y % 10);
		}
		return ans;
	}

	BigInteger operator+=(cb x) { return *this = *this + x; }

	BigInteger operator*(int x) const {
		BigInteger ans;
		int n = a.size();
		if (!x) ans = 0;
		else for (int i = 0, t = 0; i < n || t; i++) {
			int y = x;
			if (i < n) y *= a[i];
			else y = 0;
			y += t;
			t = y / 10;
			ans.a.push_back(y % 10);
		}
		return ans;
	} 
	BigInteger operator*=(int x) { return *this = *this * x; }

	BigInteger operator*(cb x) const {
		if (!(a.size() && x.a.size())) return 0;
		BigInteger ans;
		for (auto i = a.end() - 1; i >= a.begin(); i--) {
			ans *= 10;
			ans += x * *i;
		}
		return ans;
	}

	BigInteger operator*=(cb x) { return *this = *this * x; }

	void write() {
		if (!a.size()) {
			putchar('0');
			return;
		}
		for (auto it = a.end() - 1; it >= a.begin(); it--) {
			putchar(*it + '0');
		}
	}

	BigInteger read() {
		int c = getchar();
		a.clear();
		Vector v;
		while (c < '0' || c > '9') c = getchar();
		while (c >= '0' && c <= '9') v.push_back(c - '0'), c = getchar();
		for (auto i = v.end() - 1; i >= v.begin(); i--) {
			a.push_back(*i);
		}
		return *this;
	}

	bool operator<(cb x) const {
		if (a.size() != x.a.size()) return a.size() < x.a.size();
		for (int i = a.size() - 1; i >= 0; i--) {
			if (a[i] != x.a[i]) return a[i] < x.a[i];
		}
		return false;
	}
} a[maxn][maxn], dp[maxn][maxn];

int n, m;

void P1018() {
	scanf("%d%d", &n, &m);
	m++;
	BigInteger x;
	x.read();
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			a[i][j].a.assign(j - i + 1, 0);
			std::copy(x.a.end() - j, x.a.end() - i + 1, a[i][j].a.begin());
		}
		dp[i][1] = a[1][i];
	}
	for (int i = 2; i <= m; i++) {
		for (int r = 1; r <= n; r++) {
			for (int k = 1; k <= r; k++) {
				dp[r][i] = std::max(dp[r][i], dp[k][i - 1] * a[k + 1][r]);
			}
		}
	}
	dp[n][m].write();
	// for (int i = 1; i <= n; i++) {
	// 	for (int l = 1, r = l + i; r <= n; l++, r++) {
	// 		for (int j = 2; j <= m; j++) {
	// 			for (int k = l; r - k >= j; k++) {
	// 				dp[l][r][j] = std::max(dp[l][r][j], a[l][k] * dp[k + 1][r][j - 1]);
	// 			}
	// 		}
	// 	}
	// }
	// dp[1][n][m].write();
}

int main() {
	P1018();
	return 0;
}