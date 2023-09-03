#include <cstdio>
#include <algorithm>
#include <cassert>
#include <deque>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

const int N = 310;
const int K = 1010;
const int M = 2e6 + 10;
int n, m, k, a[M];
struct Operation { int type, a, b, time; };
vector<int> b[K];
deque<int> st[K];
vector<Operation> ans;

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	ans.clear();
	for (int i = 1; i <= k; i ++) b[i].clear();
	for (int i = 1; i <= n; i ++) while (!st[i].empty()) st[i].pop_back();
	for (int i = 1; i <= m; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i ++) b[(a[i] - 1) / 2 + 1].push_back(i);
	if (k == 2 * n - 2) {
		for (int i = 1; i <= n; i ++) {
			for (int x : b[i]) {
				if (st[i].size() <= 1) {
					if (!st[i].empty() && st[i].front() == a[x]) {
						ans.push_back({ 1, i, 0, x });
						st[i].pop_front();
					} else {
						ans.push_back({ 1, i, 0, x });
						st[i].push_front(a[x]);
					}
				} else {
					if (st[i].front() == a[x]) {
						ans.push_back({ 1, i, 0, x });
						st[i].pop_front();
					} else {
						ans.push_back({ 1, n, 0, x });
						st[n].push_front(a[x]);
						st[i].pop_back();
					}
				}
			}
		}
		
	} else if (n == 2) {
		for (int i = 1; i <= k; i ++) {
			for (int j = i + 1; j <= k; j ++) {
				vector<int> tmp;
				bool flag = true;
				for (int z = 1; z <= m; z ++) if (a[z] == i || a[z] == j) tmp.push_back(z);
				for (int z = 0; z < tmp.size(); z ++) if (a[tmp[z]] != a[tmp[tmp.size() - z - 1]]) { flag = false; break; }
				if (flag) {
					printf("%d\n", m);
					for (int z = 1; z <= m; z ++) if (a[z] == i || a[z] == j) {
						printf("1 1\n");
					} else {
						printf("1 2\n");
					}
					return;
				}
			}
		} 
	} else {
//		for (int i = 1; i < n; i ++) {
//			bool flag = true;
//			for (int j = 0; j < (int) b[i].size(); j ++) if (a[b[i][j]] != a[b[i][b[i].size() - j - 1]]) { flag = false; break; }
//
//			for (int x : b[i]) ans.push_back({ 1, i, 0, x });
//			b[i].clear();
//		}
		for (int i = 1; i <= n; i ++) {
			for (int x : b[i]) {
				if (st[i].size() <= 1) {
					if (!st[i].empty() && st[i].front() == a[x]) {
						ans.push_back({ 1, i, 0, x });
						st[i].pop_front();
					} else {
						ans.push_back({ 1, i, 0, x });
						st[i].push_front(a[x]);
					}
				} else {
					if (st[i].front() == a[x]) {
						ans.push_back({ 1, i, 0, x });
						st[i].pop_front();
					} else {
						ans.push_back({ 1, n, 0, x });
						st[n].push_front(a[x]);
						st[i].pop_back();
					}
				}
			}
		}
	}
	
	while (!st[n].empty()) {
		int tp = st[n].back(); st[n].pop_back();
		ans.push_back({ 2, (tp - 1) / 2 + 1, n, ++ m });
	}
	printf("%lld\n", ans.size());
	sort(ans.begin(), ans.end(), [&](auto op1, auto op2) { return op1.time < op2.time; });
	for (auto op : ans) if (op.type == 1) printf("1 %d\n", op.a); else printf("2 %d %d\n", op.a, op.b);
	
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T --) solve();
	return 0;
}

/*




*/
