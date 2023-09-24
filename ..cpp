#include <cstdio>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

const int n = 1e7;
bool St;

void test_cout() {
	for (int i = 0; i < n; i++) {
		cout << i << "\n";
	}
}

void test_printf() {
	for (int i = 0; i < n; i++) {
		printf("%d\n", i);
	}
}

void print(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

void test_print() {
	for (int i = 0; i < n; i++) {
		print(i);
		putchar('\n');
	}
}


bool Ed;

int main(int argc, char **args) {
	std::ios::sync_with_stdio(false);
	for (int i = 0; i < argc; i++) {
		cerr << args[i] << "\n";
	}
	cerr << "\n" << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
	cout.tie(nullptr);
	// test_cout();
	cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
}