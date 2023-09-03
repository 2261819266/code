//noip rp+++++;
#include <cstdio>
#define MOD (long long)(998244353)
using namespace std;

//chm_qwq orz and chm_qwq is dalao.

int T , id;
bool a[1005][1005];
int bb[1005][1005];
int cc[1005][1005];
int dd[1005][1005];

void init(int n , int m){
	for(int j = 1;j <= m;j++){
		int x = n;
		for(int i = n;i >= 1;i--){		
			if(a[i][j]){
				x = i - 1;
				continue;
			}
			bb[i][j] = x;
		}
	}
	for(int i = 1;i <= n;i++){
		int x = m;
		for(int j = m;j >= 1;j--){
			if(a[i][j]){
				x = j - 1;
				continue;
			}
			cc[i][j] = x;
		}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			dd[i][j] = (cc[i][j] + dd[i - 1][j]) % MOD;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++)
//			printf("%d " , cc[i][j]);
//		puts("");
//	}
}

int main(void){
	freopen("plant.in" , "r" , stdin);
	freopen("plant.out" , "w" , stdout);
	scanf("%d%d" , &T , &id);
	while(T--){
		int n , m , c , f;
		long long vc = 0 , vf = 0;
		scanf("%d%d%d%d" , &n , &m , &c , &f);
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				scanf("%1d" , &a[i][j]);
//		if(id == 5 || id == 6){
//			puts("0 0");
//			continue;
//		}
		if(c == 0 && f == 0){
			puts("0 0");
			continue;
		}
		init(n , m);
		if(c > 0){
			if(n <= 500 && m <= 500){
				for(int x1 = 1;x1 <= n - 1;x1++){
					for(int y0 = 1;y0 <= m;y0++){
						if(a[x1][y0]) continue;
						long long sum = 0;
						long long qwq1 = cc[x1][y0] - y0;
						if(qwq1 == 0) continue;
						if(bb[x1][y0] - x1 < 2) continue;
						for(int x2 = x1 + 2;x2 <= n;x2++){
							if(a[x2][y0]) break;
							long long qwq2 = cc[x2][y0] - y0;						
							sum += qwq1 * qwq2 % MOD;
							sum %= MOD;
						}
						vc += sum % MOD;
						vc %= MOD;
					}
				}
			}
			else{
				for(int x1 = 1;x1 <= n - 1;x1++){
					for(int y0 = 1;y0 <= m;y0++){
						if(a[x1][y0]) continue;
						long long sum = 0;
						long long qwq1 = cc[x1][y0] - y0;
						if(qwq1 == 0) continue;
						if(bb[x1][y0] - x1 < 2) continue;
						long long x2 = bb[x1][y0];
						long long qwq2 = dd[x2][y0] - dd[x1 + 1][y0] - (x2 - x1 - 1) * y0;
						vc += qwq2 * qwq1 % MOD;
						vc %= MOD;
					}
				}
			}
		}
		if(f > 0){
			for(int x1 = 1;x1 <= n - 1;x1++){
				for(int y0 = 1;y0 <= m;y0++){
					if(a[x1][y0]) continue;
					long long sum = 0;
					long long qwq1 = cc[x1][y0] - y0; //y0
					if(qwq1 == 0) continue;
					if(bb[x1][y0] - x1 < 2) continue;
					for(int x2 = x1 + 2;x2 <= n && qwq1;x2++){
						if(a[x2][y0]) break;
						long long qwq2 = cc[x2][y0] - y0; //y1
						sum += (qwq1 * qwq2 % MOD) * (bb[x2][y0] - x2) % MOD;
						sum %= MOD;
					}
					vf += sum % MOD;
					vf %= MOD;
				}
			}
		}
		printf("%lld %lld\n" , vc , vf);
	}
	return 0;
}