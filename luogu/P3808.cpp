#include <cstdio>
#include <cstring>
#include <queue>
#define f(x, y, z) for (int x = y, __ = z; x < __; ++x)

const int maxn = 1e6 + 8;

struct Trie {
#define word (s[i] - 'a')
#define pw (c[p][word])
#define pi (c[p][i])
	const int r = 0;
	int c[maxn][26], fail[maxn], cnt[maxn], t = r;
	void insert(const char *s) {
		int p = r;
		f(i, 0, strlen(s)) {
			if (!pw) pw = ++t;
			p = pw;
		}
		cnt[p]++;
	}

	void buildFail() {
		std::queue<int> q;
		f(i, 0, 26) if (c[r][i]) q.push(c[r][i]), fail[c[r][i]] = r;
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			f(i, 0, 26) {
				if (pi) fail[pi] = c[fail[p]][i], q.push(pi);
				else pi = c[fail[p]][i];
			}
		}
	}

	int query(const char *s) {
		int p = r, ans = 0;
		f(i, 0, strlen(s)) {
			p = pw;
			for (int j = p; j && ~cnt[j]; j = fail[j]) {
				ans += cnt[j];
				cnt[j] = -1;
			}
		}
		return ans;
	}
} AC;

char s[maxn];

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int n;
	scanf("%d", &n);
	f(i, 0, n) scanf("%s", s), AC.insert(s);
	scanf("%s", s);
	AC.buildFail();
	printf("%d", AC.query(s));
}