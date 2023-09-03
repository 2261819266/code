#include <cstdio>
#include <cstring>
#include <queue>

struct Trie {
#define word str[i] - 'a'
#define pword p->child[word]
	static const int maxn = 1e6 + 8;
	static const int maxl = 26;
	struct Node {
		int cnt;
		Node *child[maxl];
		Node *fail;
	};

	Node *root = new Node();

	Node *insert(const char *str) {
		Node *p = root;
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
			if (!pword) {
				pword = new Node();
			}
			p = pword;
		}
		p->cnt++;
		return p;
	}

	Node *operator+=(const char *str) { return this->insert(str); }

	void makeFail() {
		std::queue<Node *> q;
		for (int i = 0; i < maxl; i++) {
			if (root->child[i]) {
				root->child[i]->fail = root;
				q.push(root->child[i]);
			}
		}
		while (q.size()) {
			Node *f= q.front();
			q.pop();
			for (int i = 0; i < maxl; i++) {
				if (f->child[i]) {
					Node *p = f->child[i];
					Node *ffail = f->fail;
					while (ffail && !ffail->child[i]) {
						ffail = ffail->fail;
					}
					if (ffail)
						p->fail = ffail->child[i];
					else
						p->fail = root;
					q.push(p);
				}
			}
		}
	}

	int query(const char *str) {
		Node *p = root;
		int ans = 0;
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			while (!pword && p->fail) {
				p = p->fail;
			}
			if (pword) p = pword;
			else continue;
			Node *p2 = p;
			while (p2) {
				ans += p2->cnt;
				p2->cnt = 0;
				p2 = p2->fail;
			}
		}
		return ans;
	}
} trie;

char p[Trie::maxn],t[Trie::maxn]; 

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", p);
		trie += p;
	}
	scanf("%s", t);
	trie.makeFail();
	printf("%d\n", trie.query(t));
}