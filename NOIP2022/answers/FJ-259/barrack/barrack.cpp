#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 3;

int n,m;
int res;

inline int qpow(int a,int b){
	int ans = 1;
	int x = a;
	int y = b;
	while(y){
		if(y & 1){
			ans *= x;
			ans %= mod;
		}
		x *= x;
		x %= mod;
		y >>= 1;
	}
	return ans;
}

int jz(int x){
	int ans = 1;
	for(int i = 1;i<=x;i++){
		ans *= x;
		ans %= mod;
	}
	return ans;
}

int inv(int x){
	return qpow(x,mod - 2);
}

int zuhe(int n,int m){
	return jz(n) * inv(jz(m)) * inv(jz(n - m));
}

signed main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		int xx = zuhe(n,i);
		res += xx * 2;
		res %= mod;
	}
	cout<<res % mod<<endl;
	return 0;
}
