#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1005
#define P 998244353
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
ll n,m,C,F,a[N][N],r[N][N],d[N][N],f[N][N],g[N][N];
void solve(){
	n=read();m=read();C=read();F=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch=getchar();while(ch!='0'&&ch!='1')ch=getchar();
			a[i][j]=ch-'0';r[i][j]=d[i][j]=f[i][j]=g[i][j]=0;
		}
		for(int j=m-1;j>=1;j--)if(!a[i][j]&&!a[i][j+1])r[i][j]=r[i][j+1]+1;
	}
	for(int j=1;j<=m;j++){
		for(int i=n-1;i>=1;i--)if(!a[i][j]&&!a[i+1][j])d[i][j]=d[i+1][j]+1;
		if(!a[n][j])f[n][j]=r[n][j];
		for(int i=n-1;i>=1;i--)if(!a[i][j]){
			f[i][j]=(r[i][j]+f[i+1][j])%P;
			g[i][j]=(r[i][j]*d[i][j]%P+g[i+1][j])%P;
		}
	}
	ll ansC=0,ansF=0;
	for(int i=1;i<=n-2;i++){
		for(int j=1;j<=m;j++){
			if(!a[i+1][j])ansC=(ansC+r[i][j]*f[i+2][j]%P)%P;
			if(!a[i+1][j])ansF=(ansF+r[i][j]*g[i+2][j]%P)%P;
		}
	}
	printf("%lld %lld\n",ansC*C,ansF*F);
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	for(int tt=read(),id=read();tt--;solve());
	return 0;
}
