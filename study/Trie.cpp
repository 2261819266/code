#include <cstdio>
#include <cstring>

const int maxn = (1e4 + 8) * 52;

// struct Trie {
// 	int a[maxn][26], cnt[maxn], t = 1;
// 	static const int root = 1;
	
// 	void add(const char *str) {
// 		int i;
// 		for (i = root; *str; str++) {
// 			int c = *str - 'a';
// 			a[i][c] ? i = a[i][c] : (a[i][c] = ++t, i = t);
// 		}
// 		cnt[i]++;
// 	}
	
// 	int find(const char *str) {
// 		int i;
// 		for (i = root; *str; str++) {
// 			int c = *str - 'a';
// 			i = a[i][c];
// 		}
// 		return cnt[i] < 0 ? -1 : cnt[i] > 0 ? (cnt[i] = -1) + 2 : 0;
// 	}
// } s;

struct Node {
	static const int maxLetter = 128;
	Node *data[maxLetter];
	int cnt;

	Node() { memset(data, 0, sizeof(data)), cnt = 0; }

	Node *add(const char *str) {
		Node *i;
		for (i = this; *str; str++) {
			int c = *str;
			!i->data[c] ? i = i->data[c] = new Node : i = i->data[c];
		}
		i->cnt++;
		return i;
	}

	int find(const char *str) {
		Node *i;
		for (i = this; *str; str++) {
			int c = *str;
			if (i->data[c]) i = i->data[c];
			else return 0;
		}
		int k = i->cnt;
		if (i->cnt > 0) i->cnt = -1;
		return k;
	}

	Node *operator+(const char *str) { return add(str); }
} s;


int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char *str = new char[51];
		scanf("%s", str);
		s.add(str);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		char *str = new char[51];
		scanf("%s", str);
		int k = s.find(str);
		printf("%s\n", k < 0 ? "REPEAT" : k == 0 ? "WRONG" : "OK");
	}
	return 0;
}

