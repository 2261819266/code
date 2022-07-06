#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = 1e6 + 8;
struct Trie {
#define word s[i] - 'a'
#define f26 for (int i = 0; i < 26; i++)
#define pc f->child[i]
#define pw p->child[word]
	struct Node {
		Node *child[26], *fail;
		int data;
	};

	Node *root = new Node();
		
	void insert(const char *s) {
		Node *p = root;
		for (int i = 0; s[i]; i++) {
			if (!pw) pw = new Node();
			p = pw; 
		}
		p->data++;
	}

	void buildFail() {
		std::queue<Node *> q;
		f26 {
			if (root->child[i])
				root->child[i]->fail = root;
		}
		while (!q.empty()) {
			Node *f = q.front();
			q.pop();
			f26 {
				if (pc) {
					Node *ffail = f->fail;
					while (ffail && !ffail->child[i]) {
						ffail = ffail->fail;
					}
					pc->fail = ffail ? ffail->child[i] : root;
				}
			}
		}
	}

	int query(const char *s) {
		Node *p = root;
		int ans = 0;
		for (int i = 0; s[i]; i++) {
			while (!pw && p->fail) {
				p = p->fail;
			}
			if (pw) p = pw;
			else continue;
			Node *p2 = p;
			while (p2) {
				ans += p2->data;
				p2->data = 0;
				p2 = p2->fail;
			} 
		}
		return ans;
	}
} AC;

char a[maxn], x[maxn];

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", x);
		AC.insert(x);
	}
	AC.buildFail();
	scanf("%s", a);
	printf("%d\n", AC.query(a));
}