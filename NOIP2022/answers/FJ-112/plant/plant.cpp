#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,P=998244353;
int T,id,n,m,c,f,r[N][N],C,F;
char a[N][N];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	for(scanf("%d%d",&T,&id);T--;){
		scanf("%d%d%d%d",&n,&m,&c,&f),C=F=0;
		for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
		for(int i=1;i<=n;++i)for(int j=m;j;--j)r[i][j]=(j==m||a[i][j]=='1'||a[i][j+1]=='1')?0:r[i][j+1]+1;
		for(int i=1;i<=m;++i){
			int res1=0,res2=0,d=-1;
			for(int j=n;j;--j){
				if(a[j][i]=='1')res1=res2=0,d=-1;
				else{
					C=(C+1ll*r[j][i]*res1)%P,F=(F+1ll*r[j][i]*res2)%P;
					res1=(res1+r[j+1][i])%P,res2=(res2+1ll*r[j+1][i]*max(d,0))%P,++d;
				}
			}
		}
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[i][j]=r[i][j]=0;
		printf("%d %d\n",c*C,f*F);
	}
	return 0;
}
