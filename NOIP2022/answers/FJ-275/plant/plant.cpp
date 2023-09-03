#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1010;
char s[N][N];
bool a[N][N];
int ne[N][N], upp[N][N];
int n, m, c, f, t, id;

typedef long long ll;
int main(){
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d",&t, &id);
	while(t --){
		scanf("%d%d%d%d", &n, &m, &c, &f);
		
		for(int i = 1; i <= n; ++ i){
			scanf("%s", s[i] + 1);
		}
		
		memset(ne, 0, sizeof ne);
		memset(upp, 0, sizeof upp);
		for(int i = 1; i <= n; ++ i){
			for(int j = 1; j <= m; ++ j){
				if(s[i][j] =='0'){
					a[i][j] = 1;
					upp[i][j] = 1;
					upp[i][j] += upp[i - 1][j];
				}
				else a[i][j] = 0;
			}
		}
		for(int i = 1; i <= n; ++ i){
			for(int j = m; j >= 1; -- j){
				if(a[i][j] == 1){
					ne[i][j] = 1;
					ne[i][j] += ne[i][j + 1];
				}
			}
		}
		//ne 该点后接的空地数量
		// up 该点上接的空地数量 
		/*for(int i = 1; i <= n; ++ i){
			for(int j = 1; j <= m; ++ j){
				cout << ne[i][j] << " "; 
			}
			cout << endl; 
		}
		for(int i = 1; i <= n; ++ i){
			for(int j = 1; j <= m; ++ j){
				cout << upp[i][j] << " "; 
			}
			cout << endl; 
		}*/
		if(c == 0 && f == 0){
			cout << 0 << " " << 0 << endl;
			continue;
		}
		ll ansc = 0, ansf = 0;
		for(int i = 3; i <= n; ++ i){
			for(int j = 1; j <= m - 1; ++ j){
				if(upp[i][j] < 3) continue;
				if(ne[i][j] <= 1) continue;
				
				for(int k = i - upp[i][j] + 1; k < i - 1; ++ k){
					if(ne[k][j] > 1)
					{
						ansc = (ansc + (ne[i][j] - 1) * (ne[k][j] - 1) % mod) % mod;
						ansc %= mod;
					}
				}
			}
		} // 计算C 
		ansc = ansc * c % mod;
		if(f == 0){
			cout << ansc << " " << 0 << endl;
		}
		for(int i = 4; i <= n; ++ i){
			for(int j = 1; j < m; ++ j){
				if(upp[i][j] < 4) continue;
				for(int k = i - upp[i][j] + 1; k < i - 2; ++ k){
					if(ne[k][j] <= 1) continue;
					for(int l = k + 2; l < i; ++ l){
						if(ne[l][j] <= 1) continue;
						ansf = (ansf + (ne[k][j] - 1) * (ne[l][j] - 1) % mod) % mod;
						ansf %= mod;
					}
				}
			}
		}

		
		ansf = ansf * f % mod;
		printf("%lld %lld\n", ansc, ansf); 
	}
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


