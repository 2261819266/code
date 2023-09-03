# include <bits/stdc++.h>
# define N 3010
int a[N],b[N];
unsigned long long f[N][N],sum[N][N],g[N][N];
int main() {
	int T,n,i,j,q;
	freopen("match.in","r",stdin); 
	freopen("match.out","w",stdout); 
	scanf("%d%d",&T,&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	for(i=1;i<=n;i++) {
		int mxa=0,mxb=0;
		for(j=i;j<=n;j++) {
			if(a[j]>mxa) mxa=a[j];
			if(b[j]>mxb) mxb=b[j];
			f[i][j]=1ll*mxa*mxb;
		}
	}
	for(i=1;i<=n;i++) g[i][i]=f[i][i];
	for(j=1;j<=n;j++) {
		for(i=1;i<=n;i++) sum[i][j]=sum[i-1][j]+f[i][j];
	}
	int l;
	for(l=2;l<=n;l++) {
		for(i=1,j=i+l-1;j<=n;i++,j++) {
			g[i][j]=g[i][j-1]+sum[j][j]-sum[i-1][j];
		}
	}
	scanf("%d",&q);
	while(q--) {
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%llu\n",g[l][r]);
	}
	return 0;
}
