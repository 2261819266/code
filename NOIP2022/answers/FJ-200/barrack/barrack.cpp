#include <cstdio>

const int mod = 1e9 + 7;

int pow(int x, int p) {
	int ans = 1;
	while (p) {
		if (p & 1) ans = (long long)ans * x % mod;
		x = (long long)x * x % mod;
		p >>= 1;
	}
	return ans;
}

int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	printf("%lld\n", (n * 2 + (long long)n * (n - 1) / 2) % mod * pow(2, n - 2) % mod);
}
