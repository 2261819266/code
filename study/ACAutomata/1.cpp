#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

const int maxl = 26;
const int maxn = 1e1 + 8;

struct Node {
	int child[maxl] = {};
	int cnt = 0;
	int &operator[](int x) {
		return child[x];
	}
	int fail = -1;
};

Node trie[maxn];

int idx = 0;

void insert(const char *s) {
	int p = 0;
	for (int i = 0; i < strlen(s); i++) {
		int w = s[i] - 'a';
		if (!trie[p][w]) trie[p][w] = ++idx;
		p = trie[p][w];
	}
	trie[p].cnt++;
} 

const char *p[] = {"she", "he", "her", "his", "this", "is"};
const char *t = "sherthis";

void fail_pre() {
	std::queue<int> q;
	for (int i = 0; i < maxl; i++) {
		if (trie[0][i]) {
			int c = trie[0][i];
			trie[c].fail = 0;
			q.push(c);
		}
	}
	while (q.size()) {
		int f = q.front();
		q.pop();
		for (int i = 0; i < maxl; i++) {
			if (trie[f][i]) {
				int now = trie[f][i];
				int ffail = trie[f].fail;
				while (~ffail && !trie[ffail][i]) {
					ffail = trie[ffail].fail;
				}
				if (~ffail) trie[now].fail = trie[ffail][i];
				else trie[now].fail = 0;
				q.push(now);
			}
		}
	}
}

int query(const char *s) {
	int ans = 0;
	int p = 0;
	for (int i = 0; i < strlen(s); i++) {
		int w = s[i] - 'a';
		while (!trie[p][w] && ~trie[p].fail) {
			p = trie[p].fail;
		}
		if (trie[p][w])
			p = trie[p][w];
		else continue;
		int p2 = p;
		while (~trie[p2].fail) {
			ans += trie[p2].cnt;
			p2 = trie[p2].fail;
		}
	}
	return ans;
}

int main() {
	// trie.resize(maxn);
	for (int i = 0; i < 6; i++) {
		insert(p[i]);
	}
	fail_pre();
	printf("%d\n", query(t));
}