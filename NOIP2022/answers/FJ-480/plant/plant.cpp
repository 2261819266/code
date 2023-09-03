// koruneko!
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define N 1010
#define mod 998244353
using namespace std;

int n,m,C,F,f[N][N],g[N][N];
char a[N][N];
ll ans1,ans2;
void solve(){
	scanf("%d%d%d%d",&n,&m,&C,&F);
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	ans1 = 0;ans2 = 0;
	for (int i = 0;i < n;i++) scanf("%s",a[i]);
	for (int i = 0;i < n;i++){
		for (int j = m - 1;j >= 0;j--){
			if (a[i][j] == '0') f[i][j] = f[i][j + 1] + 1;
			else f[i][j] = 0;
		}
	}
	for (int i = 0;i < m;i++){
		for (int j = n - 1;j >= 0;j--){
			if (a[j][i] == '0') g[j][i] = g[j + 1][i] + 1;
			else g[j][i] = 0;
		}
	}
	for (int i = 0;i < m;i++){
		ll p = 0,q = 0;
		ll sum = 0,sum2 = 0;
		for (int j = n - 1;j >= 0;j--){
			if (a[j][i] == '1'){
				p = 0;q = 0;
				continue;
			}
			p %= mod;q %= mod;
			sum += (ll)f[j][i + 1] * p % mod;
			sum2 += (ll)f[j][i + 1] * q % mod;
			if (f[j + 1][i] > 1 && f[j][i + 1]) sum -= (ll)f[j][i + 1] * f[j + 1][i + 1] % mod,sum += mod,sum %= mod;
			if (f[j + 1][i] > 1 && f[j][i + 1]) sum2 -= (ll)((ll)f[j][i + 1] * f[j + 1][i + 1] % mod) * g[j + 2][i] % mod,sum2 += mod,sum2 %= mod;
			if (f[j][i + 1]) p += f[j][i + 1] % mod,q += (ll)f[j][i + 1] * g[j + 1][i] % mod;
			p %= mod;q %= mod;
		}
		sum %= mod;sum2 %= mod;
		ans1 += sum % mod;ans2 += sum2 % mod;
		ans1 %= mod;ans2 %= mod;
	}
	ans1 %= mod;ans2 %= mod;
	if (C == 0) ans1 = 0;
	if (F == 0) ans2 = 0;
	cout << ans1 << " " << ans2 << endl;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	cin >> T >> id;
	while (T--) solve();
	return 0;
}
