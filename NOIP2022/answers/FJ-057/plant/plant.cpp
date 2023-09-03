#include <iostream>
#include <cstring>
#include <cstdio>
#define mod 998244353
#define MAXX 1010
using namespace std;
char ar[MAXX][MAXX];
int dp[MAXX][MAXX];
int ri[MAXX][MAXX];
int rea[MAXX][MAXX];
int su[MAXX][MAXX];
int dow[MAXX][MAXX];
//ÑùÀý3³ôµôÁ¦(±¯) 
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	cin >> T >> id;
	while(T--){
		memset(ar,0,sizeof(ar));
		memset(dp,0,sizeof(dp));
		memset(ri,0,sizeof(ri));
		memset(rea,0,sizeof(rea));
		memset(su,0,sizeof(su));
		memset(dow,0,sizeof(dow));
		int n,m,c,f;
		cin >> n >> m >> c >> f;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin >> ar[i][j];
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				ri[i][j]=ri[i][j+1]+1;
				if(ar[i][j]=='1') ri[i][j]=0;
				rea[i][j]=max(ri[i][j]-1,0);
				su[i][j]=su[i-1][j]+rea[i][j];
				if(ar[i][j]=='1') su[i][j]=0;
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++){
				dow[i][j]=dow[i+1][j]+1;
				if(ar[i][j]=='1') dow[i][j]=0;
			}
		}
		int ans1=0,ans2=0;
		for(int i=3;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ar[i-1][j]=='1') continue;
				dp[i][j]=1ll*rea[i][j]*su[i-2][j]%mod;
				ans1=(ans1+dp[i][j])%mod;
				if(i<n) ans2=(ans2+1ll*dow[i+1][j]*dp[i][j]%mod)%mod;
			}
		}
		cout << c*ans1 << ' ' << f*ans2 << endl;
	}
	return 0;
}
