#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int n, m;
int u, v;
int ans = 0;
int fac[500005];

int main(){
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m);
	fac[1] = 1;
	for (int i = 2; i <= n; i++) fac[i] = fac[i-1]*i, fac[i]%=mod;
	for (int i = 1; i < n; i++){
		ans+=(i*3-1+(n-i)*3-1)*1, ans%=mod;
	}
	printf("%d", ans+1);
	return 0;
}
