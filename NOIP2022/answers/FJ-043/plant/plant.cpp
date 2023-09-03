#include <bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 998244353;

int T, id, n, m, C, F, rgt[N][N], dn[N][N], now[N];
int ans[3];
char c[N][N];

inline int add(int x, int y){
	return x + y >= MOD ? x + y - MOD : x + y;
}

void solve(){
	scanf("%d%d%d%d", &n, &m, &C, &F);
	for(int i = 1; i <= n; i++)
		scanf("%s", c[i] + 1);
	memset(rgt, 0, sizeof(rgt));
	memset(dn, 0, sizeof(dn)); 
	for(int i = 1, las; i <= n; i++){
		rgt[i][m] = m + 1, las = m + 1;
		if(c[i][m] == '1') las = m;
		for(int j = m - 1; j >= 1; j--){
			rgt[i][j] = las;
			if(c[i][j] == '1') las = j;
		}
	}
	for(int i = 1, las; i <= m; i++){
		dn[n][i] = n + 1, las = n + 1;
		if(c[n][i] == '1') las = n;
		for(int j = n - 1; j >= 1; j--){
			dn[j][i] = las;
			if(c[j][i] == '1') las = j;
		}
	}
	
	ans[1] = ans[2] = 0;
	for(int i = 1, ss, sum; i <= m; i++){
		for(int j = 1; j <= n; j++)
			now[j] = rgt[j][i] - i - 1;
		ss = sum = 0;
		for(int j = 1; j <= n; j++){
			if(c[j][i] == '1'){
				ss = sum = 0;
				continue;
			}
			ss++;
			if(ss >= 3){
				sum = add(sum, now[j - 2]);
				ans[1] = add(ans[1], 1ll * sum * now[j] % MOD);
				ans[2] = add(ans[2], 1ll * sum * now[j] % MOD * (dn[j][i] - j - 1) % MOD);
			}
		}
	}
	
	printf("%lld %lld\n", 1ll * ans[1] * C % MOD, 1ll * ans[2] * F % MOD);
}

int main(){
	
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	scanf("%d%d", &T, &id);
	while(T--) solve(); 
	
	return 0;
}
