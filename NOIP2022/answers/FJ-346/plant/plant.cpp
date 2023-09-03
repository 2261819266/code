#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1050,mod=998244353;
int n,m,c,f,sumx[N][N],sumy[N][N],sumc[N][N],sumf[N][N],ansc,ansf;
bool mapp[N][N];
char s[N];
int dfsx(int x,int y){
	if(mapp[x][y]||x>n)
		return 0;
	sumx[x][y]=dfsx(x+1,y);
	return sumx[x][y]+1;
}
int dfsy(int x,int y){
	if(mapp[x][y]||y>m)
		return 0;
	sumy[x][y]=dfsy(x,y+1);
	return sumy[x][y]+1;
}
int dfsc(int x,int y){
	if(sumx[x][y]==-1)
		return 0;
	sumc[x][y]=dfsc(x+1,y)+sumy[x][y];
	return sumc[x][y];
}
int dfsf(int x,int y){
	if(sumx[x][y]==-1)
		return 0;
	sumf[x][y]=((LL)dfsf(x+1,y)+(LL)sumy[x][y]*sumx[x][y])%mod;
	return sumf[x][y];
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,idd;
	scanf("%d%d",&T,&idd);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
//		if(c==0&&f==0){
//			puts("0 0");
//			continue ;
//		}
		memset(mapp,0,sizeof(mapp));
		for(int i=1;i<=n;++i){
			scanf("%s",s+1);
			for(int j=1;j<=m;++j)
				mapp[i][j]=(s[j]=='1');
		}
//		for(int i=1;i<=n;++i){
//			for(int j=1;j<=m;++j)
//				printf("%d ",mapp[i][j]);
//			puts("");
//		}
		memset(sumx,0xff,sizeof(sumx));
		for(int i=1;i<=n;++i)
			for(int j=1,t;j<=m;++j)
				if(sumx[i][j]==-1&&!mapp[i][j])
					t=dfsx(i,j);
		memset(sumy,0xff,sizeof(sumy));
		for(int i=1;i<=n;++i)
			for(int j=1,t;j<=m;++j)
				if(sumy[i][j]==-1&&!mapp[i][j])
					t=dfsy(i,j);
		memset(sumc,0xff,sizeof(sumc));
		for(int i=1;i<=n;++i)
			for(int j=1,t;j<=m;++j)
				if(sumc[i][j]==-1&&!mapp[i][j])
					t=dfsc(i,j);
		memset(sumf,0xff,sizeof(sumf));
		for(int i=1;i<=n;++i)
			for(int j=1,t;j<=m;++j)
				if(sumf[i][j]==-1&&!mapp[i][j])
					t=dfsf(i,j);
//		for(int i=1;i<=n;++i)
//			for(int j=1;j<=m;++j)
//				printf("sumc/sumf/sumx/sumy[%d][%d]=%d/%d/%d\n",i,j,sumc[i][j],sumf[i][j],sumx[i][j],sumy[i][j]);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(!mapp[i][j]&&sumx[i][j]>=2){
					ansc=((LL)ansc+(LL)sumy[i][j]*sumc[i+2][j])%mod;
					ansf=((LL)ansf+(LL)sumy[i][j]*sumf[i+2][j])%mod;
				}
		printf("%d %d\n",ansc*c,ansf*f);
	}
	return 0;
}
