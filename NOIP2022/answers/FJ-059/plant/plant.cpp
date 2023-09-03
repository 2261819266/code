#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 1010, mod = 998244353;

typedef long long ll;

int t, id;
int n, m, c, f;

ll res1, res2;

//int num[N][N];
char g[N][N];
//string C[N];

ll checkC(int col, int row1, int row2) {
	for (int i = row1; i <= row2; i++)
		if (g[i][col] == '1') return 0;
	
	ll k1 = -1, k2 = -1;
	//k1 = num[row1][col];
	//k2 = num[row2][col];
	for (int i = col; i <= m; i++) {
		if (g[row1][i] == '0') k1 ++;
		else break;
	}
	if (!k1) return 0;
	
	for (int i = col; i <= m; i++) {
		if (g[row2][i] == '0') k2 ++;
		else break;
	}
	
	return k1 * k2 % mod;
}

ll checkF(int col, int row1, int row2) {
	for (int i = row1; i <= row2; i++) 
		if (g[i][col] == '1') return 0;
	
	ll k1 = -1, k2 = -1, k3 = -1;
	for (int i = col; i <= m; i++) {
		if (g[row1][i] == '0') k1 ++;
		else break;
	}
	
	//k1 = num[row1][col];
	//k2 = num[row2][col];
	
	if (!k1) return 0;
	
	for (int i = col; i <= m; i++) {
		if (g[row2][i] == '0') k2 ++;
		else break;
	}
	if (!k2) return 0;
	
	for (int i = row2; i <= n; i++) {
		if (g[i][col] == '0')  k3 ++;
		else break;
	}
	return k1 * k2 % mod * k3 % mod;
}

int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d", &t, &id);
	while (t--) {
		scanf("%d%d%d%d", &n, &m, &c, &f);
		
		res1 = 0, res2 = 0;
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++)
				cin >> g[i][j];
		
		/*for (int i = 1; i <= n; i++) {
			for (int j = m; j >= 1; j--) {
				if (g[i][j] == '0') num[i][j] = num[i][j + 1] + 1;
				else num[i][j] = -1;
			}
		}*/
		
		if (c == 0 && f == 0) {
			cout << 0 << endl;
			continue;
		}
		
		if (id == 4) {
			bool st[N][N] = {0};
			for (int i = 1; i <= n; i++) st[i][i] = true;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (g[j][1] == '0') st[i][j] = st[i][j - 1];
					else st[i][j] = false;
				}
			}
			
			for (int row1 = 1; row1 <= n - 2; row1 ++) {
				for (int row2 = row1 + 2; row2 <= n; row2 ++) {
					if (g[row1][2] == '0' && g[row2][2] == '0' && st[row1][row2]) {
						res1 ++;
						int k = row2 + 1;
						while (g[k][1] == '0') {
							res2 ++;
							k ++;
						}
					}
				}
			}
			
			printf("%lld %lld\n", res1, res2);
			
			continue;
		}
		
		if (id == 5) {
			for (int col = 1; col <= m; col++) {
				if (col % 3 == 0) continue;
				for (int row1 = 1; row1 <= n - 2; row1++) {
					for (int row2 = row1 + 2; row2 <= n; row2++) {
						//printf("%d %d %d == %lld\n", col, row1, row2, checkC(col, row1, row2));
						res1 = (res1 + checkC(col, row1, row2) * c) % mod;
						res2 = (res2 + checkF(col, row1, row2) * c) % mod; 
					}
				}
			}

			printf("%lld %lld\n", res1, res2);
			
			continue;
		}
		
		if (id == 6) {
			for (int col = 1; col <= m; col++) {
				for (int row1 = 1; row1 <= n - 2; row1++) {
					if (row1 % 4 == 0) continue;
					for (int row2 = row1 + 2; row2 <= n; row2++) {
						if (row2 % 4 == 0) continue;
						//printf("%d %d %d == %lld\n", col, row1, row2, checkC(col, row1, row2));
						res1 = (res1 + checkC(col, row1, row2) * c) % mod;
						res2 = (res2 + checkF(col, row1, row2) * c) % mod; 
					}
				}
			}
			
			printf("%lld %lld\n", res1, res2);
			
			continue;
		}
		
		/*for (int i = 1; i <= m; i++) C[i] = "";
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++)
				C[j] += g[i][j];*/
		
		for (int col = 1; col <= m; col++) {
			for (int row1 = 1; row1 <= n - 2; row1++) {
				for (int row2 = row1 + 2; row2 <= n; row2++) {
					//printf("%d %d %d == %lld\n", col, row1, row2, checkC(col, row1, row2));
					res1 = (res1 + checkC(col, row1, row2) * c) % mod;
					res2 = (res2 + checkF(col, row1, row2) * c) % mod; 
				}
			}
		}
		printf("%lld %lld\n", res1, res2);
	}
	return 0;
}
