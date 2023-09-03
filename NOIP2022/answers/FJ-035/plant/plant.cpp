# include <bits/stdc++.h>
# define N 1010
# define MOD 998244353
char s[N][N];
int r[N][N],sum[N],d[N][N];
void _() {
	int n,m,c,f,i,j,ans1=0,ans2=0;
	scanf("%d%d%d%d",&n,&m,&c,&f);
	for(i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(i=1;i<=n;i++) {
		r[i][m+1]=-1;
		for(j=m;j>=1;j--) {
			if(s[i][j]=='1') r[i][j]=-1;
			else r[i][j]=r[i][j+1]+1;
		}
	}
	for(j=1;j<=m;j++) {
		d[n+1][j]=-1;
		for(i=n;i>=1;i--) {
			if(s[i][j]=='1') d[i][j]=-1;
			else d[i][j]=d[i+1][j]+1;
		}
	}
	// for(i=1;i<=n;i++) {
	// 	for(j=1;j<=m;j++) printf("%d ",r[i][j]);
	// 	puts("");
	// }
	for(j=1;j<=m;j++) {
		for(i=1;i<=n;i++) sum[i]=sum[i-1]+r[i][j];
		for(i=1;i<n;i++) {
			if(d[i][j]>=1) ans1=(1ll*(sum[i+d[i][j]]-sum[i+1]+MOD)*r[i][j]+ans1)%MOD;
		}
		for(i=1;i<=n;i++) sum[i]=((d[i][j]>=0?1ll*r[i][j]*d[i][j]:0)+sum[i-1])%MOD;
		for(i=1;i<n;i++) {
			if(d[i][j]>=1) ans2=(1ll*(sum[i+d[i][j]]-sum[i+1]+MOD)*r[i][j]+ans2)%MOD;
		}
	}
	printf("%d %d\n",c*ans1,f*ans2);
}
int main() {
	int T,id;
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--) _();
	return 0;
}
