#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;

struct ACAutomaton {
	struct Node {
		int a[2];
		int fail;
		bool cnt;
		int dep;
		Node(int d = 0) {
			a[0] = a[1] = fail = cnt = 0;
			dep = d;
		}

		int &operator[](int x) {
			return a[x];
		}
	};
	static const int root = 1;
	vector<Node> a;
	ACAutomaton() {
		a.clear();
		a.assign(2, {});
	}

	void insert(const string &s) {
		int p = root;
		for (int i : s) {
			i -= '0';
			if (!a[p][i]) 
				a.push_back({a[p].dep + 1}), a[p][i] = a.size() - 1;
			p = a[p][i];
		}
		a[p].cnt = true;
	}

	void build() {
		int p = root;
		std::queue<int> q;
		for (int i = 0; i < 2; i++) {
			if (a[p][i]) {
				a[a[p][i]].fail = p;
				q.push(a[p][i]);
			}
		}   
		while (!q.empty()) {
			p = q.front();
			q.pop();
			for (int i = 0; i < 2; i++) {
				if (a[p][i]) {
					a[a[p][i]].fail = a[a[p].fail][i], q.push(a[p][i]);
				} else {
					a[p][i] = a[a[p].fail][i];
				}
			}
			for (int j = p; j != root; j = a[j].fail) {
				if (a[j].cnt) {
					a[p].cnt = true;
					break;
				}
			}
		}
	}

	vector<bool> vis, f;

	void dfs(int x) {
		if (a[x].cnt) return;
		vis[x] = true;
		f[x] = true;
		for (int i = 0; i < 2; i++) {
			if (vis[a[x][i]]) {
				printf("TAK");
				exit(0);
			}
			if (!a[a[x][i]].cnt && !f[a[x][i]]) {
				dfs(a[x][i]);
			}
		}
		vis[x] = false;
	}

	void find() {
		vis.assign(a.size(), false);
		f.assign(a.size(), false);
		dfs(root);
		printf("NIE");
	}
} a;

void P2444() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		std::cin >> s;
		a.insert(s);
	}
	a.build();
	a.find();
}

int main() {
	P2444();
	return 0;
}
