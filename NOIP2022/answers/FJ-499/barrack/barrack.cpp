#include<bits/stdc++.h>
using namespace std;

long long n,m,u,v,g[10010][10010];
long long mod=pow(10,9)+7,ans=0;
long long dfs(long long k){
	if(k==1) return m;
	else if(k==2){
		long long sum=0;
		for(int i=m-1;i>=1;i--){
			sum=(sum+i)%mod;
		}
		return sum;
	}else{
		long long sum=m-1;
		return (sum*dfs(k-1))%mod;
	}
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		g[u][v]=1;
		g[v][u]=1;
	}
	for(int i=1;i<=m;i++){
		ans=(ans+dfs(i))%mod;
	}
	long long cnt=ans;
	for(int i=1;i<=n;i++){
		ans=(ans+cnt)%mod;
	}
	cout<<(ans+n)%mod;
	return 0;
} 
