#include<cstdio>
#define reg register
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAXN 500050
const int M=1e9+7;
long long pw2[MAXN],ans;
int n,m;
int read(){
	reg int s=0,f=1;
	reg char ch;
	for(;(ch=getchar())<'0'||ch>'9';ch=='-'?f=-f:0);
	for(;ch>='0'&&ch<='9';s=(s<<3)+(s<<1)+ch-'0',ch=getchar());
	return s*f;
}
void kotori(){
	n=read(),m=read();
	pw2[0]=1;
	for(reg int i=1;i<=n;i++)pw2[i]=pw2[i-1]*2%M;
	int u,v;
	for(reg int i=1;i<=m;i++)
		u=read(),v=read();
		ans=1ll*n*pw2[n-1]%M;
		for(reg int k=2;k<=n;k++){
			ans=(ans+1ll*(n-k+1)*pw2[n-k]%M*pw2[k-2]%M)%M;
		}
		printf("%lld\n",ans);
	
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int _=1;
	while(_--)kotori();
}
