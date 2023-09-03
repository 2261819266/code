#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int mod = 998244353;
int n, m, a[N][N], C, F;
int T, id;
long long ansc = 0, ansf = 0;
char ch;

vector< pair<int, int> > lie[N];

//int check(int x, int y) {	//返回最多能往右边走多少步 
//	//待优化  O(n)->O(1) init;
//	int ans = 0;
//	while (a[x][y] == 0 && y <= m) y++, ans++;
//	return ans;
//}

int ans[N][N];

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d", &T, &id);
	while (T--) {
		ansc = ansf = 0;
		scanf("%d%d%d%d", &n, &m, &C, &F); getchar();
		for (int i = 1; i <= n; i++, getchar())
			for (int j = 1; j <= m; j++) {
				ch = getchar();
				a[i][j] = ch - '0';
				ans[i][j] = 0;
			}
	
		for (int i = 1; i <= n; i++) {
			int pre = m;
			for (int j = m; j > 0; j--) {
				if (a[i][j] == 1) {
					pre = j - 1;
					continue;
				}
				ans[i][j] = pre - j + 1;
			}
		}
		
//		for (int i =1 ; i <= n; i++, puts(""))
//			for (int j = 1;j <= m; j++) cout << ans[i][j] << ' ';
		
		for (int j = 1; j <= m; j++) {
			int i = 1;
			int st = 0, ed = 0;
			while (i <= n) {
				while (a[i][j] == 1 && i <= n) i++;
				st = i; while (a[i][j] == 0 && i <= n) i++;
				ed = i - 1;
				if (ed - st + 1 >= 3) lie[j].push_back(make_pair(st, ed));
				if (i == n) break;
			}
		}
		
		for (int j = 1; j <= m - 1; j++) {
			for (int idx = 0; idx < lie[j].size(); idx++) {
				//O(n^2)
				int st = lie[j][idx].first, ed = lie[j][idx].second;
//				cout << st << ' ' << ed << endl;
				for (int a_1 = st; a_1 <= ed; a_1++) {
					for (int a_2 = a_1 + 2; a_2 <= ed; a_2++) {
						// 在连续区间内枚举可能性
//						int A_1 = check(a_1, j), A_2 = check(a_2, j);
						int A_1 = ans[a_1][j], A_2 = ans[a_2][j];
//						cout << '\t' << a_1 << ' ' << A_1 << ' ' << a_2 << ' ' << A_2 << endl;
						if (A_1 >= 2 && A_2 >= 2) {
							ansc = (ansc + (long long) (A_1 - 1) * (A_2 - 1)) % mod;
							ansf = (ansf + (long long) (A_1 - 1) * (A_2 - 1) * (ed - a_2)) % mod;
						}
					}
				}
			}
			while (lie[j].size()) lie[j].pop_back();
		}
		printf("%lld %lld\n", ansc * C, ansf * F);
	}
	return 0;
}
/*

5 0
4 3 1 1
001
010
000
000
4 3 1 1
001
010
000
000
4 3 1 1
001
010
000
000
4 3 1 1
001
010
000
000
4 3 1 1
001
010
000
000

*/
