#include <bits/stdc++.h>
using namespace std;
int T,n,a[250001],b[250001],Q;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	scanf("%d",&Q);
	for (int i=1,l,r;i<=Q;i++){
		scanf("%d%d",&l,&r);
		unsigned long long ans=0;
		for (int p=l,Maxa=0,Maxb=0;p<=r;p++,Maxa=Maxb=0) for (int q=p;q<=r;q++){
			Maxa=max(Maxa,a[q]),Maxb=max(Maxb,b[q]);
			ans+=1ll*Maxa*Maxb;
		}
		cout<<ans<<endl;
	}
	return 0;
}
