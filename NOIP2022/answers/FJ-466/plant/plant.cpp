#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define mod 998244353
#define ll long long
using namespace std;
ll ma[1050][1050];
ll lin_c[1050][1050];
ll str_c[1050][1050];
ll coun_c[1050][1050],coun_f[1050][1050];
ll sum_c[1050][1050],sum_f[1050][1050];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ll t,id;
	cin>>t>>id;
	while(t--){
		ll n,m,c,f;
		char ch;
		cin>>n>>m>>c>>f;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				cin>>ch;
				if(ch=='1') ma[i][j]=1; 
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=m;j>=1;j--){
				if(ma[i][j]) lin_c[i][j]=0;
				else lin_c[i][j]=lin_c[i][j+1]+1;
			}
		}
		for(ll i=n;i>=1;i--){
			for(ll j=1;j<=m;j++){
				if(ma[i][j]) str_c[i][j]=0;
				else str_c[i][j]=str_c[i+1][j]+1;
			}
		}
		for(ll i=n;i>=1;i--){
			for(ll j=1;j<=m;j++){
				if(ma[i][j]) continue;
				coun_c[i][j]=(lin_c[i][j]-1)%mod;
				coun_f[i][j]=((str_c[i][j]-1)*(lin_c[i][j]-1))%mod;
				sum_c[i][j]=(sum_c[i+1][j]+coun_c[i][j])%mod;
				sum_f[i][j]=(sum_f[i+1][j]+coun_f[i][j])%mod;
			}
		}
		ll ans_c=0,ans_f=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				if(ma[i][j]) continue;
				ans_c=(ans_c+(coun_c[i][j]*(sum_c[i][j]-coun_c[i+1][j]-coun_c[i][j])))%mod;
				ans_f=(ans_f+(coun_c[i][j]*(sum_f[i][j]-coun_f[i+1][j]-coun_f[i][j])))%mod;
			}
		}
		cout<<((ans_c*c)%mod)<<' '<<((ans_f*f)%mod)<<endl;
	}
	return 0;
}
