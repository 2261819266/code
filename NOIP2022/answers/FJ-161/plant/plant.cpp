#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
const int mod = 998244353 , MAXN = 1e3 + 10 ;
typedef long long ll ;
int T , typ , n , m , C , F , c[MAXN][MAXN] , p[MAXN][MAXN] , d[MAXN][MAXN] ;
ll ansc , ansf , g[MAXN][MAXN] ;
char s[MAXN][MAXN] ;
void U (ll &x , ll y) {x = x + y >= mod ? x + y - mod : x + y ;}
int main () {
	freopen ("plant.in" , "r" , stdin) ;
	freopen ("plant.out" , "w" , stdout) ;
	scanf ("%d%d" , &T , &typ) ;
	while (T--) {
		scanf ("%d%d%d%d" , &n , &m , &C , &F) ;
		for (int i = 1 ; i <= n ; i++) scanf ("%s" , s[i] + 1) ;
		for (int i = 1 ; i <= n ; i++) {
			c[i][m + 1] = 0 ;
			for (int j = m ; j ; j--)
				c[i][j] = (s[i][j] == '0') ? (c[i][j + 1] + 1) : 0 ;
		}
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= m ; j++) {
				d[i][j] = (c[i][j] + d[i - 1][j] - 1 + mod) % mod ;
				g[i][j] = ((ll)(c[i][j] - 1 + mod) % mod * i % mod + g[i - 1][j]) % mod ; 
			}
		for (int j = 1 ; j <= m ; j++) {
			p[n + 1][j] = 0 ;
			for (int i = n ; i ; i--)
				p[i][j] = (s[i][j] == '0') ? (p[i + 1][j] + 1) : 0 ;
		}
		ansc = ansf = 0 ;
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= m ; j++) {
				if (s[i][j] == '1') continue ;
				int x = i + p[i][j] - 1 ;
				if (x > i + 1) U (ansc , (ll)(d[x][j] - d[i + 1][j] + mod) % mod * (c[i][j] - 1) % mod) ;
				if (x > i + 2) {
					ll tmp = (d[x - 1][j] - d[i + 1][j] + mod) % mod ;
					U (ansf , (ll)(tmp * x % mod - g[x - 1][j] + g[i + 1][j] + mod) % mod * (c[i][j] - 1) % mod) ;
				}
			}
		printf ("%lld %lld\n" , (C ? ansc : 0) , (F ? ansf : 0));
	}
	return 0 ;
} 
