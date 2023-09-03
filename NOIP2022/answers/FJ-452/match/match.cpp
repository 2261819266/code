#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int T, n, Q;
int l, r;
long long a[250005], b[250005];
long long ans;
int main(){
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	cin >> T >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];
	cin >> Q;
	while(Q--){
		ans = 0;
		cin >> l >> r;
		for(int p = l; p <= r; p++){
			for(int q = p; q <= r; q++){
				if(p == q) ans += a[p] * b[q];
				else{
					long long x, y = 0;
					for(int k = p; k <= q; ++k){
						x = max(x, a[k]);
						y = max(y, b[k]);
					}
					ans += x * y;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
