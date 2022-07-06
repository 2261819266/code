#include <bits/stdc++.h>
#define ll long long
#define int128 __int128_t

void scan(__int128 &x) {
	x = 0;
	int f = 1;
	char ch;
	if((ch = getchar()) == '-') f = -f;
	else x = x * 10 + ch - '0';
	while((ch = getchar()) >= '0' && ch <= '9')
		x = x * 10 + ch - '0';
	x *= f;
}

void print(__int128 x) {
	if(x < 0) {
		x = -x;
		putchar('-');
	}
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

void print(const char *format, ...) {
	__builtin_va_list args;
	__builtin_va_start(args, format);
	__int128_t x;
	for(int i = 0; i < strlen(format); i++) {
		if(format[i] == '%' && format[i + 1] == 'd') {
			x = __builtin_va_arg(args, __int128_t);
			print(x);
			i++;
			continue;
		}
		printf("%c", format[i]);
	}
}

inline int128 gcd(int128 x, int128 y) {
	// if (y > x)
	// 	std::swap(x, y);
	return x % y ? gcd(y, x % y) : y;
}

struct Number {
	int128 s, m;
	Number(int128 x = 0) { *this = x; }

	Number(int128 x, int128 y) { s = x, m = y; }

	void updata() {
		int128 k = gcd(s, m);
		s /= k, m /= k;
	}

	Number operator=(int128 x) {
		s = x, m = 1;
		return *this;
	}

	Number operator+(const Number &x) {
		Number y;
		y.m = m * x.m;
		y.s = s * x.m + x.s * m;
		y.updata();
		return y;
	}

	Number operator+=(const Number &x) { return *this = *this + x; }

	Number operator/(const Number &x) {
		Number y;
		y.s = s * x.m;
		y.m = m * x.s;
		y.updata();
		return y;
	}

	Number operator/=(const Number &x) { return *this = *this / x; }
};

const int maxn = 1e5 + 5;

int n, m;
struct node {
	int outQua, inQua;
	std::vector<int> out, in;
	Number water;

	void push_out(int x) { out.push_back(x), outQua++; }
	void push_in(int x) { in.push_back(x), inQua++; }

	int pop_out() {
		int x = out.back();
		out.pop_back(), outQua--;
		return x;
	}
	int pop_in() {
		int x = in.back();
		in.pop_back(), inQua--;
		return x;
	}
} a[maxn];

template <typename T> struct queue {
	T a[maxn];
	int head, tail;
	void push(T x) { a[++tail] = x; }
	T pop() { return a[++head]; }
	T front() const { return a[head + 1]; }
	T back() const { return a[tail]; }
	int size() const { return tail - head; }
	bool empty() { return !size(); }
};

queue<node *> q, k;

inline void read() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int c = 1; c <= n; c++) {
		int nn;
		scanf("%d", &nn);
		for (int d = 1; d <= nn; d++) {
			int x;
			scanf("%d", &x);
			a[c].push_out(x);
			a[x].push_in(c);
		}
	}
}

inline void solve() {
	for (int c = 1; c <= n; c++) {
		if (!a[c].inQua)
			a[c].water = 1, q.push(&a[c]);
		if (!a[c].outQua)
			k.push(&a[c]);
	}
	while (!q.empty()) {
		node *x = q.front();
		if (!x->outQua) {
			q.pop();
			continue;
		}
		Number k = x->water / x->outQua;
		while (x->outQua) {
			int y = x->pop_out();
			a[y].water += k, a[y].pop_in();
			if (!a[y].inQua)
				q.push(&a[y]);
		}
		q.pop();
	}
}

void print() {
	while (!k.empty()) {
		// std::cout << k.front()->water.s << k.front()->water.m;
		print("%d %d\n", k.front()->water.s, k.front()->water.m);
		k.pop();
	}
}

int main(int argc, char const *argv[]) {
	read();
	solve();
	print();
	return 0;
}