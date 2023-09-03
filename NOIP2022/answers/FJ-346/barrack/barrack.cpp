#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int mod=1e9+7;
int n,m;
LL ksm(LL x,LL y){
	LL res=1ll;
	for(;y;y>>=1ll){
		if(y&1ll) res=res*x%mod;
		x=x*x%mod;
	}
	return res;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	printf("%lld",(ksm(2,n)-1ll+mod)%mod*ksm(2,m)%mod);
	return 0;
}
