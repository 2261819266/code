#include <cstdarg>
#include <cstdio>
#include <cstring>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define IsNumber(X) ((X) >= '0' && (X) <= '9')
#define IsLetter(X) ((X) >= 'A' && (X) <= 'Z')
const int maxn = 1000;
#define CharToInt(X) (IsNumber(X) ? X - 48 : X - 55)

template <class T> void swap(T &a, T &b) {
	T x = a;
	a = b, b = x;
}

class number {
private:
	int base;
	int data[maxn];
	int len;
	void intTonumber(const char *str) {
		memset(data, 0, sizeof(data));
		int n = strlen(str);
		for (int c = 0; c < n; c++) {
			data[c] = CharToInt(str[n - c - 1]);
		}
		len = n;
	}

	void updata() {
		for (int c = len; c > 0 && data[c - 1] == 0; c--)
			len--;
	}

public:
	number init() {
		number x;
		memset(x.data, 0, sizeof(x.data));
		x.len = 0;
		return x;
	}

	void input(int base, const char *str) {
		this->base = base;
		intTonumber(str);
	}

	number turn() {
		updata();
		number x = *this;
		for (int c = 0; c * 2 < len; c++)
			// data
			swap(x[c], x[len - c - 1]);
		return x;
	}

	void print() {
		for (int c = len - 1; c >= 0; c--)
			printf("%d", data[c]);
	}

	int &operator[](int x) { return x < len ? data[x] : (data[x] = 0); }

	number operator+(number x) {
		number he = init();
		int n = max(len, x.len);
		he.len = n + 1;
		for (int c = 0, d = 0; c <= n; c++) {
			he[c] = (*this)[c] + x[c] + d;
			d = he[c] / base;
			he[c] %= base;
		}
		he.updata();
		return he;
	}

	bool Ishui() {
		for (int c = 0; c * 2 < len; c++) {
			if (data[c] != data[len - c - 1])
				return false;
		}
		return true;
	}
};

inline void scanf(int n, ...) {
	va_list args;
	va_start(args, n);
	for (int c = 0; c < n; c++) {
		number *x = va_arg(args, number *);
		char *str = new char;
		int y;
		scanf("%d", &y);
		scanf("%s", str);
		x->input(y, str);
		// delete str, x;
	}
	va_end(args);
}

inline void print(const char *str, ...) {
	va_list args;
	va_start(args, str);
	for (int c = 0; c < strlen(str); c++) {
		if (str[c] == '%') {
			if (str[c + 1] == 'h') {
				number x = va_arg(args, number);
				x.print();
				c++;
				continue;
			}
			// if (str[c + 1] == 'd')
			// 	printf("%d", va_arg(args, int));
		}
		printf("%c", str[c]);
	}
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	number a, b;
	int x = 0;
	scanf(1, &a);
	while (!a.Ishui()) {
		x++;
		b = a.turn();
		a = a + b;
		if (x == 30) {
			printf("Impossible!");
			return 0;
		}
	}
	printf("STEP=%d", x);
}

