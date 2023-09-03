#include <bits/stdc++.h>
using namespace std;
int t, n, q;
int a[3005] = {0};
int b[3005] = {0};
const unsigned long long MOD = 1;

int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	unsigned long long tmp = -1;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		unsigned long long ans = 0;
		for (int p = l; p <= r; p++)
		{
			for (int q = p; q <= r; q++)
			{
				unsigned long long Maxa = 0;
				for (int i = p; i <= q; i++) Maxa = max((unsigned long long)a[i], Maxa);
				unsigned long long Maxb = 0;
				for (int i = p; i <= q; i++) Maxb = max((unsigned long long)b[i], Maxb);
				ans += (Maxa * Maxb);
			}
		}
		cout << ans << endl;
	}
	//I was very glad as soon as I saw the problem because it so difficult that NO ONE can work out it.So NO ONE can AK NOIp2022!
	return 0;
}
