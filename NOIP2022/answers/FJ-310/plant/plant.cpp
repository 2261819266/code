#include<bits/stdc++.h>
#define reg register
#define IL inline
using namespace std;
const int mod=998244353;
int T,ID,n,a[1007][1007],g[1007][1007],h[1007][1007],v[1007][1007],tr[1007];
char s[1007];
IL void Pls(reg int&x,reg int y){x-=(x+=y)>=mod?mod:0;}
IL void upd(reg int x,reg int y){for(;x<=n;x+=x&-x)Pls(tr[x],y);}
IL int w(reg int x){reg int y=0;for(;x;x-=x&-x)Pls(y,tr[x]);return y;}
int main(){
	freopen("plant.in","r",stdin),freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&ID);
	for(reg int m,C,F,AnsC,AnsF;~--T;){
		scanf("%d%d%d%d",&n,&m,&C,&F),AnsC=AnsF=0;
		for(reg int i=1,j;i<=n;++i)for(scanf("%s",s),j=0;j<m;++j)a[i][j+1]=((s[j]-'0')^1);
		for(reg int i=n;i;--i)g[i][m]=0;
		for(reg int j=m-1;j;--j)for(reg int i=n;i;--i)if(a[i][j]&&a[i][j+1])g[i][j]=g[i][j+1]+1;
		for(reg int j=m;j;--j)h[n][j]=0;
		for(reg int i=n-1;i;--i)for(reg int j=m;j;--j)if(a[i][j]&&a[i+1][j])h[i][j]=h[i+1][j]+1;
		for(reg int j=m;j;--j)v[1][j]=0;
		for(reg int i=2;i<=n;++i)for(reg int j=m;j;--j)if(a[i][j]&&a[i-1][j])v[i][j]=v[i-1][j]+1;
		
		//for(reg int i=1;i<=n;++i,puts(""))for(reg int j=1;j<=m;++j)printf("%d ",g[i][j]);
		//for(reg int i=1;i<=n;++i,puts(""))for(reg int j=1;j<=m;++j)printf("%d ",h[i][j]);
		//for(reg int i=1;i<=n;++i,puts(""))for(reg int j=1;j<=m;++j)printf("%d ",v[i][j]);
		
		for(reg int j=1;j<m;++j){
			for(reg int i=n;i;--i)tr[i]=0;
			for(reg int i=n;i;--i)upd(i,g[i][j]);
			for(reg int i=n,k;i>2;--i)
				if(g[i][j]&&v[i][j]>1){
					k=1ll*g[i][j]*(w(i-2)-w(i-v[i][j]-1)+mod)%mod,Pls(AnsC,k);
					if(h[i][j]){
						Pls(AnsF,1ll*h[i][j]*k%mod);
					}
				}
		}
		AnsC=1ll*AnsC*C%mod,AnsF=1ll*AnsF*F%mod;
		printf("%d %d\n",AnsC,AnsF);
	}
	return 0;
}
