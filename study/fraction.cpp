#include <cstdio>
#include <cstring>
#define ll long long

template<typename T>
T gcd(T x, T y) { return x % y ? gcd(y, x % y) : y; }

template<typename T>
T lcm(T x, T y) { return x / gcd(x, y) * y; }

template<typename T>
T reduction(T &x, T &y) {
	T k = gcd(x, y);
	x /= k, y /= k;
	return k;
}

template<typename tp>
class fraction {
private:
	tp s, m; // s / m
public:
	fraction(tp x = 0, tp y = 1) {
		if(y == 0) {
			fprintf(fopen("con", "w"), "error\n\n\n");
			// getchar();
			return;
		}
		tp k = gcd(x, y);
		s = x / k;
		m = y / k;
	}

	tp getSon() { return s; }

	tp getMother() { return m; }

	fraction updata() const {
		fraction x = *this;
		tp k = gcd(x.s, x.m);
		x.s /= k;
		x.m /= k;
		return x;
	}

	template<typename tp_o> operator tp_o() const { return (tp_o)s / (tp_o)m; }

	template<typename tp_o> fraction operator=(tp_o x) { s = x, m = 1; return *this;}

	template<typename tp_o> fraction operator+(tp_o x) const {
		fraction y = updata();
		y.s += y.m * x;
		return y;
	}

	fraction operator+(const fraction &y) const {
		fraction z = (fraction) {s * y.m + m * y.s, m * y.m};
		z.updata();
		return z;
	}

	template<typename tp_o> fraction operator+=(tp_o x) { return *this = *this + x; }

};

#define fll fraction<ll>

void frprintf(const char *__format, ...) {
	__builtin_va_list args;
	__builtin_va_start(args, __format);
	fll *next;
	for (int i = 0; i < strlen(__format); i++) {
		if (__format[i] == '%') {
			const char *p = __format + i + 1;
			switch (*p) {
				case 'g' : next = __builtin_va_arg(args, fll*); break;
				case 's' : printf("%d", next->getSon()); break;
				case 'm' : printf("%d", next->getMother()); break;
				case '%' : printf("%%"); break;
			
			default:
				printf("%c", __format[i]);
				i--;
				break;
			}
			i++;
			continue;
		}
		printf("%c", __format[i]);
	}
}

int main(int argc, char const *argv[]) {
	fraction<ll> a(3, 4);
	frprintf("%g%s / %m", fll(1, 4) + fll(3, 10));
	return 0;
}
