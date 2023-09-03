#include<cstdio>
#include<cstring>
const int mod=998244353;
const int N=1010;
char s[N][N];
int f[N][N],g[2][4],tmp[4];
void work(){
	int n,m,C,F,ans1=0,ans2=0;
	scanf("%d%d%d%d",&n,&m,&C,&F),memset(f,0,sizeof f);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(s[i][j]=='0')f[i][j]=f[i][j+1]+1;
//			printf("%d %d %d\n",i,j,f[i][j]);
		}
	}
	for(int j=1;j<=m;j++){
		memset(g,0,sizeof g),g[0][0]=1;
		for(int i=1;i<=n;i++){
			if(s[i][j]=='1'){
				memset(g,0,sizeof g),g[0][0]=1;
				continue;
			}
			ans2=(ans2+g[1][2])%mod;
			ans2=(ans2+g[0][2])%mod;
			for(int k=1;k<=2;k++)tmp[k]=g[1][k],g[1][k]=0;
			for(int k=1;k<=2;k++)g[1][k]=(g[1][k]+1ll*(f[i][j]-1)*g[0][k-1])%mod;
			for(int k=1;k<=2;k++)g[0][k]=(g[0][k]+tmp[k])%mod;
			ans1=(ans1+g[1][2])%mod;
		}
	}
	printf("%lld %lld\n",1ll*C*ans1%mod,1ll*F*ans2%mod);
}
int main(){
	freopen("plant.in","r",stdin),freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
	while(T--){
		work();
	}
	return 0;
} 
