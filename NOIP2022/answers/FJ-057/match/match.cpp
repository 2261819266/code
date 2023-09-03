#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXX 250010
#define ll unsigned long long
using namespace std;
ll a[MAXX],b[MAXX];
ll sta1[MAXX],it1=0,sta2[MAXX],it2=0;
ll tra[MAXX];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		ll ans=0;
		ll las=0;
		memset(tra,0,sizeof(tra));
		ll o=0,p=0;
		for(int k=l;k<=r;k++){
			o=max(o,a[k]);
			p=max(p,b[k]);
			tra[k]=o*p;
			las+=o*p;
		}
		ans+=las;
		for(int j=l+1;j<=r;j++){
			las-=tra[j-1];
			ll maxx1=0,maxx2=0;
			for(int k=j;k<=r;k++){
				maxx1=max(maxx1,a[k]);
				maxx2=max(maxx2,b[k]);
				if(tra[k]!=maxx1*maxx2){
					las-=tra[k];
					tra[k]=maxx1*maxx2;
					las+=tra[k];
				}else break;
			}
			ans+=las;
		}
		cout << ans << endl;
	}
	return 0;
}
