#include<bits/stdc++.h>
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define D(i,j,n)for(register int i=j;i>-n;i--)
#define N 500005
#define mod 1000000007
#define ll long long
int a[N],mp[20][20],n,vis[N];ll er[N],p[N],q[N];
int main(){
	freopen("barrack.in","r",stdin);freopen("barrack.out","w",stdout);
	int m;scanf("%d%d",&n,&m);/*if(n<=16){
		
		F(s,1,(1<<n)-1){
			F(i,1,n){
				
			}
		}
	}*/
	er[0]=1;F(i,1,n)er[i]=er[i-1]*2%mod;
	ll ans=er[m]*n%mod;
	ans=(ans+n*(n-1)/2%mod*er[m-1]%mod)%mod;printf("%lld",ans);
}
