#include<bits/stdc++.h>
#define int long long
#define reg register
using namespace std;
inline int cmax(reg int x,reg int y){return x>y?x:y;}
const int N=3e3+10,mod=1e9+7;
int n,m,ans[N];
int a[N],b[N],id;
#define ull unsigned long long
ull sum[N][N];
inline ull query(reg int l1,reg int r1,reg int l2,reg int r2){return sum[l2][r2]-sum[l2][r1-1]-sum[l1-1][r2]+sum[l1-1][r1-1];}
signed main(){
	freopen("match.in","r",stdin);freopen("match.out","w",stdout);
	scanf("%lld%lld",&id,&n);
	for (reg int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (reg int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for (reg int i=1;i<=n;i++){
		reg int mx1=-1,mx2=-1;
 		for (reg int j=i;j<=n;j++){
 			mx1=cmax(mx1,a[j]);mx2=cmax(mx2,b[j]);
			sum[i][j]=(ull)mx1*(ull)mx2;
		} 
	}
	for (reg int i=1;i<=n;i++) for (reg int j=1;j<=n;j++) sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
//	for (reg int i=0;i<=n;i++,puts("")) for (reg int j=0;j<=n;j++) cout<<sum[i][j]<<" ";
	scanf("%lld",&m);
	while (m--){
		reg int l,r; scanf("%lld%lld",&l,&r);
		printf("%llu\n",query(l,l,r,r));
	}
	return 0;
}
/*
4 20 6
1 3 4 1 2 2 6 3 6 2 1 3 2 4 6 3 6 1 5 5
*/