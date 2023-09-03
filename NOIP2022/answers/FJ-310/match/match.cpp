#include<bits/stdc++.h>
#define reg register
#define IL inline
using namespace std;
const int N=250007;
int ID,n,a[N],b[N],q;
long long f[3007][3007],C;
int main(){
	freopen("match.in","r",stdin),freopen("match.out","w",stdout);
	scanf("%d%d",&ID,&n);
	for(reg int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(reg int i=1;i<=n;++i)scanf("%d",&b[i]);
	scanf("%d",&q);
	for(reg int i=1,x,y;i<=n;++i){
		x=y=0;
		for(reg int j=i;j<=n;++j){
			x=max(x,a[j]),y=max(y,b[j]),f[i][j]=f[i][j-1]+1ll*x*y;
		}
	}
	for(reg int l,r;~--q;){
		scanf("%d%d",&l,&r),C=0;
		for(reg int i=l;i<=r;++i)C+=f[i][r];
		printf("%lld\n",C);
	}
	return 0;
}
