#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e3+3,mod=1e9+7;
bool a[N][N];
int n,m,c,f,dp[N][N];

void CCF(){
	memset(dp,0,sizeof(dp)); int ans=0,ans2=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!a[i][j]){
				if(dp[i][j-1]) dp[i][j]=dp[i][j-1]-1;
				else{
					for(int k=j+1;k<=m;k++)
						if(!a[i][k]) dp[i][j]++;
						else break;
				}
				int now=0;
				if(i>=3&&!a[i-1][j]){
					for(int k=i-2;k;k--)
						if(!a[k][j]) now=(now+dp[i][j]*dp[k][j]%mod)%mod;
						else break;
					ans=(ans+now)%mod;
				}
				if(f&&i>=4){
					int now2=0;
					for(int k=i-1;k;k--){
						if(!a[k][j]&&!a[k-1][j]&&k>=3){
							for(int l=k-2;l;l--)
								if(!a[l][j]) now2=(now2+dp[k][j]*dp[l][j]%mod)%mod;
								else break;
						}
						else break;
					}
					ans2=(ans2+now2)%mod;
				}
			}
	printf("%lld %lld\n",ans,ans2);
}

void real_main(){
	scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
	if(!c&&!f){
		printf("0 0");
		return;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1lld",&a[i][j]);
	CCF();
}

signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id; scanf("%lld%lld",&T,&id);
	while(T--) real_main();
}
