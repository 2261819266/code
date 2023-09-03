#include<cstdio>
using namespace std;
const int Mod=998244353;
int T,ll,n,m,C,F,t[1005][1005],f[1005][1005],ansc,ansf;
bool a[1005][1005];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&ll);
	if(ll==1){while(T--)printf("0 0\n");return 0;}
	while(T--){
		scanf("%d%d%d%d",&n,&m,&C,&F);
		for(int i=1;i<=n;++i){
			char ch=getchar();
			while((ch^'1')&&(ch^'0'))ch=getchar();
			for(int j=1;j<=m;++j)a[i][j]=ch^48,ch=getchar();
		}
		for(register int i=1;i<=m;++i)for(register int j=n;j>=1;--j)if(a[j][i])t[j][i]=0;else t[j][i]=t[j+1][i]+1;
		for(register int i=1;i<=n;++i)for(register int j=m;j>=1;--j)if(a[i][j])f[i][j]=0;else f[i][j]=f[i][j+1]+1;
		if(C)for(register int i=1;i<=n;++i)for(register int j=i+2;j<=n;++j)for(register int k=1;k<=m;++k)if(t[i][k]>=j-i+1)ansc=(ansc+f[i][k+1]*f[j][k+1])%Mod;
		if(F)for(register int i=1;i<=n;++i)for(register int j=i+2;j<=n;++j)for(register int k=1;k<=m;++k)if(t[i][k]>=j-i+1)ansf=(ansf+(t[j+1][k]*f[i][k+1]*f[j][k+1])%Mod)%Mod;
		printf("%d %d\n",ansc*C,ansf*F);
	}
	return 0;
}/*
1 0
4 3 1 1
001
010
000
000
*/