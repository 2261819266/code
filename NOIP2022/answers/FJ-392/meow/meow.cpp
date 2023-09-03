#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);

using std::vector;
using std::min;
using std::queue;

vector<queue<int> >qs;
vector<int> a;

void solve() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	qs.assign(n, {});
	while (n--) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	for (int x : a) {
		for (auto q : qs) {
			if (q.size() && q.back() == x) {
				q.pop();
				printf("%d\n");
			} 
		}
	}
}

void meow() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}

int main() {
	fo(meow)
	meow();
	return 0;
}

/*
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <iostream>

using std::vector;
using std::string;
using std::queue;
using std::cin;

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);

struct ACAutomaton {
	struct Node {
		vector<int> a;
		int cnt, fail;
		Node() {
			a.assign(26, 0);
			cnt = fail = 0;
		}
	
		int &operator[](int x) {
			return a[x];
		}
	};
	
	vector<Node> a;
	
	ACAutomaton() {
		a.assign(1, {});
	}
	
	void insert(const string &s) {
		int p = 0;
		for (int i : s) {
			i -= 'a';
			if (!a[p][i]) {
				a[p][i] = a.size();
				a.push_back({});
			}
			p = a[p][i];
		} 
		a[p].cnt++;
	}
	
	void build() {
		queue<int> q;
		for (int i : a[0].a) {
			if (i) {
				q.push(i);
				a[i].fail = 0;
			}
		}
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (int &i : a[p].a) {
				if (i) {
					a[i].fail = a[a[p].fail][i];
					q.push(i);
				} else {
					i = a[a[p].fail][i];
				}
			}
		}
	}
	
	int query(const string &s) {
		int p = 0, ans = 0;
		for (int i : s) {
			i -= 'a';
			p = a[p][i];
			for (int j = p; j && ~a[j].cnt; j--) {
				ans += a[j].cnt;
				a[j].cnt = -1;
			}
		}
		return ans;
	}
} a;

void solve() {
	string s;
	int n;
	scanf("%d", &n);
	while (n--) {
		cin >> s;
		a.insert(s);
	}
	a.build();
	cin >> s;
	printf("%d", a.query(s));
}

int main() {
	fo(test)
	solve();
	return 0;
}

*/

