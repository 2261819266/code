#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e3+10;
const int MOD=998244353;

int T,id,n,m,c,f,l[M][M],h[M][M],cntc,cntf,suml[M][M],sumf[M][M];
bool gar[M][M];
char cc;

signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld %lld\n",&T,&id);
	for(int t=1;t<=T;t++){
		memset(l,0,sizeof(l));
		memset(h,0,sizeof(h));
		memset(gar,0,sizeof(gar));
		cntc=0,cntf=0;
		scanf("%lld %lld %lld %lld\n",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%c",&cc);
				if(cc=='1')gar[i][j]=1;
			}
			scanf("%c",&cc);
		}
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				l[i][j]=l[i][j+1]+1;
				h[i][j]=h[i+1][j]+1;
				if(gar[i][j]){
					l[i][j]=0;
					h[i][j]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(l[i][j]>0){
					suml[i][j]=(suml[i-1][j]+l[i][j]-1)%MOD;
					sumf[i][j]=(sumf[i-1][j]+(l[i][j]-1)*(n-i+1))%MOD;
				}else{
					suml[i][j]=suml[i-1][j];
					sumf[i][j]=sumf[i-1][j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!gar[i][j]){
					if(l[i][j]>=2 and h[i][j]>=3){
						cntc=(cntc+(l[i][j]-1)*(suml[i+h[i][j]-1][j]-suml[i+1][j]))%MOD;
						if(h[i][j]>=4)cntf=(cntf+(l[i][j]-1)*(sumf[i+h[i][j]-2][j]-sumf[i+1][j]-(suml[i+h[i][j]-2][j]-suml[i+1][j])*(n-(i+h[i][j]-2)))%MOD)%MOD;
					}
				}
			}
		}
		printf("%lld %lld\n",cntc*c,cntf*f);
	}
	return 0;
}

