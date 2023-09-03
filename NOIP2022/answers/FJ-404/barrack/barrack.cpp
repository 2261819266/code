#include<bits/stdc++.h>
#define ll long long
const int Mod = 1e9 + 7;
using namespace std;
int n, m;
ll jc[500005];
ll ans;
int main()
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m);
	jc[0] = jc[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		jc[i] = (i * jc[i - 1]) % Mod;
	}
	for(int i = 1; i <= n; i++)
	{
		ans = ans + jc[n] / jc[i] / jc[n - i];
		ans = ans % Mod;
		if(i == 1) ans = (ans + n) % Mod;
	}
	printf("%lld", ans);
	return 0;
}