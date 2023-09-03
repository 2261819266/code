#include<bits/stdc++.h>
#define mod 1000000007
#define MAXN 500001
using namespace std;
typedef long long ll;
int n,m;
vector<int> G[MAXN];
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v;
	bool sub1flag=1;
    for(int i=1;i<=m;i++)
	 {
	 	scanf("%d%d",&u,&v);
	 	G[u].push_back(v);
	 	G[v].push_back(u);
	 	if(abs(u-v)==1&&(u==i||v==i))continue;
	 	sub1flag=0;

     }
     ll ans=n*(1<<m)%mod;
	 	 //printf("%lld",ans);
	 if(m==n-1&&sub1flag)
      ans=ans+(m*(m+1)/2)*(1<<(m-1))%mod;
	printf("%lld",ans);
	 return 0;
}
