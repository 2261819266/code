#include<bits/stdc++.h>
using namespace std;
#define maxn 2001
#define inf 99999999999999999
#define ll long long
#define mod 998244353
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
	return x*f;
}
ll T,id,n,m,c,f,num[maxn][maxn],epa[maxn][maxn],sum[maxn][maxn],ansc,ansf;
string now;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--){
		memset(epa,0,sizeof(epa));
		memset(sum,0,sizeof(sum));
		ansc=0,ansf=0;
		n=read(),m=read(),c=read(),f=read();
		for(ll i=1;i<=n;i++){
			cin>>now;
			for(ll j=0;j<m;j++) num[i][j+1]=(now[j]-'0');
		}
		for(ll i=1;i<=n;i++){
			if(!num[i][m]) epa[i][m]=1;
			for(ll j=m-1;j>=1;j--){
				if(!num[i][j]) epa[i][j]=epa[i][j+1]+1;
			}
		}
		for(ll i=1;i<=m;i++){
			if(!num[n][i]) sum[i][n]=1;
			for(ll j=n-1;j>=1;j--){
				if(!num[j][i]) sum[i][j]=sum[i][j+1]+1;
			}
		}
		for(ll i=1;i<=m;i++){
			ll poi=0;
			while(poi<n){
				while(poi<n&&!sum[i][poi+1]) poi++;
				if(poi==n) break;
				for(ll j=poi+1;j<=poi+sum[i][poi+1];j++){
					for(ll l=j+2;l<=poi+sum[i][poi+1];l++){
						ansc=(ansc+(epa[j][i]-1)*(epa[l][i]-1)%mod)%mod;
						if(l!=(poi+sum[i][poi+1])){
							ansf=ansf+(epa[j][i]-1)*(epa[l][i]-1)%mod*(poi+sum[i][poi+1]-l)%mod;
							ansf=ansf%mod;
						}
					}
				}
				poi=(poi+sum[i][poi+1])%mod;
			}
		}
		printf("%lld %lld",ansc*c%mod,ansf*f%mod);
	}
	return 0;
}
