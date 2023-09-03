//NOIP2022 RP++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll T, n, a[250005], b[250005], Q;
int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T >> n;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	for (ll i = 1; i <= n; i++)
		cin >> b[i];
	cin >> Q;
	for (ll ii = 1, l, r; ii <= Q; ii++)
	{
		cin >> l >> r;
		ll ans = 0;
		for (ll i = l; i <= r; i++)
			for (ll j = i; j <= r; j++)
			{    
				ll aMax = -0x3f3f3f3f, bMax = -0x3f3f3f3f;
				for (ll k = i; k <= j; k++)
					aMax = max(aMax, a[k]), bMax = max(bMax, b[k]);
				ans += aMax * bMax;
			}
		cout << ans << endl;
	}
	return 0;
}