#include<bits/stdc++.h>
using namespace std;
#define int long long 
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9')f=(c!='-'),c=getchar();
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	if(f)return x;return -x;
}
const int maxn=1050,mod=998244353;
int dn[maxn][maxn],rt[maxn][maxn],up[maxn][maxn],G[maxn][maxn];
int get(){
	char c=getchar();
	while(c!='0'&&c!='1')c=getchar();
	return c=='1';
}
int n,m,c,f,ans1,ans2;
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),id=read();while(T--){
		n=read(),m=read(),c=read(),f=read(),ans1=0,ans2=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)G[i][j]=get();
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--)if(!G[i][j]){
				if(j!=m&&!G[i][j+1])rt[i][j]=rt[i][j+1]+1;
				else rt[i][j]=0;
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++)if(!G[i][j]){
				up[i][j]=rt[i][j];
				if(i!=1&&!G[i-1][j])up[i][j]+=up[i-1][j];
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=n;i>=1;i--)if(!G[i][j]){
				if(i!=n&&!G[i+1][j])dn[i][j]=dn[i+1][j]+1;
				else dn[i][j]=0;
			}
		}
		for(int i=3;i<=n;i++)for(int j=1;j<=m;j++)if(!G[i][j]){
			if(G[i-1][j]||G[i-2][j])continue;
			ans1=(ans1+up[i-2][j]*rt[i][j]%mod)%mod;
			ans2=(ans2+up[i-2][j]*rt[i][j]%mod*dn[i][j]%mod)%mod;
		}
		printf("%lld %lld\n",ans1*c%mod,ans2*f%mod);
	}return 0;
}
