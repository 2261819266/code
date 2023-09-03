#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=1010;
int read(){
	int ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret;
}
int T,id,n,m,c,f;
int a[N][N];
ll len[N][N];
ll sum[N][N];
ll sum2[N][N];
int nxt[N][N];
void work(){
	ll ans1,ans2;
	ans1=0;
	ans2=0;
	n=read();
	m=read();
	c=read();
	f=read();
	char ch;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ch=getchar();
			while(ch!='0'&&ch!='1')ch=getchar();
			a[i][j]=(ch=='1');
		}
	}
	for(int i=1;i<=n;i++){
		a[i][m+1]=1;
		len[i][m]=0;
		for(int j=m-1;j>=1;j--){
			if(a[i][j]==0&&a[i][j+1]==0){
				len[i][j]=len[i][j+1]+1;
			}else{
				len[i][j]=0;
			}
		}
	}
	for(int j=1;j<=m;j++){
		a[n+1][j]=1;
		nxt[n+1][j]=0;
		for(int i=n;i>=1;i--){
			if(a[i][j]==0&&a[i+1][j]==0){
				nxt[i][j]=nxt[i+1][j]+1;
			}else{
				nxt[i][j]=0;
			}
		}
	}
	for(int j=1;j<=m;j++){
		sum[0][j]=0;
		sum2[0][j]=0;
		for(int i=1;i<=n;i++){
			sum[i][j]=sum[i-1][j]+len[i][j];
			sum[i][j]%=mod;
			sum2[i][j]=sum2[i-1][j]+sum[i][j];
			sum2[i][j]%=mod;
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1,p;i<=n;i++){
			if(a[i][j]==1||a[i+1][j]==1)continue;
			p=i+nxt[i][j];
			if(p<=i+1)continue;
			ans1=(ans1+len[i][j]*(sum[p][j]-sum[i+1][j])%mod)%mod;
			ans1=(ans1%mod+mod)%mod;
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1,p;i<=n;i++){
			if(a[i][j]==1||a[i+1][j]==1||a[i+2][j]==1)continue;
			p=i+nxt[i][j];
			if(p<i+3)continue;
			ans2=(ans2+len[i][j]*(sum2[p-1][j]-sum2[i+1][j]-sum[i+1][j]*(p-i-2)%mod)%mod)%mod;
			ans2=(ans2%mod+mod)%mod;
		}
	}
	ans1=(ans1%mod+mod)%mod;
	ans2=(ans2%mod+mod)%mod;
	printf("%lld %lld\n",ans1*c,ans2*f);
	return ;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();
	id=read();
	while(T--){
		work();
	}
	return 0;
}
