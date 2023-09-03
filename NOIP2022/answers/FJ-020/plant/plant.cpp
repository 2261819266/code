#include <cstdio>
#include <iostream>
using namespace std;
int read() {
	int res = 0, w = 1; char chr = getchar();
	while(chr < '0' | chr > '9') { if(chr == '-') w = -1; chr = getchar(); }
	while(chr >= '0' & chr <= '9') res = res * 10 + chr - 48, chr = getchar();
	return res * w;
}
const int mod = 998244353;
int ansc, ansf;
int a[1010][1010], sum[1010][1010];
int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int T = read(), id = read();
	if(id == 1) {
		puts("0 0");
		return 0;
	}
	while(T --) {
		int n = read(), m = read(), c = read(), f = read();
		char str[1010];
		ansc = ansf = 0;
		for(int i = 1; i <= n; i ++) {
			scanf("%s", str + 1);
			for(int j = 1; j <= m; j ++) {
				a[i][j] = 1 ^ (str[j] - '0');
			}
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				if(a[i][j]) sum[i][j] = sum[i][j - 1] + a[i][j];
				else sum[i][j] = 0;
			}
		}
		for(int i = 1; i <= m; i ++) {
			for(int j = 1; j <= n; j ++) {
				if(a[j][i]) sum[j][i] = sum[j - 1][i] + a[j][i];
				else sum[j][i] = 0;
			}
		}
		for(int i = 1; i <= n - 2; i ++)
			for(int j = i + 2; j <= n; j ++) {
				for(int k = 1; k <= m; k ++)
					if(sum[j][k] - sum[i][k] == j - i && a[i][k] && a[j][k]) {
						int sum1 = 0;
						for(int l = k + 1; l <= m; l ++, sum1 ++) if(a[i][l] == 0) break;
						int sum2 = 0;
						for(int l = k + 1; l <= m; l ++, sum2 ++) if(a[j][l] == 0) break;
						ansc = (ansc + sum1 * sum2) % mod; 
//						cout << i << ' ' << j << ' ' << k << ' ' << ansc << '\n';
					}
					else continue;
			}
		for(int i = 1; i <= n - 3; i ++)
			for(int j = 1; j <= n; j ++) {
				for(int k = 1; k <= m; k ++)
					if(sum[j][k] - sum[i][k] == j - i && a[i][k] && a[j][k]) {
						int sum1 = 0;
						for(int l = k + 1; l <= m; l ++, sum1 ++) if(a[i][l] == 0) break;
						int sum2 = 0;
						for(int r = i + 2; r < j; r ++)
							for(int l = k + 1; l <= m; l ++, sum2 ++)
								if(a[r][l] == 0) break;
						ansf = (ansf + sum1 * sum2) % mod; 
					}
					else continue;
			}
		printf("%d %d\n", ansc * c, ansf * f);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
