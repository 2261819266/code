#include<cstdio>
#include<iostream>
const int maxn=1e3+10;
const int mod=998244353;
int T,ID,n,m,C,F;
long long f[maxn][maxn],sumc[maxn],sumf[maxn],ansc,ansf;
char a[maxn][maxn];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&ID);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&C,&F);
		for(int i=1;i<=n;++i){
			scanf("%s",a[i]+1);
			for(int j=m;j;--j){
				if(a[i][j]=='1')f[i][j]=-1;
				else if(j==m||a[i][j+1]=='1')f[i][j]=0;
				else f[i][j]=f[i][j+1]+1;
			}
			
		}
		for(int j=1;j<=m;++j){
			for(int i=1,d=1;i<=n;i=d+1,d=i){
				if(a[i][j]=='1')continue;
				while(d<n&&a[d+1][j]=='0')++d;
				sumc[i-1]=sumf[i-1]=0;
				for(int k=i;k<=d;++k){
					sumc[k]=(sumc[k-1]+f[k][j])%mod;
					sumf[k]=(sumf[k-1]+f[k][j]*(d-k)%mod)%mod;
				}
				for(int k=i;k<d;++k){
					ansc=(ansc+f[k][j]*(sumc[d]-sumc[k+1])%mod)%mod;
					ansf=(ansf+f[k][j]*(sumf[d]-sumf[k+1])%mod)%mod;
				}
			}
		}
		ansc=(ansc+mod)%mod,ansf=(ansf+mod)%mod;
		printf("%lld %lld\n",C*ansc,F*ansf);
	}
	return 0;
}
