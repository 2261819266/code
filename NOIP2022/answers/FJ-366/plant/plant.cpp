#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010;
const int mod=998244353;
int n,m,C,F;
int a[N][N],f[N][N];
int g[N];
ll ansc,ansf,qz[N];
char s[N];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&C,&F);
		ansc=ansf=0;
		for(int i=1;i<=n;++i){
			scanf("%s",s+1);
			for(int j=1;j<=m;++j) a[i][j]=s[j]-'0';
			f[i][m+1]=0;
			for(int j=m;j;--j) f[i][j]=a[i][j]?0:f[i][j+1]+1;
		}
//		for(int i=1;i<=n;++i)
//		{
//			for(int j=1;j<=m;++j) printf("%d ",f[i][j]);
//			puts("");
//		}
		for(int j=1,fi=0;j<m;++j){
//			printf("j=%d\n",j);
			for(int i=1;i<=n;++i)
			{
				if(a[i][j])
				{
					qz[fi]=0;
					if(fi) qz[fi-1]=0;
					for(int w=fi+1;w<i;++w){
//						printf("g[%d]=%d\n",w,g[w]);
						ansc=(ansc+(w==1?0:qz[w-2])*g[w]%mod)%mod;
						ansf=(ansf+((w==1?0:qz[w-2])*g[w]%mod)*(i-w-1)%mod)%mod;
						qz[w]=(qz[w-1]+g[w])%mod;
					}
					fi=i;
				}
				else
					g[i]=f[i][j]-1;
			}
			if(fi!=n){
				qz[fi]=0;
				if(fi) qz[fi-1]=0;
				for(int w=fi+1;w<=n;++w){
//					printf("g[%d]=%d    ",w,g[w]);
					ansc=(ansc+(w==1?0:qz[w-2])*g[w]%mod)%mod;
//					printf("%d\n",((w==1?0:qz[w-2])*g[w]%mod));
//					printf("ansf+=%d\n",((w==1?0:qz[w-2])*g[w]%mod)*(n-w)%mod);
					ansf=(ansf+((w==1?0:qz[w-2])*g[w]%mod)*(n-w)%mod)%mod;
//					printf("ansf=%d\n",ansf);
					qz[w]=(qz[w-1]+g[w])%mod;
				}
			}
//			printf("ansc=%d ansf=%d\n",ansc,ansf);
		}
		printf("%lld %lld\n",ansc*C%mod,ansf*F%mod);
	}
	return 0;
}
