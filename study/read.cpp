#include <cstdio>

template<typename tp> 
void scan(tp &x) {
	x = 0;
	int sign = 1;
	char c;
	if ((c = getchar()) == '-')
		sign = -1;
	else
		x = x * 10 + c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		x = x * 10 + c - '0';
	x *= sign;
}

template<typename tp>
void print(tp x) {
	if (x < 0)
		x = -x, putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int main(int argc, char const *argv[]) {
	int x;
	scan(x);
	print(x);
	return 0;
}

