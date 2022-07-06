#include <cstdio>
#define maxn 100100
#define ll long long
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define abs(X) ((X) > 0 ? (X) : -(X))

ll a[maxn];
ll b[maxn];

void cf(const int n) {
	b[0] = a[0];
	for (int c = 1; c < n; c++) {
		b[c] = a[c] - a[c - 1];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int c = 0; c < n; c++) {
		scanf("%lld", &a[c]);
	}
	cf(n);
	ll up = 0, down = 0;
	for (int c = 1; c < n; c++) {
		(b[c] > 0 ? up : down) += b[c];
	}
	down = -down;
	printf("%lld\n%lld", max(up, down), abs(up - down) + 1);
}