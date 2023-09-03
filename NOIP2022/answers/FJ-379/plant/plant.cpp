#include<bits/stdc++.h>
using namespace std;

const int N = 1005, Mod = 998244353;
typedef long long LL;

char a[N][N];
int lft[N][N], down[N][N];

int main(){
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	int T, id;
	scanf("%d%d", &T, &id);
	while(T --){
		int n, m, c, f;
		scanf("%d%d%d%d", &n, &m, &c, &f);
		
		for(int i = 1; i <= n; i ++){
			scanf("%s", a[i] + 1);
		}
		
		for(int i = 1; i <= n; i ++){
			int k = m + 1;
			for(int j = m; j >= 1; j --){
				if(a[i][j] == '1')k = j;
				lft[i][j] = k;
			}
		}
		
		for(int i = 1; i <= m; i ++){
			int k = n + 1;
			for(int j = n; j >= 1; j --){
				if(a[j][i] == '1')k = j;
				down[j][i] = k;
			}
		}
		
		LL ans = 0;
//		for(int i = 1; i <= m; i ++){
//			for(int j = 1; j <= n; j ++){
//				LL sum = 0, mul = 0;
//				for(int k = j; k < down[j][i]; k ++){
//					int x = lft[k][i] - i - 1;
//					sum = (sum + x) % Mod;
//					mul = (mul + x * x % Mod) % Mod;
//					if(k != j){
//						int y = lft[k - 1][i] - i - 1;
//						mul = (mul + x * y * 2 % Mod) % Mod;
//					}
//				}
//				ans = (ans + ((sum * sum % Mod) - mul) * 499122177 % Mod) % Mod;
//			}
//		}
		LL ansc = 0, ansf = 0;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				for(int k = i + 2; k < down[i][j]; k ++){
					int x = lft[i][j] - j - 1, y = lft[k][j] - j - 1;
					int z = down[k][j] - k - 1;
					ansc = (ansc + x * y % Mod) % Mod;
					ansf = (ansf + x * y % Mod * z % Mod) % Mod;
				}
			}
		}
		
	
		printf("%d %d\n", ansc * c, ansf * f);
		
		
	}
		
	return 0;
}
