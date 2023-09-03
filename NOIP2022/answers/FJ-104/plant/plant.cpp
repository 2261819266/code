#include<cstdio>
#include<cstdlib>
using namespace std;

typedef long long ll;
const int N = 3000, MOD = 998244353;

int right[N+5][N+5];
int down[N+5][N+5];
int down_c[N+5][N+5];
int down_f[N+5][N+5];

void init(int n, int m, int pos_u[]);

signed main(){
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int T, id;
	scanf("%d%d", &T, &id);
	while(T--){
		int n, m, c, f;
		scanf("%d%d%d%d", &n, &m, &c, &f);
		char tmp_c;
		int pos_u[N+5];//The nearest place up here where is not a hole.
		init(n, m, pos_u);
		for(int i = 1; i <= n + 1; i++){
			int pos_l = 1;//The nearest place on the left where is not a hole.
			for(int j = 1; j <= m + 1; j++){
				if(i != n + 1 && j != m + 1)	scanf(" %c", &tmp_c);
				if(tmp_c == '1' || j == m + 1){
					for(int k = j-1; k >= pos_l; k--)
						right[i][k] = right[i][k+1] + 1;
					pos_l = j + 1;
					
				}if(tmp_c == '1' || i == n + 1){
					for(int k = i-1; k >= pos_u[j]; k--)
						down[k][j] = down[k+1][j] + 1;
					pos_u[j] = i + 1;
				}
			}
		}
		
/*		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++)
				printf("%d ", right[i][j]);
			printf("\n");
		}printf("\n");
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++)
				printf("%d ", down[i][j]);
			printf("\n");
		}printf("\n");
*/		
			
		for(int j = 1; j <= m; j++){
			for(int i = 1; i <= n; i++){
				if(right[i][j] == -1)	continue;
				int k = i - 1;
				if(k < 1 || right[k][j] == -1)	continue;
				while(right[--k][j] != -1){
					down_c[k][j] = (down_c[k][j] + ll(right[i][j]) % MOD) % MOD;
					down_f[k][j] = (ll(down_f[k][j]) + ll(right[i][j]) * down[i][j] % MOD) % MOD;
				}
			}
		}
/*		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++)
				printf("%d ", down_c[i][j]);
			printf("\n");
		}printf("\n");
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++)
				printf("%d ", down_f[i][j]);
			printf("\n");
		}printf("\n");
*/		
		ll ans_c = 0, ans_f = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(right[i][j] < 1)	continue;
				ans_c = (ll(ans_c) + ll(right[i][j]) * down_c[i][j] % MOD) % MOD;
				ans_f = (ll(ans_f) + ll(right[i][j]) * down_f[i][j] % MOD) % MOD;
			}
		}
		printf("%d %d\n", int((ans_c * c) % MOD), int((ans_f * f) % MOD));
	}
	return 0;
}

void init(int n, int m, int pos_u[]){
	for(int i = 0; i <= n+1; i++)
		for(int j = 0; j <= m+1; j++)
			right[i][j] = down[i][j] = -1,
			down_c[i][j] = down_f[i][j] = 0;
	for(int j = 1; j <= m; j++)	pos_u[j] = 1;
}
