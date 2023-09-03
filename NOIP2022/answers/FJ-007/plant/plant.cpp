#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Q=1e3+10;
const ll P=998244353;
ll T,id,n,m,c,f,a[Q][Q],r[Q][Q],d[Q][Q],ansc,ansf,p;
char s[Q];
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&T,&id);
	while(T--) {
		ansc=0,ansf=0;
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		for(ll i=1; i<=n; i++) {
			scanf("%s",s+1);
			for(ll j=1; j<=m; j++)
				a[i][j]=s[j]-'0';
		}
		for(ll i=n; i>=1; i--) {
			for(ll j=m; j>=1; j--) {
				r[i][j]=0,d[i][j]=0;
				if(!a[i][j]) {
					r[i][j]=1,d[i][j]=1;
					if(!a[i][j+1])
						r[i][j]+=r[i][j+1];
					if(!a[i+1][j])
						d[i][j]+=d[i+1][j];
				}
			}
		}
		for(ll i=1; i<=n; i++) {
			for(ll j=1; j<=m; j++) {
				if(r[i][j]>1) {
					p=r[i][j]-1;
					for(ll l=i+2; l<=d[i][j]+i-1; l++) {
						ansc=(ansc+p*(r[l][j]-1)%P)%P;
						ansf=(ansf+p*(r[l][j]-1)*(d[l][j]-1)%P)%P;
					}
				}
			}
		}
		printf("%lld %lld\n",ansc*c,ansf*f);
	}
	return 0;
}
