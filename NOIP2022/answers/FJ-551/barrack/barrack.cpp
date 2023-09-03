#include<iostream>
using namespace std;
const long long mod=1e9+7;
int vis[500001];
int C(int a,int b){
	if(a==0||a==b) return 1;
	int sum=1;
	for(int i=1;i<=a;i++) sum*=(b-i+1);
	return sum;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	long long ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		vis[u]++,vis[v]++;
	}
	for(int i=1;i<=n;i++) if(vis[i]==1){
		int res=0;
		for(int j=0;j<n;j++) res+=C(j,n-1);
		ans+=(1<<n)*res;
		ans%=mod;
		ans+=(1<<(n-1));
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}

