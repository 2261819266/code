#include<bits/stdc++.h>
using namespace std;
const int N=1005,mod=998244353;
int T,id,n,m,c,f,a[N][N],h[N][N],l[N][N];
long long ansc,ansf;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	register int i,j,k;
	for(scanf("%d%d",&T,&id);T--;){
		ansc=ansf=0;
		memset(h,0,sizeof h);
		memset(l,0,sizeof l);
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				scanf("%1d",&a[i][j]);
		if(!c&&!f){
			puts("0 0");
			continue;
		}
		for(i=n;i;--i)
			for(j=m;j;--j)
				if(!a[i][j]){
					h[i][j]=h[i][j+1]+1;
					l[i][j]=l[i+1][j]+1;
				}
		for(j=1;j<=m;++j)
			for(i=1;i<=n;++i)
				if(l[i][j]>=3)
					for(k=i+2;k<=n;++k){
						if(a[k][j])break;
						ansc=(ansc+(h[i][j]-1)*(h[k][j]-1))%mod;
						ansf=(ansf+1ll*(h[i][j]-1)*(h[k][j]-1)*(l[k][j]-1))%mod;
					}
		printf("%d %d\n",c*ansc,f*ansf);
	}
	return 0;
}
