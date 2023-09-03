#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int T, n, Q, lg[250010], a[250010][21], b[250010][21];
long long qwq[3010][3010];
void RMQ() {
	for(int j = 1; j <= lg[n]; ++j) {
		for(int i = 1; i + (1 << j) - 1 <= n; ++i) {
			a[i][j] = max(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
			b[i][j] = max(b[i][j - 1], b[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int quere_a(int l, int r) {
	int t = lg[r - l + 1];
	return max(a[l][t], a[r - (1 << t) + 1][t]);
}
int quere_b(int l, int r) {
	int t = lg[r - l + 1];
	return max(b[l][t], b[r - (1 << t) + 1][t]);
}
void write(long long x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x > 9) write(x / 10);
	putchar(x - x / 10 * 10 + '0');
}
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	T = read(), n = read();
	lg[0] = -1;
	for(int i = 1; i <= n; ++i) {
		lg[i] = lg[i - 1];
		if((i & (i - 1)) == 0) lg[i]++;
	}
	for(int i = 1; i <= n; ++i) a[i][0] = read();
	for(int i = 1; i <= n; ++i) b[i][0] = read();
	RMQ();
	Q = read();
	int l, r;
	if(n <= 3000 && Q <= 3000) {
		for(int i = 1; i <= n; ++i) qwq[i][i] = a[i][0] * b[i][0];
		for(int i = 1; i <= n - 1; ++i) {
			qwq[i][i + 1] = qwq[i][i] + qwq[i + 1][i + 1] + quere_a(i, i + 1) * quere_b(i, i + 1);
		}
		for(int lon = 2; lon <= n - 1; ++lon) {
			for(int i = 1; i + lon <= n; ++i) {
				int j = i + lon;
				qwq[i][j] = qwq[i][j - 1] + qwq[i + 1][j] - qwq[i + 1][j - 1] + quere_a(i, j) * quere_b(i, j);
			}
		}
		for(int i = 1; i <= Q; ++i) {
			l = read();
			r = read();
			write(qwq[l][r]);
			putchar('\n');
		}
	}
	else
	{
		for(int i = 1; i <= Q; ++i) {
			l = read();
			r = read();
			long long ans = 0;
			for(int j = l; j <= r; ++j) {
				for(int k = j; k <= r; ++k) {
					ans += (long long)quere_a(j, k) * quere_b(j, k);
				}
			}
			write(ans);
			putchar('\n');
		}
    }
    return 0;
}
