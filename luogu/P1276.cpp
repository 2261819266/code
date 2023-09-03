#include <cstdio>
#include <cstring>
#define ll long long

const int maxn = 1e4 + 8;
ll a[maxn], ans, ans1;

void add(int l, int r, int k) {
	if (k < 0) {
		for(int i = l; i <= r; i++) {
			if(a[i] == -1)
				ans++;
			a[i] = 0;
		}
		return;
	}
	for(int i = l; i <= r; i++) {
		a[i] = a[i] <= 0 ? -1 : 1;
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	memset(a, 1, sizeof(ll) * (n + 1));
	for(int i = 0; i < m; i++) {
		int x, y, k;
		scanf("%d%d%d", &k, &x, &y);
		add(x, y, !k ? -1 : 1);
	}
	for(int i = 0; i <= n; i++) {
		if(a[i] < 0)
			ans1++;
	}
	printf("%lld\n%lld\n", ans1, ans);
	return 0;
}
