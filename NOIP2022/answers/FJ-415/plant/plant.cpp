#include<bits/stdc++.h>
using namespace std;
const int N=1011,mod=998244353;
int id,t,c,f,n,m;
int mp[N][N],sum[N][N],sh[N][N],dp[N][N],xi[N][N];
long long ans,anss;
string s;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t>>id;
	while(t--){
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;++i){
			cin>>s;
			for(int j=0;j<m;++j)
			if(s[j]=='0')
			mp[i][j+1]=0;
			else
			mp[i][j+1]=1;
		}
		
		for(int i=1;i<=n;++i)
		dp[i][m+1]=-1;
		
		for(int j=1;j<=m;++j)
		sh[0][j]=-1;
		
		for(int j=1;j<=m;++j)
		xi[n+1][j]=-1;
		
		for(int i=1;i<=n;++i)
		for(int j=m;j>=1;--j)
		if(mp[i][j]) dp[i][j]=-1;
		else dp[i][j]=dp[i][j+1]+1;
		
		for(int j=1;j<=m;++j)
		for(int i=1;i<=n;++i)
		sum[i][j]=sum[i-1][j]+dp[i][j];
		
		for(int j=1;j<=m;++j)
		for(int i=1;i<=n;++i)
		if(mp[i][j]) sh[i][j]=-1;
		else sh[i][j]=sh[i-1][j]+1;
		
		for(int j=1;j<=m;++j)
		for(int i=n;i>=1;--i)
		if(mp[i][j]) xi[i][j]=-1;
		else xi[i][j]=xi[i+1][j]+1;
		
		for(int i=3;i<=n;++i)
		for(int j=1;j<=m;++j)
		if(sh[i][j]>=2){
			ans=(ans+dp[i][j]*(sum[i-2][j]-sum[i-sh[i][j]-1][j])%mod)%mod;
			anss=(anss+xi[i][j]*dp[i][j]%mod*(sum[i-2][j]-sum[i-sh[i][j]-1][j])%mod)%mod;
		}
		cout<<ans*c<<' '<<anss*f<<'\n';
		ans=anss=0;
	}
}
