#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD=998244353;
ll the_test,id,a[1020][1020];
ll n,m,c,d,sum[1020][1020];
bool vis[1020][1020];
ll sumc,sumf;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&the_test,&id);
	while(the_test--){
		scanf("%lld%lld%lld%lld",&n,&m,&c,&d);
		if(c==0&&d==0)puts("0 0");
		else{		
			for(int i=1;i<=n;i++){
				char st[1020];
				scanf("%s",st+1);
				for(int j=1;j<=m;j++)
					vis[i][j]=!(st[j]-'0');
			}
			for(int i=1;i<=n;i++){
				ll s=0;
				for(int j=m;j>=1;j--){
					if(vis[i][j]){sum[i][j]=s;s++;}
					else{s=0;sum[i][j]=s;}
				}
			}
			for(int i=1;i<=m;i++){
				ll s=0;
				for(int j=n;j>=1;j--){
					if(vis[j][i]){a[j][i]=s;s++;}
					else{s=0;a[j][i]=s;}
				}
			}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					if(a[i][j]>=2&&sum[i][j]>=1)
						for(int k=i+2;k<=i+a[i][j];k++)
							if(sum[k][j]>=1){
								int x=(sum[i][j]*sum[k][j])%MOD;
								sumc=(sumc+x)%MOD;
								sumf=(sumf+(x*a[k][j])%MOD)%MOD;
							}
			printf("%d %d",(sumc*c)%MOD,(sumf*d)%MOD);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
