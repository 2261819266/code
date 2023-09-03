//NOIP2022 RP++!
//in:match.in
//out:match.out
//Let us go!
#include <iostream>
#include <cstdio>
#define ll unsigned long long
using namespace std;
ll MOD;
ll f[3003][3003];
ll d[3003][3003];
ll p[3003][3003];
ll dp[3003][3003];
ll pre[3003][3003];
int id,n;
int a[3003];
int b[3003];
int q,l,r;
int mx(int x114514,int x1919810){
	return (x114514>x1919810?x114514:x1919810);
}
ll power(ll x,ll y){
	if(y==0) return 1;
	ll res=1;
	while(y){
		if(y&1) res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	MOD=power(2,64)-1;
	cin>>id>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<n;i++){
		d[i][i+1]=a[i]*b[i+1];
		p[i][i+1]=b[i]*a[i+1];
		dp[i][i+1]=mx(d[i][i+1],p[i][i+1]);
	}
	for(int len=3;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			d[i][j]=mx(d[i][j-1],a[i]*b[j]);
			p[i][j]=mx(p[i][j-1],b[i]*a[j]);
			dp[i][j]=mx(d[i][j],p[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i]=a[i]*b[i];
		pre[i][i]=f[i][i];
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			f[i][j]=mx(f[i][i],mx(f[i+1][j],dp[i][j]));
			pre[i][j]=(pre[i][j-1]+f[i][j])%MOD;
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		int ans=0;
		for(int i=l;i<=r;i++){
			ans=(ans+pre[i][r]-pre[i][l-1]+MOD)%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//20pts
