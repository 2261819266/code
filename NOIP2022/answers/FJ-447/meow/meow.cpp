#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
#define fo(x) freopen(#x".in", "r", stdin); \
	freopen(#x".out", "w", stdout);
int stk[600][600];
const int maxm = 1e6 + 10;
int a[maxm];
set<pair<int, int> > s;
queue<pair<int, int> > q;
struct Ans {
	int op;
	int x, y = -1;
	Ans(int op_ = 0, int x_ = 0, int y_ = 0)  {
		op = op_, x = x_, y = y_;
	}
} ans[maxm];
void solve1() {
	int n, m, k;
	int opt = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n - 1; ++i) {
		q.push(make_pair(i, 1));
		q.push(make_pair(i, 2));
	}
	memset(stk, -1, sizeof(stk));
	for (int i = 1; i <= m; ++i) {
		auto it = s.lower_bound(make_pair(a[i], 0));
		if (it == s.end()) {
			int u, v;
			while (1) {
				u = q.front().first, v = q.front().second;
				q.pop();
				if (v == 1 || stk[u][1] != -1) {
					break;
				}
				q.push(make_pair(u, v));
			}
			s.insert(make_pair(a[i], u));
			stk[u][v] = a[i];
//			printf("1 %d\n", u);
			ans[++opt] = {1, u};
		} else {
			if (stk[it->second][2] != -1) {
				if (stk[it->second][1] == a[i]) {
					ans[++opt] = {1, n};
//					printf("1 %d\n", n);
//					printf("2 %d %d\n", it->second, n);
					ans[++opt] = {2, it->second, n};
					stk[it->second][1] = stk[it->second][2];
					stk[it->second][2] = -1;
					q.push(make_pair(it->second, 2));
				} else if (stk[it->second][2] == a[i]) {
//					printf("1 %d\n", it->second);
					ans[++opt] = {1, it->second};
					stk[it->second][2] = -1;
					q.push(make_pair(it->second, 2));
				} else {
					int u, v;
					while (1) {
						u = q.front().first, v = q.front().second;
						q.pop();
						if (v == 1 || stk[u][1] != -1) {
							break;
						}
						q.push(make_pair(u, v));
					}
					s.insert(make_pair(a[i], u));
					stk[u][v] = a[i];
					//			printf("1 %d\n", u);
					ans[++opt] = {1, u};
					continue;
				}
			} else {
				if (stk[it->second][1] == a[i]) {
					stk[it->second][1] = -1;
					//				printf("1 %d\n", it->second);
					ans[++opt] = {1, it->second};
					q.push(make_pair(it->second, 1));
				} else {
					int u, v;
					while (1) {
						u = q.front().first, v = q.front().second;
						q.pop();
						if (v == 1 || stk[u][1] != -1) {
							break;
						}
						q.push(make_pair(u, v));
					}
					s.insert(make_pair(a[i], u));
					stk[u][v] = a[i];
					//			printf("1 %d\n", u);
					ans[++opt] = {1, u};
					continue;
				}
			}
			s.erase(it);
		}
	}

	printf("%d\n", opt);
	for (int i = 1; i <= opt; ++i) {
		if (ans[i].op == 1) {
			printf("1 %d\n", ans[i].x);
		} else {
			printf("2 %d %d\n", ans[i].x, ans[i].y);
		}
	}
}
void solve2() {
	int n, m, k;
	int opt = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n - 1; ++i) {
		q.push(make_pair(i, 1));
		q.push(make_pair(i, 2));
		q.push(make_pair(i, 3));
	}
	memset(stk, -1, sizeof(stk));
	for (int i = 1; i <= m; ++i) {
		auto it = s.lower_bound(make_pair(a[i], 0));
		if (it == s.end()) {
			int u, v;
			while (1) {
				u = q.front().first, v = q.front().second;
				q.pop();
				if (v == 1 || stk[u][1] != -1) {
					break;
				} else if (v == 2 || stk[u][2] != -1) {
					break;
				}
				q.push(make_pair(u, v));
			}
			s.insert(make_pair(a[i], u));
			stk[u][v] = a[i];
//			printf("1 %d\n", u);
			ans[++opt] = {1, u};
		} else {
//			if (it->first==1) {
//
//			}
			if (stk[it->second][3] != -1) {
				if (stk[it->second][1] == a[i]) {
					ans[++opt] = {1, n};
//					printf("1 %d\n", n);
//					printf("2 %d %d\n", it->second, n);
					ans[++opt] = {2, it->second, n};
					stk[it->second][1] = stk[it->second][2];
					stk[it->second][2] = stk[it->second][3];
					stk[it->second][3] = -1;
					q.push(make_pair(it->second, 2));
				} else if (stk[it->second][3] == a[i]) {
//					printf("1 %d\n", it->second);
					ans[++opt] = {1, it->second};
					stk[it->second][2] = -1;
					q.push(make_pair(it->second, 2));
				} else {
					int u, v;
					while (1) {
						u = q.front().first, v = q.front().second;
						q.pop();
						if (v == 1 || stk[u][1] != -1) {
							break;
						} else if (v == 2 || stk[u][2] != -1) {
							break;
						}
						q.push(make_pair(u, v));
					}
					s.insert(make_pair(a[i], u));
					stk[u][v] = a[i];
					//			printf("1 %d\n", u);
					ans[++opt] = {1, u};
					continue;
				}
			} else if (stk[it->second][2] != -1) {
				if (stk[it->second][1] == a[i]) {
					ans[++opt] = {1, n};
//					printf("1 %d\n", n);
//					printf("2 %d %d\n", it->second, n);
					ans[++opt] = {2, it->second, n};
					stk[it->second][1] = stk[it->second][2];
					stk[it->second][2] = -1;
					q.push(make_pair(it->second, 2));
				} else if (stk[it->second][2] == a[i]) {
//					printf("1 %d\n", it->second);
					ans[++opt] = {1, it->second};
					stk[it->second][2] = -1;
					q.push(make_pair(it->second, 2));
				} else {
					int u, v;
					while (1) {
						u = q.front().first, v = q.front().second;
						q.pop();
						if (v == 1 || stk[u][1] != -1) {
							break;
						} else if (v == 2 || stk[u][2] != -1) {
							break;
						}
						q.push(make_pair(u, v));
					}
					s.insert(make_pair(a[i], u));
					stk[u][v] = a[i];
					//			printf("1 %d\n", u);
					ans[++opt] = {1, u};
					continue;
				}
			} else {
				if (stk[it->second][1] == a[i]) {
					stk[it->second][1] = -1;
					//				printf("1 %d\n", it->second);
					ans[++opt] = {1, it->second};
					q.push(make_pair(it->second, 1));
					
				} else {
					int u, v;
					while (1) {
						u = q.front().first, v = q.front().second;
						q.pop();
						if (v == 1 || stk[u][1] != -1) {
							break;
						} else if (v == 2 || stk[u][2] != -1) {
							break;
						}
						q.push(make_pair(u, v));
					}
					s.insert(make_pair(a[i], u));
					stk[u][v] = a[i];
					//			printf("1 %d\n", u);
					ans[++opt] = {1, u};
					continue;
				}
			}
			s.erase(it);
		}

//		auto it1 = s.lower_bound(make_pair(0, 0));
//		auto et = s.upper_bound(make_pair(it1->first, it1->second));
//		while (!s.empty()) {
//			if (it1 == s.end()) break;
//			if (it1 != s.end() && et != s.end() && it1 != et && it1->first == et->first) {
////			printf("2 %d %d\n", it->second, et->second);
//				ans[++opt] = {2, it1->second, et->second};
//				q.push(make_pair(it1->first, ))
//				s.erase(it1);
//				s.erase(et);
//			}
//			it1 = s.upper_bound(make_pair(et->first, et->second));
//			et = s.upper_bound(make_pair(it1->first, it1->second));
//		}
	}

	while (!s.empty()) {
		auto it = s.lower_bound(make_pair(0, 0));
		auto et = s.upper_bound(make_pair(it->first, it->second));
		if (et == s.end()) continue;
//			printf("2 %d %d\n", it->second, et->second);
		ans[++opt] = {2, it->second, et->second};
		s.erase(it);
		s.erase(et);
	}
	printf("%d\n", opt);
	for (int i = 1; i <= opt; ++i) {
		if (ans[i].op == 1) {
			printf("1 %d\n", ans[i].x);
		} else {
			printf("2 %d %d\n", ans[i].x, ans[i].y);
		}
	}
}
int main() {
	fo(meow);
	int t;
	scanf("%d", &t);
	if (t % 10 == 1) {
		while (t--) {
			while(!q.empty()) q.pop();
			solve1();
		}
	} else {
		while (t--) {
			while(!q.empty()) q.pop();
			solve2();
		}
	}
	return 0;
}
