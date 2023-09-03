#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <iostream>

using std::vector;
using std::string;
using std::queue;
using std::cin;
using std::cout;

struct ACAutomata {
    struct Node {
        vector<int> a;
        size_t cnt;
        int fail;
        Node () {
            a.clear();
            a.assign(26, -1);
            cnt = 0;
            fail = -1;
        }
        int &operator[](int x) {
            return a[x];
        }
    } ;
    vector<Node> a;
    static const int root = 0;
    void clear() {
        a.clear();
        a.push_back({});
    }

    ACAutomata() {
		clear();
    }

    int add() {
        a.push_back({});
        return a.size() - 1;
    }

    void insert(const string &s) {
        int p = root;
        for (char i : s) {
            i -= 'a';
            if (!~a[p][i]) a[p][i] = add();
            p = a[p][i];
        }
        a[p].cnt++;
    }

    void build() {
        queue<int> q;
        int p = root;
        a[0].fail = 0;
        for (int i = 0; i < 26; i++) {
            if (~a[p][i]) {
                a[a[p][i]].fail = p;
                q.push(a[p][i]);
            } else a[p][i] = 0;
        }
        while (!q.empty()) {
            p = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (~a[p][i]) {
                    a[a[p][i]].fail = a[a[p].fail][i];
                    q.push(a[p][i]);
                } else {
                    a[p][i] = a[a[p].fail][i];
                }
            }
        }
    }

    size_t query(const string &s) const {
        vector<bool> vis(a.size(), false);
        size_t ans = 0;
        int p = root;
        for (char i : s) {
            i -= 'a';
            p = a[p].a[i];
            for (int j = p; j > root && !vis[j]; j = a[j].fail) {
                ans += a[j].cnt;
                vis[j] = true;
            }
        }
        return ans;
    }
} a;

size_t solve(const string t, const vector<string> &s) {
    a.clear();
    for (string i : s) { 
        a.insert(i);
    }
    a.build();
    return a.query(t);
}

void P3808() {
	vector<string> s;
	string t;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> t;
		s.push_back(t);
	}
	cin >> t;
	cout << solve(t, s);
}

int main() {
	P3808();
	return 0;
}
