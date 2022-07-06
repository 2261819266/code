#include <cstdio>
#include <cstring>
#include <algorithm>
#define long long long

struct ll {
	int a[100], len;
	ll operator=(int x) {
		for (len = 0; x > 0; len++) {
			a[len] = x % 10;
			x /= 10;
		}
		return *this;
	}
	int &operator[](int x) { return a[x]; }
	ll(int x) { *this = x; }
	ll operator+(const ll &x) const {
		ll s = 0;
		int m = std::max(len, x.len) + 1, d = 0;
		for (int &i = s.len = 0; i < m && d + a[i] + x.a[i]; s.len++) {
			s[i] = a[i] + x.a[i] + d;
			d = s[i] / 10;
			s[i] %= 10;
		}
		return s;
	}
	ll operator+=(const ll &x) { return *this = *this + x; }
	ll operator*(int x) const {
		ll s = 0;
		int d = 0;
		for (int &i = s.len = 0; i <= len; i++) {
			s[i] = a[i] * x + d;
			d = s[i] / 10;
			s[i] %= 10;
		}
		return s;
	}
	ll operator*=(int x) { return *this = *this * x; }
	ll operator*=(const ll &x) { return *this = *this * x; }
	ll operator<<(int x) const { 
		ll s = *this;
		for (int i = len - 1; i >= 0; i--) {
			s[i + x] = s[i];
			s[i] = 0;
		}
		s.len += x;
		return s;
	}
	ll operator>>(int x) const { 
		ll s = *this;
		for (int i = x; i < len; i++) {
			s[i - x] = s[i];
		}
		s.len -= x;
		return s;
	}
	ll operator*(const ll &x) {
		ll s = 0, j = 1;
		for (int i = 0; i < len; i++, j *= 10) {
			s += (x * a[i]) << i;
		}
		return s;
	}
	int operator%(int x) { return a[0]; }
	ll operator/(int x) { return x << 1; }
	bool operator<(const ll &x) {
		if (len == x.len) {
			for (int i = len - 1; i >= 0; i--)
				if (a[i] != x.a[i]) return a[i] < x.a[i];
		} else return len < x.len;
		return false;
	}
};


const int maxn = 41;

template<typename tp>
void print(tp x) {
	if (x < 0)
		x = -x, putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

ll a[maxn][maxn], ans = 0;
int n, m, l[maxn];

void init(const char *s) {
	for (int i = 0; i < n; i++) {
		a[i][i] = s[i] - '0';
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; i + j < n; j++) {
			a[j][i + j] = a[j][i + j - 1] * 10 + a[i + j][i + j];
		}
	}
}

void print() {
	ll sum = 1;
	for (int i = 0, now = 0; i < n; i++) {
		if (l[i]) {
			sum *= a[now][i];
			now = i + 1;
		}
	}
	ans = std::max(ans, sum);
}

void solve(int num, int k = -1) {
	if (num == 0) return print();
	else {
		num--;
		for (k++; k < n - 1; k++) {
			l[k]++;
			solve(num, k);
			l[k]--;
		}
	}
}

ll A, B;

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	// char s[maxn], ss[maxn];
	// scanf("%d%d%s", &n, &m, s);
	// init(s);
	// l[n - 1]++;
	// solve(m);
	// print(ans);
	A = 123, B = 321;

}