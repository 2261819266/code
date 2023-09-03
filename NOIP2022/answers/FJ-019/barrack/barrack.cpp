#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5e5+5;
const ll p=1e9+7;

vector<int>a[N];

int dp[N];

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=(dp[i-1]*3%p+2)%p;
	}
	printf("%lld",dp[n]);
	return 0;
}
