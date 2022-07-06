#include <cstdio>
#include <cstring>
#define _str2 ".in"
#define _str3 ".out"

const int maxn = 1005;

class H {
private:
	int data[maxn];
	int len;

	void updata() {
		while (len && data[len - 1] == 0) {
			len--;
		}
		len == 0 ? len = 1, data[0] = 0 : 0;
	}

	void init() { memset(data, 0, sizeof(data)), len = 1; }

	int &operator[](int x) { return data[x]; }

public:
	H() { init(); }
	H(const char *str) {
		init();
		len = strlen(str);
		for (int c = 0; c < len; c++) {
			data[c] = str[len - c - 1] - 48;
		}
		updata();
	}

	H operator+(H x) {
		H y = "0";
		y.len = len + x.len + 1;
		for (int c = 0, d = 0; c < y.len; c++) {
			y[c] = x[c] + (*this)[c] + d;
			d = y[c] / 10;
			y[c] %= 10;
		}
		y.updata();
		return y;
	}
	void print() {
		for (int c = len - 1; c >= 0; c--)
			printf("%d", data[c]);
	}
	void scan() {
		char str[maxn];
		scanf("%s", str);
		*this = str;
	}
};

H a[maxn];

H f(int x) { return a[x]; }

char _str4[3] = {'0'};

int main() {
	int x;
	scanf("%d",&x);
	a[1] = "0", a[2] = "1";
	for (int c = 3; c <= 1000; c++) {
		a[c] = a[c - 1] + a[c - 2];
	}
	f(x).print();
}