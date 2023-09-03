#include <cstdio>
#include <cstring>
#include <algorithm>

template <class T>
inline void read(T &x) {
	static char s;
	static bool opt;
	while (s = getchar(), (s < '0' || s > '9') && s != '-');
	x = (opt = s == '-') ? 0 : s - '0';
	while (s = getchar(), s >= '0' && s <= '9') x = x * 10 + s - '0';
	if (opt) x = ~x + 1;
}

const int N = 1010;
const int mod = 998244353;

void add(int &x, const int &y) {
	x += y;
	if (x >= mod) x -= mod;
}

int T, test_id;
int n, m, type_c, type_f;

char str[N][N];

int rg[N][N];

int ans_c, ans_f;

void work() {
	read(n), read(m), read(type_c), read(type_f);

	for (int i = 1; i <= n; i ++)
		scanf("%s", str[i] + 1);

	for (int i = 1; i <= n; i ++) {
		rg[i][m + 1] = 0;
		for (int j = m; j >= 1; j --) {
			if (str[i][j] == '1')
				rg[i][j] = 0;
			else
				rg[i][j] = rg[i][j + 1] + 1;
		}
	}

	ans_c = ans_f = 0;

	int cnt, last_i = 0;

	for (int j = m; j >= 1; j --) {
		cnt = 0;
		for (int i = n; i >= 1; i --) {
			if (str[i][j] == '1') {
				cnt = 0;
			} else {
				ans_c = (ans_c + 1ll * (rg[i][j] - 1) * cnt) % mod;

				if (i < n && str[i + 1][j] == '0')
					add(cnt, rg[i + 1][j] - 1);
			}
		}
	}

	for (int j = m; j >= 1; j --) {
		cnt = 0;
		for (int i = n; i >= 1; i --) {
			if (str[i][j] == '1') {
				cnt = 0;
			} else {
				if (i == n || str[i + 1][j] == '1') last_i = i;

				ans_f = (ans_f + 1ll * (rg[i][j] - 1) * cnt) % mod;

				if (i < n && str[i + 1][j] == '0')
					cnt = (cnt + 1ll * (last_i - (i + 1)) * (rg[i + 1][j] - 1)) % mod;
			}
		}
	}

	printf("%d %d\n", type_c * ans_c, type_f * ans_f);
}

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);

	read(T), read(test_id);

	while (T --)
		work();

	return 0;
}

// changle_cyx huge.
// xyz32768 huge.
