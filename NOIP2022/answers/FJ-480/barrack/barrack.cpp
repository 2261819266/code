#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n;cin >> n;
	ll ans = 1;
	for (int i = n;i > 1;i--){
		ans = (ll)ans * i % mod;
	}
	cout << ans;
	return 0;
}

