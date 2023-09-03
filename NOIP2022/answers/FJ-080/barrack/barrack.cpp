#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,x[1000010],y[1000010],fa[1000010];
ll m,l[210][210],f[1000010],ans;
int find(int x){
	if(x!=fa[x]) return fa[x]=find(fa[x]);
	else return x; 
}
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	if(yy==xx) return;
	fa[xx]=yy;
}
ll power(ll a,ll b){
	ll ans=1ll,base=a;
	while(b){
		if(b&1) ans=ans*base%mod;
		base=base*base%mod;
		b>>=1ll;
	} return ans%mod;
}
ll cont(ll x){
	ll s=0;
	while(x){
		if(x&1) s++;
		x>>=1ll;
	} return s;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) fa[j]=j;
		for(int j=1;j<=m;j++){
			if(j!=i) merge(x[j],y[j]);
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(find(j)!=find(k)){
					l[j][k]|=(1ll<<(i-1));
					l[k][j]|=(1ll<<(i-1));
				}
			}
		}
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))) continue;
			f[i|(1<<(j-1))]=f[i];
			for(int k=1;k<=n;k++){
				if(i&(1<<(k-1))){
					f[i|(1<<(j-1))]|=l[k][j];
				}
			}
		}
	}
	for(int i=1;i<(1<<n);i++){
		ans=(ans+power(2ll,m-cont(f[i]))%mod)%mod;
	}
	cout<<ans;
}
