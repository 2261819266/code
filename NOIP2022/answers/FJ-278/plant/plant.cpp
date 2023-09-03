#include<bits/stdc++.h>
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define D(i,j,n)for(register int i=j;i>-n;i--)
#define mod 998244353
#define N 1005
#define ll long long
ll f[N][N],g[N];char s[N][N]; 
int main(){
	freopen("plant.in","r",stdin);freopen("plant.out","w",stdout);
	int T,id;scanf("%d%d",&T,&id);while(T--){
		int n,m,c,ff;scanf("%d%d%d%d",&n,&m,&c,&ff);ll ans1=0,ans2=0;
		F(i,1,n){scanf("%s",s[i]+1);}
		F(i,1,m)f[i][n+1]=0;F(i,1,n)D(j,m,1)if(s[i][j]=='1')f[i][j]=0;else f[i][j]=f[i][j+1]+1;
//		F(i,1,n){
//			F(j,1,m)printf("%d ",f[i][j]);puts("");
//		}
		ll nw,q;F(j,1,m-1){
			memset(g,0,sizeof(g));D(i,n,1)if(s[i][j]=='1')g[i]=0;else g[i]=g[i+1]+1;
			nw=q=0;F(i,1,n){
				if(s[i][j]=='0'){
					if(nw>=2){
						ans1=(ans1+(f[i][j]-1)*(q-f[i-1][j]+1)%mod)%mod;
						ans2=(ans2+(f[i][j]-1)*(q-f[i-1][j]+1)%mod*g[i+1]%mod)%mod;
					}q+=f[i][j]-1;nw++;
				}else nw=q=0;
			}
		}printf("%lld %lld\n",ans1*c,ans2*ff);
	}return 0;
}
