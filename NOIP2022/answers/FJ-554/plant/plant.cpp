#include <bits/stdc++.h>
#define N 1005
#define mod 998244353
using namespace std;
int t,id,n,m,c,f;
long long dp[3][N][N],ans[2];
bool a[N][N];
char q1;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--){
		cin>>n>>m>>c>>f;
		ans[0]=ans[1]=0;
		memset(dp,0,sizeof dp);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>q1;
			a[i][j]=q1-'0';
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=m-2;j>=0;j--){
			if(a[i][j]||a[i][j+1]) continue;
			dp[0][i][j]=dp[0][i][j+1]+1;
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(a[i][j]||a[i+1][j]) continue;
			dp[2][i][j]=dp[2][i+1][j]+1;
		}
	}
	for(int i=2;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]||a[i-1][j]||a[i-2][j])
				continue;
			dp[1][i][j]=dp[0][i-2][j]+dp[1][i-1][j];
		}
	}
	/*
	for(int ii=0;ii<3;ii++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cout<<dp[ii][i][j]<<' ';
			puts("");
		}
		puts("");
	}
	*/
	if(c){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j])
					continue;
				ans[0]=(ans[0]+dp[0][i][j]*dp[1][i][j])%mod;
			}
		}
	}
	if(f){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j])
					continue;
				ans[1]=(ans[1]+dp[0][i][j]*dp[1][i][j]%mod*dp[2][i][j])%mod;
			}
		}
	}
	cout<<ans[0]<<' '<<ans[1]<<endl;
	}
	return 0;
}
