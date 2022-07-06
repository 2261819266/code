#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using std::vector;

class BigInteger {
private:
#define ll long long int
#define ull unsigned ll
	static const int base = 1e8;
	static const int width = 8;
	static const int maxn = 1e5 + 3;
	vector<ull> s;
public:
	BigInteger(ull num = 0) { *this = num; }

	BigInteger operator=(ull num) {
		s.clear();
		do {
			s.push_back(num % base);
			num /= base;
		} while(num);
		return *this;
	}

	BigInteger operator=(const char *str) {
		s.clear();
		int x, n = (strlen(str) - 1) / width + 1;
		for(int i = 0; i < n; i++) {
			int end = strlen(str) - i * width;
			int start = std::max(0, end - width);
			sscanf(strncpy(new char[width << 1], str + start, end - start), "%d", &x);
			s.push_back(x);
		}
		return *this;
	}

	void input() {
		char *str = new char[maxn];
		scanf("%s", str);
		*this = str;
	}

	void output() {
		printf("%d", s.back());
		for (int i = s.size() - 2; i >= 0; i--) {
			printf("%08d", s[i]);
		}
	}

	BigInteger operator+(const BigInteger &b) const {
		BigInteger c;
		c.s.clear();
		for (int i = 0, g = 0; true; i++) {
			if (g == 0 && i >= s.size() && i >= b.s.size()) break;
			int x = g;
			if (i < s.size()) x += s[i];
			if (i < b.s.size()) x += b.s[i];
			c.s.push_back(x % base);
			g = x / base;
		}
		return c;
	}

	BigInteger operator+=(const BigInteger &b) { return *this = *this + b; }

	BigInteger operator*(ull b) const {
		BigInteger c;
		ull g = 0;
		c.s.clear();
		for (int i = 0; true; i++) {
			if (g == 0 && i >= s.size()) break;
			ull x = b * s[i];
			g += x;
			c.s.push_back(g % base);
			g /= base;
		}
		return c;
	}

	/**
	 * @return *this * pow(base, x).
	*/
	BigInteger operator<<(int x) const {
		BigInteger y;
		for(int i = 1; i < s.size() + x; i++) {
			y.s.push_back(0);
		}
		for(int i = s.size() - 1; i >= 0 ; i--) {
			y.s[i + x] = s[i];
		}
		return y;
	}
	
	BigInteger operator<<=(int x) {
		return *this = *this << x;
	}

	BigInteger operator*(const BigInteger &b) const {
		BigInteger c;
		c.s.clear();
		ull g = 0;
		for(int i = 0; true; i++) {
			if(g == 0 && i >= b.s.size()) break;
			BigInteger k;
			k = *this * b.s[i];
			c += k << i;
		}
		return c;
	}

	BigInteger operator*=(const BigInteger &b) {
		return *this = *this * b;
	}
} a, b;

void bscanf(const char *format, ...) {
	__builtin_va_list args;
	__builtin_va_start(args, format);
	BigInteger *next;
	for (int i = 0; i < strlen(format); i++){
		if(format[i] == '%' && format[i + 1] == 'd') {
			next = __builtin_va_arg(args, BigInteger*);
			next->input();
			i++;
			continue;
		}
	}
}

void bprintf(const char *format, ...) {
	__builtin_va_list args;
	__builtin_va_start(args, format);
	BigInteger *p;
	for(int i = 0; i < strlen(format); i++) {
		if(format[i] == '%' && format[i + 1] == 'd') {
			p = __builtin_va_arg(args, BigInteger*);
			p->output();
			i++;
			continue;
		}
		putchar(format[i]);
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	bscanf("%d%d", &a, &b);
	bprintf("%d", a * b);
	return 0;
}
