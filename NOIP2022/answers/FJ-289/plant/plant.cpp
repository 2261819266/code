#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005,Mod=998244353;
ll n,m,c,f,mxr[N][N],mxlen[N][N],sum[N][N];
ll ansc,ansf;
char s[N][N];
vector<ll> k[N];
ll cntc(ll l,ll r,ll j){
//	ll aaa=sum[r][j]-sum[l-1][j],rt=0;
//	rt=aaa*aaa;
////	for(int i=l;i<=r;i++){
////		rt=(rt+mxlen[i][j]*aaa)%Mod;
////	}
//	for(int i=l;i<=r;i++){
//		rt=(rt-mxlen[i][j]*mxlen[i][j])%Mod;
//	}
//	rt/=2;
//	for(int i=l;i<=r-1;i++){
//		rt=(rt-mxlen[i][j]*mxlen[i+1][j])%Mod;
//	}
////	cout << l << " " << r << " " << j << " " << rt << endl;
//	return (rt+Mod)%Mod;
	ll rt=0;
	for(register int i=l+2;i<=r;i++){
		rt=(rt+(sum[i-2][j]-sum[l-1][j])*mxlen[i][j]%Mod)%Mod;
	}
	return (rt+Mod)%Mod;
}
ll cntf(ll l,ll r,ll j){
	ll rt=0;
	for(register int i=l+2;i<=r;i++){
		rt=(rt+(sum[i-2][j]-sum[l-1][j])*mxlen[i][j]%Mod*(r-i)%Mod)%Mod;
	}
	return (rt+Mod)%Mod;
}
void val(){
	memset(mxr,0,sizeof(mxr));
	memset(mxlen,0,sizeof(mxlen));
	memset(sum,0,sizeof(sum));
	ansc=0;
	ansf=0;
	scanf("%d%d%d%d",&n,&m,&c,&f);
	for(int i=1;i<=n;i++) vector<ll>().swap(k[i]);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout << s[i][j];
//		cout << endl;
//	}
	for(int i=1;i<=n;i++){
		for(register int j=1;j<=m;j++){
			if(s[i][j]=='1') k[i].push_back(j);
		}
		k[i].push_back(m+1);
	}
	for(int i=1;i<=n;i++){
		int p=0;
		for(register int j=1;j<=m;j++){
			mxr[i][j]=k[i][p];
			if(mxr[i][j]==j) mxr[i][j]++;
			if(s[i][j]=='1') p++;
			mxlen[i][j]=mxr[i][j]-j-1;
		}
	}
	for(int j=1;j<=m;j++){
		for(register int i=1;i<=n;i++) sum[i][j]=(sum[i-1][j]+mxlen[i][j])%Mod;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout << mxlen[i][j] << " ";
//		cout << endl;
//	}
//	cout << endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout << sum[i][j] << " ";
//		cout << endl;
//	}
//	cout << endl;
	if(c==1){
	for(int j=1;j<=m;j++){
		int l=1;
		for(register int i=1;i<=n;i++){
			if(s[i][j]=='1'){
				ansc=(ansc+cntc(l,i-1,j))%Mod;
				l=i+1;
				i++;
			}
		}
		if(l!=n+1){
			ansc=(ansc+cntc(l,n,j))%Mod;
		}
	}
	}
	if(f==1){
	for(int j=1;j<=m;j++){
		int l=1;
		for(register int i=1;i<=n;i++){
			if(s[i][j]=='1'){
				ansf=(ansf+cntf(l,i-1,j))%Mod;
				l=i+1;
				i++;
			}
		}
		if(l!=n+1){
			ansf=(ansf+cntf(l,n,j))%Mod;
		}
	}
	}
	cout << ansc << " " << ansf << endl;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,id;
	cin >> t >> id;
	while(t--) val();
	return 0;
}
