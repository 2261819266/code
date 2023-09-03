#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const long long mod=998244353;
int T,n,m,c,f,id;
int mp[N][N];
long long sum[N][N][2],sumc[N][N],sumf[N][N];//0 right  1 down
char mm[N],ch;
long long ansc,ansf;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin >> T >> id;
	for(int i=1;i<=T;i++){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		ch=getchar();
		ansc=ansf=0;
		for(int i=1;i<=n;i++){
			scanf("%s",mm);
			for(int j=1;j<=n;j++){
				mp[i][j]=mm[j-1]-'0';
				sum[i][j][0]=sum[i][j][1]=sumc[i][j]=sumf[i][j]=0;
			}
		}
		if(c==0&&f==0){
			printf("0 0\n");
			continue;
		}
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				if(mp[i][j]==1) sum[i][j][0]=sum[i][j][1]=0;
				else {
					
					if(mp[i][j+1]==1) sum[i][j][0]=0;
					else sum[i][j][0]=sum[i][j+1][0]+1;
					
					if(mp[i+1][j]==1) sum[i][j][1]=0;
					else sum[i][j][1]=sum[i+1][j][1]+1;
				}
				if(i==n) sum[i][j][1]=0;
				if(j==m) sum[i][j][0]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(mp[i][j]==1) sumc[i][j]=sumf[i][j]=0;
				else{
					sumc[i][j]=(sumc[i-1][j]+sum[i][j][0])%mod;
					sumf[i][j]=(sumf[i-1][j]+sum[i][j][1]*sum[i][j][0])%mod;
				}
			}
		}
		long long resc,resf;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				resc=resf=0;
				if(mp[i][j]||!sum[i][j][0]||(sum[i][j][1]<2)) continue;
				resc=(resc+sumc[i+sum[i][j][1]][j]+mod-sumc[i+1][j])%mod;
				resf=(resf+sumf[i+sum[i][j][1]][j]+mod-sumf[i+1][j])%mod;
				ansc=(ansc+1LL*sum[i][j][0]*resc)%mod;
				ansf=(ansf+1LL*sum[i][j][0]*resf)%mod;
			}
		}
		printf("%lld %lld\n",(c*ansc)%mod,(f*ansf)%mod);
	}
	return 0;
}
