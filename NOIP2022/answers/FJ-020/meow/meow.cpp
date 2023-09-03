#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int read() {
	int res = 0, w = 1; char chr = getchar();
	while(chr < '0' | chr > '9') { if(chr == '-') w = -1; chr = getchar(); }
	while(chr >= '0' & chr <= '9') res = res * 10 + chr - 48, chr = getchar();
	return res * w;
}
vector<int > s[310];
struct answer { int num, a, b; } ans[2000010];
int flr[310], top[310], a[2000010], cnt;//flr为底，top为顶 
int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int T = read();
	while(T --) {
		cnt = 0;
		int n = read(), m = read(), useless = read();
		for(int i = 1; i <= n; i ++) s[i].clear(), top[i] = 0, flr[i] = 1;
		for(int i = 1; i <= m; i ++) {
			a[i] = read();
		}
		//令第n个栈始终保持为空的状态
		for(int i = 1; i <= m; i ++) {
//			cout << i << ' ';
			int flg = -1, tmp = -1;
			for(int j = 1; j < n; j ++) {
//				cout << flr[j] << ' ' << top[j] << '\n';
				if(flr[j] - 1 == top[j]) {
					s[j].push_back(a[i]), top[j] ++, ans[++ cnt] = {1, j, 0}, flg = 1;
//					cout << 1;
					break;
				} else if(s[j][flr[j] - 1] == a[i]) {
					flr[j] ++, ans[++ cnt] = {1, n, 0}, ans[++ cnt] = {2, j, n}, flg = 1;
					break;
				} else if(s[j][top[j] - 1] == a[i]) {
					top[j] --, ans[++ cnt] = {1, j, 0}, flg = 1;
					break;
				} else {
//					cout << top[j] - flr[j] + 1 << ' ';
					if(tmp > top[j] - flr[j] + 1) {
						ans[++ cnt] = {1, j, 0};
						s[j].push_back(a[i]);
						top[j] ++, flg = 1;
						break;
					} tmp = top[j] - flr[j] + 1;
				}
			}
//			cout << flg << ' ';
			if(flg == -1) s[1].push_back(a[i]), ans[++ cnt] = {1, 1, 0}, top[1] ++;
		}
		for(int i = 1; i < n - 1; i ++) {
			for(int j = 2; j < n; j ++) {
				while(s[i][flr[i] - 1] == s[j][flr[j] - 1] && top[i] - flr[i] + 1 && top[j] - flr[j] + 1)
					flr[i] ++, flr[j] ++;
			}
		}
		printf("%d\n", cnt);
		for(int i = 1; i <= cnt; i ++) {
			if(ans[i].num == 1) printf("%d %d\n", ans[i].num, ans[i].a);
			else printf("%d %d %d\n", ans[i].num, ans[i].a, ans[i].b);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
2 4 2
1 2 1 2
*/
