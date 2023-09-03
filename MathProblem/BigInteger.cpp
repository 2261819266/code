#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
#include <iostream>


using std::vector;
using std::string;
using std::cin;

class BigInteger {
private:
	vector<ull> a;
	const ull Bit = 16, Base = 1e16;

	ull &operator[](ull x) {
		return a[x];
	}

public:

	BigInteger operator=(ull x) {
		a.clear();
		do {
			a.push_back(x % Base);
			x /= Base;
		} while (x > 0);
		return *this;
	}

	BigInteger operator=(const string &s) {
		a.assign(s.size() / Bit + 1, 0);
		for (int i = 0; i < s.size(); i++) {
			int c = s[i] - '0';
			int b = (s.size() - i - 1) / Bit;
			a[b] = a[b] * 10 + c;
		}
		return *this;
	}

	BigInteger operator=(const char *s) {
		return *this = (string)s;
	}

	BigInteger(ull x = 0) {
		*this = x;
	}

	template<typename t>
	BigInteger(t x) {
		*this = x;
	}

	ull size() const {
		return a.size();
	}

	void clear() {
		a.clear();
	}

	BigInteger operator+(const BigInteger &b) const {
		ull n = std::max(this->size(), b.size());
		BigInteger ans;
		ans.clear();
		for (ull i = 0, d = 0; i < n || d; i++) {
			ull x = d;
			x += size() <= i ? 0 : a[i];
			x += b.size() <= i ? 0 : b.a[i];
			ans.a.push_back(x);
			d = ans[i] / Base;
			ans[i] %= Base;
		}
		return ans;
	}

	void print() {
		for (int i = size() - 1; i >= 0; i--) {
			char str[Bit];
			sprintf(str, "%llu", a[i]);
			string s = str;
			if (i < size() - 1) {
				while (s.size() < Bit) {
					s = "0" + s;
				}
			}
			std::cout << s;
		}
	}

	void scan() {

	}
};

int main() {
	// ull x = 1;

	BigInteger a, b;
	string sa, sb;
	cin >> sa >> sb;
	a = sa, b = sb;
	// a.print();
	// putchar(10);
	// b.print();

	(a + b).print();
}