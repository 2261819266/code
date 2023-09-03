#include<bits/stdc++.h>
#define L unsigned long long
#define N 300000
using namespace std;
L T,n,Q,ans,a[N],b[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&T,&n);
	for(L i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(L i=1;i<=n;i++)scanf("%lld",&b[i]);
	scanf("%lld",&Q);
	for(L i=1;i<=Q;i++){
		ans=0;
		L l,r;
		scanf("%lld%lld",&l,&r);
		for(L p=l;p<=r;p++)for(L q=p;q<=r;q++){
			L maxa=0,maxb=0;
			for(L k=p;k<=q;k++)maxa=max(maxa,a[k]),maxb=max(maxb,b[k]);
			ans+=maxa*maxb;
		}
		printf("%lld\n",ans);
	}
}
