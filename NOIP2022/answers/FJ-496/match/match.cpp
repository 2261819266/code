#include <bits/stdc++.h>
using namespace std;

const int N = 500005, mod = 1.844674407370955e+19;

long long n, t, a[N], b[N];
long long q;
long long x, y;
long long ans;
long long maxa, maxb;
bool f1, f2;

void query(long long l, long long r) {
	long long ma = 0, mb = 0;
	for (long long i = l; i <= r; i ++) {
		ma = max(ma, a[i]);
		mb = max(mb, b[i]);
	}
	ans += (ma * mb);
	return ;
}

int main () {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%lld %lld", &t, &n);
	for (long long i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
		if (a[i] < maxa) f1 = true;
		maxa = max(maxa, a[i]);
	}
	for (long long i = 1; i <= n; i ++) {
		scanf("%lld", &b[i]);
		if (b[i] < maxb) f2 = true;
		maxb = max(maxb, b[i]);
	}	
	cin >> q;
	for (long long i = 1; i <= q; i ++) { 
		scanf("%lld %lld", &x, &y);
		for (long long j = x; j <= y; j ++) {
			for (long long k = j; k <= y; k ++) {
				if (f1 == true && f2 == true) ans += a[k] * b[k];
				else {
					if (j == k) ans += a[j] * b[k];
					else query(j, k);
				}
			}
		}
	}
	printf("%lld\n", ans % mod);
	return 0;
}
