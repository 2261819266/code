#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long
#define mod 998244353
using namespace std;
ll n,m;
ll vc,vf;
ll T;
char x[1001];
ll a[1001][1001],h[1001][1001],ds[1001][1001],dx[1001][1001],sumc[1001][1001],sumf[1001][1001];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ll id=0;
	cin>>T>>id;
	while(T--){
		memset(a,0,sizeof(a));
		memset(h,0,sizeof(h));
		memset(ds,0,sizeof(ds));
		memset(sumc,0,sizeof(sumc));
		memset(sumf,0,sizeof(sumf));
		ll ansc=0,ansf=0;
		cin>>n>>m>>vc>>vf;
		for(ll i=1;i<=n;i++){
			cin>>x;
			for(int j=0;j<m;j++){
				a[i][j+1]=x[j]-'0';
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=m;j>=1;j--){
				if(a[i][j]==0) h[i][j]=h[i][j+1]+1;
				if(h[i][j]>0) sumc[i][j]=(sumc[i-1][j]+h[i][j]-1)%mod;
			}
		}
		for(ll i=n;i>=1;i--){
			for(ll j=1;j<=m;j++){
				if(a[i][j]==0) ds[i][j]=ds[i+1][j]+1;
				if(ds[i][j]>0&&h[i][j]>0)sumf[i][j]=(sumf[i+1][j]+((ds[i][j]-1)*(h[i][j]-1))%mod)%mod;
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				if(h[i][j]>0&&ds[i][j]>2){
					ansc=(ansc+(h[i][j]-1)*(sumc[i+ds[i][j]-1][j]-sumc[i+1][j]+mod)%mod)%mod;
					ansf=(ansf+(h[i][j]-1)*(sumf[i+2][j]-sumf[i+ds[i][j]][j]+mod)%mod)%mod;
				}
			}
		}
		cout<<(ansc*vc)%mod<<" "<<(ansf*vf)%mod<<" "<<endl;
	}
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/