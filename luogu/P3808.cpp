#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = 1e6 + 8;

struct Trie {
#define word s[i] - 'a'
#define pword a[p][word]
#define f26 for (int i = 0; i < 26; i++)
#define fs for (int i = 0; s[i]; i++)
	static const int root = 0;
	int a[maxn][26], fail[maxn], v[maxn], cnt;
	void insert(const char *s) {
		int p = root;
		fs {
			if (!pword) pword = ++cnt;
			p = pword; 
		}
		v[p]++;
	}

	void buildFail() {
		std::queue<int> q;
		f26 if (a[root][i]) fail[a[root][i]] = root, q.push(a[root][i]);
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			f26 {
				
			}
		}
	}
};
