#include<bits/stdc++.h>

using namespace std;

const int N =1005,mod = 998244353;
int n,m,s[N][N],b[N][N],ansc,e[N][N],ansf,p[N][N];
char g[N][N];
int main(){
	int T,id,C,F;
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d%d%d%d%d",&T,&id,&n,&m,&C,&F);
	for(int i=1;i<=n;++i){
		scanf("%s",g[i]+1);
		s[i][m+1]=0;
	}
	for(int i=1;i<=n;++i)
		for(int j=m;j>=1;--j){
			if(g[i][j]=='0'){
				s[i][j]=s[i][j+1]+1;
			}else{
				s[i][j]=0;
			}
		}
	for(int i=1;i<=n;++i)
		for(int j=m;j>=1;--j)if(s[i][j])--s[i][j];
	for(int j=1;j<=m;++j)
		for(int i=1;i<=n;++i){
			if(g[i][j]=='0'){
				b[i][j]=b[i-1][j]+1;
				e[i][j]=e[i-1][j]+s[i][j];
			}else{
				b[i][j]=0;
				e[i][j]=0;
			}
		}
	for(int j=1;j<=m;++j)
		for(int i=n;i>=1;--i){
			if(g[i][j]=='0'){
				p[i][j]=p[i+1][j]+1;
			}else p[i][j]=0;
		}
	for(int i=3;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(b[i][j]>=3){
				ansc=(ansc+1ll*s[i][j]*e[i-2][j]%mod)%mod;
				if(i!=n){
					if(g[i+1][j]=='0')
						ansf=(ansf+1ll*s[i][j]*e[i-2][j]%mod*p[i+1][j]%mod)%mod;
				}
			}
		}
	printf("%d %d",ansc*C,ansf*F);
	return 0;
}
