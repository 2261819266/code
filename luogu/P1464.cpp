#include <algorithm>
#include <cstdio>
#define ll long long

const int maxn = 25;
int a[maxn][maxn][maxn];

int f(ll x, ll y, ll z) {
	if (x <= 0 || y <= 0 || z <= 0)
		return 1;
	if (x > 20 || y > 20 || z > 20)
		return f(20, 20, 20);
	if (!a[x][y][z]) {
		if (x < y && y < z)
			a[x][y][z] = f(x, y, z - 1) + f(x, y - 1, z - 1) - f(x, y - 1, z);
		else
			a[x][y][z] =
				f(x - 1, y, z) + f(x - 1, y - 1, z) + f(x - 1, y, z - 1) - f(x - 1, y - 1, z - 1);
	}
	return a[x][y][z];
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	while (true) {
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		if (x == -1 && y == -1 && z == -1)
			return 0;
		printf("w(%d, %d, %d) = %d\n", x, y, z, f(x, y, z));
	}
	return 0;
}
