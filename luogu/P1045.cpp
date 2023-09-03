#include <cmath>
#include <cstdio>
#include <cstring>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define swap(X, Y) ((X) ^= (Y) ^= (X) ^= (Y))
#define maxn 10005

struct high {

	void init() { memset(data, 0, sizeof(data)), len = 0; }

	high operator=(const char *str) {
		init();
		len = strlen(str);
		for (int c = 0; c < len; c++) {
			data[c] = str[len - c - 1] - '0';
		}
		return *this;
	}
	high operator=(int x) {
		init();
		int c;
		for (c = 0; x > 0; c++)
			data[c] = x % 10, x /= 10;
		len = c;
		return *this;
	}

	void ar() {
		if (data[len - 1] == 0 && len > 1)
			len--, ar();
		return;
	}

	void arr() {
		ar();
		memset(data + len, 0, sizeof(data + len));
	}

	void print(const char *str = "\n") {
		arr();
		for (int c = 0; c < 500; c++) {
			printf("%d", data[500 - c - 1]);
			if (c % 50 == 49)
				printf("\n");
		}
		printf("%s", str);
	}

	int &operator[](int x) { return data[x]; }

	int data[maxn];
	int len;
};

high operator<<(high a, int x) {
	if (x == 0)
		return a;
	for (int c = a.len - 1; c >= 0; c--) {
		swap(a[c], a[c + x]);
	}
	a.len += x;
	return a;
}

high operator>>(high a, int x) {
	for (int c = 0; c < a.len; c++) {
		a[c] = a[c + x];
	}
	a.len -= x;
	return a;
}

high operator<<=(high &a, int x) { return a = a << x; }

high operator>>=(high &a, int x) { return a = a >> x; }

high operator+(high a, high b) {
	a.arr();
	b.arr();
	high h;
	h.init();
	int na = a.len, nb = b.len, n = max(na, nb), c, d = 0;
	for (int c = 0; c <= n; c++) {
		h[c] = a[c] + b[c] + d;
		d = h[c] / 10;
		h[c] %= 10;
	}
	h.len = n + 1;
	h.arr();
	return h;
}

high operator+(high a, int x) {
	high b;
	b.init();
	b = x;
	return a + b;
}

high operator+(int x, high b) { return b + x; }

high operator+=(high &a, int x) { return a = a + x; }
high operator+=(high &a, high b) { return a = a + b; }
high operator++(high &a) {
	a += 1;
	return a;
}
high operator++(high &a, int) {
	++a;
	return a;
}

high operator*(high a, int x) {
	a.arr();
	high h;
	h.init();
	int n = a.len += 10;
	for (int c = 0, d = 0; c < n; c++) {
		h[c] = a[c] * x + d;
		d = h[c] / 10;
		h[c] %= 10;
	}
	h.len = n;
	h.arr();
	return h;
}
high operator*(int x, high b) { return b * x; }

high operator*(high a, high b) {
	a.arr();
	b.arr();
	high h, x, y, z;
	h.init(), x.init(), z = 1;
	int na = a.len, nb = b.len, n = na + nb;
	for (int c = 1; c <= na; c++) {
		int x = 0;
		for (int d = 1; d <= nb; d++) {
			int s = a.data[c] * b.data[d];
			y[c + d - 1] += s + x;
			x = y[c + d - 1] / 10;
			y[c + d - 1] %= 10;
		}
		y[c + nb] = x;
	}
	h.arr();
	return h;
}

high operator*=(high &a, int x) { return a = a * x; }
high operator*=(high &a, high b) { return a = a * b; }

high operator^(high a, int x) {
	if (x == 1) {
		return a;
	}
	if (x % 2) {
		return a * ((a * a) ^ (x / 2));
	} else {
		return ((a * a) ^ (x / 2));
	}
}

int main() {
	high a, b, he;
	he = 0;
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	a = 2;
	int x;
	scanf("%d", &x);
	b = a ^ x;
	b.print();
}