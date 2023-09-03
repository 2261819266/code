#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353, MAX_N = 1e3 + 10;
bool a[MAX_N][MAX_N];
int p[MAX_N][MAX_N], q[MAX_N][MAX_N], n, m, c, f;
int sum1[MAX_N][MAX_N], sum2[MAX_N][MAX_N];
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
inline bool read_bool() {
	char c = getchar();
	while(c != '0' && c != '1')	c = getchar();
	return c - 48;
}
void pre() {
	for(int i = 1; i <= n; i++) {
		int lst = -1;
		for(int j = m; j >= 1; j--) {
			if(!a[i][j]) {
				if(lst == -1)	lst = j;
				p[i][j] = lst;
			}
			else	lst = p[i][j] = -1;
		}
	}
	for(int j = 1; j <= m; j++) {
		int lst = -1;
		for(int i = n; i >= 1; i--) {
			if(!a[i][j]) {
				if(lst == -1)	lst = i;
				q[i][j] = lst;
			}
			else	lst = q[i][j] = -1;
		}
	}
	for(int j = 1; j <= m; j++) {
		for(int i = 1; i <= n; i++) {
			sum1[i][j] = sum2[i][j] = 0;
			if(p[i][j] == -1)	continue;
			sum1[i][j] = sum1[i - 1][j] + p[i][j] - j;
			if(q[i][j] == -1)	continue;
			sum2[i][j] = sum2[i - 1][j] + (p[i][j] - j) * (q[i][j] - i);
		}
	}
}
int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int T = read(), id = read();
	while(T--) {
		n = read(), m = read(), c = read(), f = read();
		ll vc = 0, vf = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				a[i][j] = read_bool();
		if(id == 1) {
			write(0), putchar(' '), write(0);
			putchar('\n');
			continue;
		}
		pre();
		for(int i = 1; i <= n - 2; i++) {
			for(int j = 1; j <= m - 1; j++) {
				int leni = p[i][j] - j, lenj = q[i][j] - i;
				if(lenj >= 2 && leni >= 1) {
					(vc += 1ll * leni * (sum1[q[i][j]][j] - sum1[i + 1][j])) %= MOD;
					(vf += 1ll * leni * (sum2[q[i][j]][j] - sum2[i + 1][j])) %= MOD;
				}
			}
		}
		write(vc * c), putchar(' '), write(vf * f);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
