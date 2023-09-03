#include<bits/stdc++.h>
#define Maxn 1007
#define Mod 998244353
using namespace std;
int D[Maxn][Maxn], R[Maxn][Maxn], a[Maxn][Maxn], U[Maxn][Maxn], sum[Maxn][Maxn], ansc, ansf, n, m, C, F, T, id;
void solve(){
	cin >> n >> m >> C >> F; ansc = ansf = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			char x; cin >> x; a[i][j] = (int) x - '0'; a[i][j] ^= 1;
			U[i][j] = D[i][j] = R[i][j] = sum[i][j] = 0;
		}
	} 
	for(int i = 1; i <= n; i ++){
		for(int j = m; j; j --){
			if(! a[i][j]) {R[i][j] = -1; continue;}
			if(j == m) R[i][j] = 0;
			else R[i][j] = R[i][j + 1] + 1;
		}
	}
	for(int j = 1; j <= m; j ++){
		for(int i = n; i; i --){
			if(! a[i][j]) D[i][j] = -1;
			else if(i == n) D[i][j] = 0;
			else D[i][j] = D[i + 1][j] + 1;
			sum[i][j] = (R[i][j] + sum[i + 1][j]);		
		}
	}
	for(int j = 1; j <= m; j ++){
		for(int i = 1; i <= n; i ++){
			if(! a[i][j]) U[i][j] = -1;
			else if(i == 1) U[i][j] = 0;
			else U[i][j] = U[i - 1][j] + 1;			
		}
	}
//	for(int i = 1; i <= n; i ++){
//		for(int j = 1; j <= m; j ++) cout << U[i][j] << " ";
//		puts("");
//	}
	for(int j = 1; j <= m; j ++){
		for(int i = 1; i <= n; i ++){
			if(! a[i][j] or D[i][j] < 2) continue;
			ansc = (ansc + 1ll * R[i][j] * (sum[i + 2][j] - sum[i + D[i][j] + 1][j]) % Mod) % Mod;
		}
	}
	for(int j = 1; j <= m; j ++){
		for(int i = 1; i <= n; i ++){
			if(! a[i][j] or U[i][j] < 2 or D[i][j] < 1) continue;
			ansf = (ansf + 1ll * R[i][j] * (sum[i - U[i][j]][j] - sum[i][j]) % Mod * D[i][j] % Mod) % Mod;
		}
	}	
	cout << ansc * C << " " << ansf * F << "\n";
}
int main(){
	freopen("plant.in", "r", stdin); freopen("plant.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T >> id; while(T --) solve();	
} 
