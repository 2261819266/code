#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

unsigned long long ma[3005][3005], mb[3005][3005], s[3005][3005], d[3005][3005], a[3005], b[3005], t, n, c[3005], q, p = 1 << 64;

inline unsigned long long read() {
	unsigned long long n = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') { n = n * 10 + c - 48, c = getchar();}
	return n;
}

inline unsigned long long lowbit(int x) {
	return x & -x;
}

inline void add(int x, int v) {
	while (x <= n) {
		c[x] = c[x] + v;
		x += lowbit(x);
	}
}

inline unsigned long long qr(int x) {
	unsigned long long ans = 0;
	while (x) {
		ans = ans + c[x];
		x -= lowbit(x);
	}
	return ans;
}

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	t = read(), n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), ma[i][1] = a[i];
	for (int i = 1; i <= n; i++) b[i] = read(), mb[i][1] = b[i], s[i][1] = a[i] * b[i];
	
	for (int i = 2; i <= n; i++)
	  for (int j = 1; j <= n - i + 1; j++)
	    ma[j][i] = max(ma[j][i - 1], ma[j + 1][i - 1]),
	    mb[j][i] = max(mb[j][i - 1], mb[j + 1][i - 1]),
		s[j][i] = ma[j][i] * mb[j][i];
		
	for (int i = 1; i <= n; i++) d[i][1] = s[i][1], add(i, s[i][1]);
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) d[j][i] = (qr(j + i - 1) - qr(j - 1) + s[j][i]);
		memset(c, 0, sizeof c);
		for (int j = 1; j <= n - i + 1; j++) add(j, d[j][i]);
	}
	q = read();
	while (q--) {
		unsigned long long a = read(), b = read(), f = b - a + 1;
		printf("ull\n", d[a][f]);
	}
}
