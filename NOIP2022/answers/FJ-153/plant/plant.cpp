#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
const int N=1005;
const int mod=998244353;
typedef long long ll;
char mp[N][N];
int f[N][N],g[N][N],h[N][N],h1[N][N];
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
void solve(){
	int n,m,c,F;scanf("%d%d%d%d",&n,&m,&c,&F);
	int ansc=0,ansf=0;
	for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--) {
			if(mp[i][j]=='1') f[i][j]=0;
			else f[i][j]=f[i][j+1]+1;
		}
	} 
	for(int j=1;j<=m;j++){
		for(int i=n;i>=1;i--){
			if(mp[i][j]=='1') g[i][j]=0;
			else g[i][j]=g[i+1][j]+1;
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++) h[i][j]=add(h[i-1][j],f[i][j]-1);
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++) h1[i][j]=add(h1[i-1][j],(ll)(f[i][j]-1)*(n-i+1)%mod);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) if(mp[i][j]=='0'){
			int r=i+g[i][j]-1;
			if(r<=i+1) continue;
			ansc=add(ansc,(ll)(f[i][j]-1)*sub(h[r][j],h[i+1][j])%mod);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) if(mp[i][j]=='0'){
			int r=i+g[i][j]-1;
			if(r<=i+1) continue;
			ansf=add(ansf,(ll)(f[i][j]-1)*sub(h1[r][j],h1[i+1][j])%mod);
			ansf=sub(ansf,(ll)(f[i][j]-1)*sub(h[r][j],h[i+1][j])%mod*(n-r)%mod);
		}
	}
	ansf=sub(ansf,ansc); 
	printf("%d %d\n",ansc*c,ansf*F);
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;scanf("%d%d",&T,&id);
	while(T--) solve();
}
