#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int T,id,n,m;
int a[1005][1005];
int fa[1005][1005];
long long sum1[1005][1005];
long long sum2[1005][1005];
long long sum3[1005][1005];
long long cans,fans,c,f;
char s[1005];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		cans=fans=0;
		scanf("%d%d%lld%lld",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m;j++){			
				a[i][j]=(s[j]=='1');
				fa[i][j]=0;
			}
		}
		for(int j=1;j<=m;j++){
			fa[n][j]=n+1;
			for(int i=n-1;i>=1;i--){
				if(!a[i][j])fa[i][j]=fa[i+1][j];
				else fa[i][j]=i;
			}
		}
		for(int i=1;i<=n;i++){
			a[i][m+1]=0;
			for(int j=m;j>=1;j--){
				if(a[i][j]||a[i][j+1]||j==m)sum1[i][j]=0;
				else sum1[i][j]=sum1[i][j+1]+1;
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(a[i][j])sum2[i][j]=0,sum3[i][j]=0;
				else sum2[i][j]=(sum2[i-1][j]+sum1[i][j])%mod,sum3[i][j]=(sum3[i-1][j]+sum1[i][j]*(fa[i][j]-i))%mod;
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n-2;i++){
				if(a[i][j]||a[i+1][j]||a[i+2][j])continue;
				int sit=fa[i][j]-1;
				if(sit<=i+1)continue;
				cans=(cans+sum1[i][j]*(sum2[sit][j]-sum2[i+1][j]+mod)%mod)%mod;
				if(a[i+3][j]||i==n-2)continue;
				int sit2=fa[i][j]-i;
				fans=(fans+sum1[i][j]*(sum3[sit][j]-sum3[i+1][j]-(sum2[sit][j]-sum2[i+1][j])+mod+mod)%mod);
			}
		}
		printf("%lld %lld\n",cans*c%mod,fans*f%mod);
	}
	return 0;
}

