#include<iostream>
#include<cstdio>
const int M = 1e9+7;
long long ans;
signed main(){
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	int n,m;
	scanf("%d%d", &n, &m);
	ans=n;
	for(int i=1;i<=n;i++){
		ans=ans*i%M;
	}
	ans=(ans<<1)%M;
	ans=ans-n-m;
	printf("%lld", ans);
}
