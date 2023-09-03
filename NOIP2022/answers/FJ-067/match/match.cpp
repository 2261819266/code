#include<bits/stdc++.h>
using namespace std;
const unsigned long long Mod = (1 << 61) - 1;
unsigned long long T, n, q, ans, a[3100], b[3100];
int main() {
  freopen("match.in", "r", stdin);
  freopen("match.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> T >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  cin >> q;
  for(int i = 1; i <= q; ++i) {
  	int p, r;
  	cin >> p >> r;
  	for(int j = p; j <= r; ++j) {
  		unsigned long long  maxa = 0, maxb = 0;
  		for(int k = p; k <= j; ++k) {
  			maxa = max(maxa, a[k]);
  			maxb = max(maxb, b[k]);
  			ans = ans + maxa * maxb % Mod;;
  			ans %= Mod;
			}
		}
	}
	cout << ans;
  return 0;
}

