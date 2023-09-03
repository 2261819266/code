#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
char cc;
long long mmap[1010][1010];
long long dp1[1010][1010],dp2[1010][1010];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
	while(T--){
		int n,m,c,f;
		long long ansc=0;
		long long ansf=0;
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		memset(mmap,0,sizeof(mmap));
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cc=' ';
				while(cc!='0'&&cc!='1')scanf("%c",&cc);
				mmap[i][j]=cc-'0';
			}
		}
		if(c==0&&f==0){
			printf("0 0\n");
			continue;
		}
		for(int i=n;i>0;i--){
			for(int j=m;j>0;j--){
				if(mmap[i][j]==0){
					dp1[i][j]=dp1[i][j+1]+1;
					dp2[i][j]=dp2[i+1][j]+1;
				}else dp1[i][j]=dp2[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(mmap[i][j]==1)continue;
				if(dp1[i][j]<=1)continue;
				if(dp2[i][j]<=2)continue;
				for(int ii=2;ii<dp2[i][j];ii++){
					if(dp1[ii+i][j]<=1)continue;
					ansc=(ansc+((1ll*(dp1[i][j]-1)%M)*(dp1[ii+i][j]-1)%M)%M)%M;
					if(ii<dp2[i][j]-1)ansf=(ansf+((1ll*(dp1[i][j]-1)%M)*((dp1[ii+i][j]-1)%M)*(dp2[ii+i+1][j]%M))%M)%M;
				}
			}
		}
		printf("%lld %lld\n",c*ansc,f*ansf);
	}
	return 0;
}
