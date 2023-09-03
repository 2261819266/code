#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 2.5e5 + 10, MAX_LOG = 20;
int T, n, log_2[MAX_N];
void init_log() {
	log_2[1] = 0, log_2[2] = 1;
	for(int i = 3; i <= n; i++)
		log_2[i] = log_2[i >> 1] + 1;
}
struct st {
	int mx[MAX_N][MAX_LOG];
	void init() {
		for(int j = 1; j < MAX_LOG; j++)
			for(int i = 1; i + (1 << (j - 1)) - 1 <= n; i++)
				mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
	}
	int query(int l, int r) {
		int len = log_2[r - l + 1];
		return max(mx[l][len], mx[r - (1 << len) + 1][len]);
	}
} a, b;

inline ll read() {
	ll ret = 0, w = 1; char c = getchar();
	while(!isdigit(c))	{if(c == '-')	w = -1; c = getchar();}
	while(isdigit(c))	{ret = (ret << 1) + (ret << 3) + (c ^ 48); c = getchar();}
	return ret * w;
}
char buf[100];
inline void write(ll x) {
	if(x < 0)	putchar('-'), x = -x;
	int tp = 0;
	do {buf[++tp] = x % 10 + 48; x /= 10;} while(x);
	while(tp) putchar(buf[tp--]);
}


int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	T = read(), n = read();
	init_log();
	for(int i = 1; i <= n; i++)
		a.mx[i][0] = read();
	for(int i = 1; i <= n; i++)
		b.mx[i][0] = read();
	int q = read();
	a.init(), b.init();
	while(q--) {
		int l = read(), r = read();
		unsigned long long ans = 0;
		for(int i = l; i <= r; i++)
			for(int j = i; j <= r; j++)
				ans += 1ull * a.query(i, j) * b.query(i, j);
		write(ans);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
