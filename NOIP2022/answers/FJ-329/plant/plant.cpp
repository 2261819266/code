#include <bits/stdc++.h>
using namespace std;
const int p=998244353;
int T,idx,n,m,c,f,R[1005][1005],D[1005][1005],Rs[1005][1005],Ds[1005][1005],Vc,Vf;
char Mp[1005][1005];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&idx);
	while (T--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) scanf(" %c",&Mp[i][j]);
		for (int i=1;i<=n;i++) for (int j=m,cnt=0;j;j--){
			if (Mp[i][j]=='0') R[i][j]=cnt++;
			else cnt=0;
		}
		for (int j=1;j<=m;j++) for (int i=n,cnt=0;i;i--){
			if (Mp[i][j]=='0') D[i][j]=cnt++,Rs[i][j]=Rs[i+1][j]+R[i][j],Ds[i][j]=Ds[i+1][j]+R[i][j]*D[i][j];
			else cnt=0;
		}
//		for (int i=1;i<=n;i++,puts("")) for (int j=1;j<=m;j++) printf("(%d,%d,%d,%d) ",R[i][j],D[i][j],Rs[i][j],Ds[i][j]);
		if (c>0) for (int i=1;i<=n-2;i++) for (int j=1;j<m;j++) if (Mp[i][j]=='0') Vc=(Vc+1ll*R[i][j]*(Rs[i][j]-R[i][j]-R[i+1][j])%p)%p;
		if (f>0) for (int i=1;i<=n-3;i++) for (int j=1;j<m;j++) if (Mp[i][j]=='0') Vf=(Vf+1ll*R[i][j]*(Ds[i][j]-R[i][j]*D[i][j]-R[i+1][j]*D[i+1][j]-R[n][j]*D[n][j])%p)%p;
		printf("%d %d\n",Vc,Vf),Vc=Vf=0,memset(Rs,0,sizeof Rs),memset(Ds,0,sizeof Ds),memset(R,0,sizeof R),memset(D,0,sizeof D);
	}
	return 0;
}
