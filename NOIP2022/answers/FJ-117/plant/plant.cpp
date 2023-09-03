#include<bits/stdc++.h>
#define N 1100
#define mod 998244353
#define L long long 
using namespace std;
L T,id,n,m,c,f,lin[N][N],row[N][N],a[N][N],sumc[N][N],sumf[N][N],ansc,ansf;
char s[N][N];
void init(){
	ansc=0,ansf=0;
	memset(sumc,0,sizeof(sumc));
	memset(sumf,0,sizeof(sumf));
	memset(row,0,sizeof(row));
	memset(lin,0,sizeof(lin));
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&T,&id);
	while(T--){
		init();
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=s[i][j]-'0';
		for(int i=1;i<=n;i++){
			L now=0;
			for(int j=m;j>0;j--){
				if(!a[i][j])lin[i][j]=now;
				now++;
				if(a[i][j])now=0;
			}
		}
		for(int j=1;j<=m;j++){
			L now=0;
			for(int i=n;i>0;i--){
				if(!a[i][j])row[i][j]=now;
				now++;
				if(a[i][j])now=0;
			}
		}
		for(int j=1;j<=m;j++)for(int i=1;i<=n;i++)sumc[j][i]=(sumc[j][i-1]+lin[i][j])%mod,sumf[j][i]=(sumf[j][i-1]+lin[i][j]*row[i][j]%mod)%mod;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(row[i][j]>1)ansc=(ansc+lin[i][j]*(sumc[j][i+row[i][j]]-sumc[j][i]-lin[i+1][j]+2*mod)%mod)%mod;
				if(row[i][j]>2)ansf=(ansf+lin[i][j]*(sumf[j][i+row[i][j]]-sumf[j][i]-lin[i+1][j]*row[i+1][j]%mod+2*mod)%mod)%mod;
			}
		}
		printf("%lld %lld\n",ansc*c%mod,ansf*f%mod);
	}
	return 0;
}
