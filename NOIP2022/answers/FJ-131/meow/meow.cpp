#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, M = 605;
int T, n, m, k, a[N], zt[M], id[M], op[N * 2], x[N * 2], y[N * 2], cnt;
int Op[N * 2], xx[N * 2], yy[N * 2], Cnt;
bool ok;
deque<int> st[M];
vector<int> qq;
void myawa(int n) {
	int ccnt = 0;
			for(int i = 1; i <= m; i ++) {
				if(!zt[a[i]] && !id[a[i]]) {
					if(ccnt < n) {
						op[++ cnt] = 1; x[cnt] = (ccnt + 1) / 2;
						++ ccnt;
						st[(ccnt + 1) / 2].push_back(a[i]);
						zt[a[i]] = (ccnt + 1) / 2; 
						id[a[i]] = st[(ccnt + 1) / 2].size();
					} else {
						++ ccnt;
						if(!st[n].size()) {
							int ide = 0;
							for(int j = 1; j <= n; j ++)
								if(st[j].front() == a[i + 1]) {
									ide = j;
									break;
								}
							if(ide > 0) {
								op[++ cnt] = 1; x[cnt] = ide;
								st[ide].push_back(a[i]);
								zt[a[i]] = ide; id[a[i]] = st[ide].size();
							} else {
								op[++ cnt] = 1; x[cnt] = n;
								st[n].push_back(a[i]);
								zt[a[i]] = n; id[a[i]] = st[n].size();
							}
						} else {
							int ide = 0;
							for(int j = 1; j <= n; j ++)
								if(st[j].back() == a[i + 1]) {
									ide = j;
									break;
								}
							if(ide > 0) {
								op[++ cnt] = 1; x[cnt] = n;
								st[n].push_back(a[i]);
								zt[a[i]] = n; id[a[i]] = st[n].size();
							} else {
								op[++ cnt] = 1; x[cnt] = 1;
								st[1].push_back(a[i]);
								zt[a[i]] = 1; id[a[i]] = st[1].size();
							}
						}
					}
				} else {
					if(st[zt[a[i]]].back() == a[i]) {
						op[++ cnt] = 1; x[cnt] = zt[a[i]];
						st[zt[a[i]]].pop_back();
						-- ccnt;
						zt[a[i]] = id[a[i]] = 0;
					} else {
						int ppg = 0;
						for(int j = 1; j <= n; j ++)
							if(!st[j].size()) {
								ppg = j;
								break;
							}
						if(!ppg) ppg = n;
						-- ccnt;
						op[++ cnt] = 1; x[cnt] = ppg;
						op[++ cnt] = 2; x[cnt] = ppg; y[cnt] = zt[a[i]];
						st[zt[a[i]]].pop_front();
						zt[a[i]] = id[a[i]] = 0;
					}
				}
			}
			cout << cnt << '\n';
			for(int i = 1; i <= cnt; i ++)
				if(op[i] == 1) cout << op[i] << ' ' << x[i] << '\n';
				else cout << op[i] << ' ' << x[i] << ' ' << y[i] << '\n';
}
void dfs(int X, int *op, int *x, int *y, int cnt) {
	//cout << X << ' ' << cnt << '\n';
	bool okok = true;
	while(okok) {
		okok = false;
		for(int i = 1; i <= n; i ++)
			for(int j = i + 1; j <= n; j ++)
				if(st[i].size() && st[j].size() && st[i].front() == st[j].front()) {
					op[++ cnt] = 2; x[cnt] = i; y[cnt] = j;
					st[i].pop_front(); st[j].pop_front();
					okok = true; break;
				}
	}
	deque<int> St[4];
	for(int i = 1; i <= n; i ++) St[i] = st[i];
	if(ok) return;
	if(X == m + 1) {
		ok = true;
		for(int i = 1; i <= n; i ++)
			if(st[i].size()) ok = false;
		if(ok) {
			Cnt = cnt;
			for(int i = 1; i <= cnt; i ++)
				Op[i] = op[i], xx[i] = x[i], yy[i] = y[i];
		}
		return;
	}
	for(int i = 1; i <= n; i ++) {
		if(st[i].size() && st[i].back() == a[X]) st[i].pop_back();
		else st[i].push_back(a[X]);
		op[cnt + 1] = 1; x[cnt + 1] = i;
		dfs(X + 1, op, x, y, cnt + 1);
		st[i] = St[i];
	}
}
void work() {
	scanf("%d%d%d", &n, &m, &k);
	memset(zt, 0, sizeof(zt));
	memset(id, 0, sizeof(id));
	for(int i = 1; i <= m; i ++) scanf("%d", &a[i]);
	qq.clear(); int ccnt = 0; ok = false; cnt = Cnt = 0;
	for(int i = 1; i <= n; i ++) st[i].clear();
	for(int i = 1; i < n; i ++) qq.push_back(i);
	if(k == 2 * n - 2) { //Easy
		for(int i = 1; i <= m; i ++)
			if(!zt[a[i]] && !id[a[i]]) {
				int awa = qq.back();
				st[awa].push_back(a[i]);
				op[++ cnt] = 1; x[cnt] = awa;
				zt[a[i]] = awa; id[a[i]] = st[awa].size();
				if(st[awa].size() == 2) qq.pop_back();
			} else {
				if(id[a[i]] == 1) {
					op[++ cnt] = 1; x[cnt] = n;
					op[++ cnt] = 2; x[cnt] = zt[a[i]]; y[cnt] = n;
					qq.push_back(zt[a[i]]);
					zt[a[i]] = id[a[i]] = 0;
					st[zt[a[i]]].pop_front();
				} else {
					op[++ cnt] = 1; x[cnt] = zt[a[i]];
					st[zt[a[i]]].pop_back();
					qq.push_back(zt[a[i]]);
					zt[a[i]] = id[a[i]] = 0;
				}
			}
		cout << cnt << '\n';
		for(int i = 1; i <= cnt; i ++)
			if(op[i] == 1) cout << op[i] << ' ' << x[i] << '\n';
			else cout << op[i] << ' ' << x[i] << ' ' << y[i] << '\n';
	} else { // Why is it so hard?
		if(n == 2) { // Not very hard.
			for(int i = 1; i <= m; i ++) {
				if(!zt[a[i]] && !id[a[i]]) {
					if(ccnt < 2) {
						op[++ cnt] = 1; x[cnt] = 1;
						++ ccnt;
						st[1].push_back(a[i]);
						zt[a[i]] = 1; id[a[i]] = st[1].size();
					} else {
						++ ccnt;
						if(!st[2].size()) {
							if(a[i + 1] == st[1].front()) {
								op[++ cnt] = 1; x[cnt] = 1;
								st[1].push_back(a[i]);
								zt[a[i]] = 1; id[a[i]] = st[1].size();
							} else {
								op[++ cnt] = 1; x[cnt] = 2;
								st[2].push_back(a[i]);
								zt[a[i]] = 2; id[a[i]] = st[2].size();
							}
						} else {
							if(a[i + 1] == st[1].back()) {
								op[++ cnt] = 1; x[cnt] = 2;
								st[2].push_back(a[i]);
								zt[a[i]] = 2; id[a[i]] = st[2].size();
							} else {
								op[++ cnt] = 1; x[cnt] = 1;
								st[1].push_back(a[i]);
								zt[a[i]] = 1; id[a[i]] = st[1].size();
							}
						}
					}
				} else {
					if(st[zt[a[i]]].back() == a[i]) {
						op[++ cnt] = 1; x[cnt] = zt[a[i]];
						st[zt[a[i]]].pop_back();
						-- ccnt;
						zt[a[i]] = id[a[i]] = 0;
					} else {
						int ppg = 0;
						if(!st[1].size()) ppg = 1;
						else ppg = 2;
						-- ccnt;
						op[++ cnt] = 1; x[cnt] = ppg;
						op[++ cnt] = 2; x[cnt] = ppg; y[cnt] = zt[a[i]];
						st[zt[a[i]]].pop_front();
						zt[a[i]] = id[a[i]] = 0;
					}
				}
			}
			cout << cnt << '\n';
			for(int i = 1; i <= cnt; i ++)
				if(op[i] == 1) cout << op[i] << ' ' << x[i] << '\n';
				else cout << op[i] << ' ' << x[i] << ' ' << y[i] << '\n';
		} else if(n == 3) {
			if(m <= 14) { // Not very hard,too.
				dfs(1, op, x, y, 0);
				cout << Cnt << '\n';
				for(int i = 1; i <= Cnt; i ++)
					if(Op[i] == 1) cout << Op[i] << ' ' << xx[i] << '\n';
					else cout << Op[i] << ' ' << xx[i] << ' ' << yy[i] << '\n';
			} else { // Very hard.(Life is hard.)
				myawa(n);
			}
		} else {
			myawa(n);
		}
	}
}
int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	while(T --) work();
	return 0;
}
