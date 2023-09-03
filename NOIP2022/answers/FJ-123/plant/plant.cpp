#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 15;
ll mod = 998244353;
ll mapn[N][N];
ll T, id;
ll n, m, c, f;
ll g[N][N], down[N][N];

int main(){
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%lld %lld", &T, &id);
	while(T --){
		scanf("%lld %lld %lld %lld", &n, &m, &c, &f);
		memset(mapn, 0, sizeof(mapn));
		memset(g, 0, sizeof(g));
		memset(down, 0, sizeof(down));
		ll ansc = 0, ansf = 0;
		for(ll i = 1; i <= n; i ++){
			string s;
			cin >> s;
			for(ll j = 0; j < s.size(); j ++) mapn[i][j + 1] = s[j] - 48;
		}
		for(ll i = 1; i <= n; i ++)
			for(ll j = m; j >= 1; j --)
				if(!mapn[i][j]) g[i][j] = g[i][j + 1] + 1;
		for(ll i = n; i >= 1; i --)
			for(ll j = 1; j <= m; j ++) 
				if(!mapn[i][j]) down[i][j] = down[i + 1][j] + 1;	
		
		for(ll k = 1; k <= m; k ++)
			for(ll j = 1; j <= n; j ++)
				if(g[j][k] >= 2 && !mapn[j][k] && !mapn[j + 1][k]){
					for(ll t = j + 2; t <= n; t ++){
						if(mapn[t][k]) break;
						if(g[t][k] >= 2){
							ll xx = (g[j][k] - 1) * (g[t][k] - 1) % mod;
							ansc = ((ansc + (g[j][k] - 1) * (g[t][k] - 1)) % mod + mod) % mod;
							ansf = (((ansf + xx * (down[t][k] - 1) % mod) % mod + mod) % mod + mod) % mod;
						}
					}
				}
		ansc = (ansc * c % mod + mod) % mod;
		ansf = (ansf * f % mod + mod) % mod; 
		printf("%lld %lld\n", ansc, ansf);
	}
	return 0;
}
