//noip rp+++++;
#include <cstdio>
#include <algorithm>
using namespace std;

int T , n , Q;
int a[250003];
int b[250003];
int maxn[3003][3003][3];
const unsigned long long MOD = (long long)(1) << (long long)(63);

void init(){
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			maxn[i][j][0] = max(maxn[i][j - 1][0] , a[j]);
			maxn[i][j][1] = max(maxn[i][j - 1][1] , b[j]);
//			maxn[i][j][3] = (long long)maxn[i][j][0] * maxn[i][j][1] % MOD;
//			maxn[i][j][3] += (long long)maxn[i - 1][j][3] - maxn[i - 1][j - 1][3] + maxn[i][j - 1][3];
//			maxn[i][j][3] %= MOD;
		}
	}
//	for(int i = 1;i <= n;i++){
//		for(int j = i;j <= n;j++){
//			printf("%d,%d:%d %d\n" , i , j , maxn[i][j][0] , maxn[i][j][1]);
//		}
//	}
}

int main(void){
	freopen("match.in" , "r" , stdin);
	freopen("match.out" , "w" , stdout);	
	scanf("%d%d" , &T , &n);
	for(int i = 1;i <= n;i++)
		scanf("%d" , &a[i]);
	for(int j = 1;j <= n;j++)
		scanf("%d" , &b[j]);
	scanf("%d" , &Q);
	if(T <= 5 && T > 2)
		init();	
//	if(T == 0 && n == 2){
//		puts("8");
//		return 0;
//	}
	while(Q--){
		int l , r;
		long long ans = 0;
		scanf("%d%d" , &l , &r);
		if(T <= 2){
			for(int q = l;q <= r;q++){
				for(int p = q;p <= r;p++){
					long long maxnn = -1;
					long long maxm = -1;
					for(int i = q;i <= p;i++){
						maxnn = max(maxnn , (long long)a[i]);
						maxm = max(maxm , (long long)b[i]);
					}	
					ans += maxnn * maxm % MOD;
					ans %= MOD;
				}
			}
		}
		else if(T <= 5){
//			ans = maxn[r][r][3] - maxn[l - 1][r][3] - maxn[r][l - 1][3] + maxn[l - 1][l - 1][3];
			for(int q = l;q <= r;q++){
				for(int p = q;p <= r;p++){						
					ans += maxn[q][p][0] * maxn[q][p][1] % MOD;
					ans %= MOD;					
				}
			}
		}
		else{
			for(int q = l;q <= r;q++){
				for(int p = q;p <= r;p++){
					long long maxnn = -1;
					long long maxm = -1;
					for(int i = q;i <= p;i++){
						maxnn = max(maxnn , (long long)a[i]);
						maxm = max(maxm , (long long)b[i]);
					}
					ans += maxnn * maxm % MOD;
					ans %= MOD;
				}
			}
		}
		printf("%lld\n" , ans);
	}
	return 0;
}