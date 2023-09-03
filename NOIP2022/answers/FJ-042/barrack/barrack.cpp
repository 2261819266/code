#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
const int MAXN=5e5+5;
const int MAXM=2e6+2;
const ll MOD=1e9+7;
int head[MAXN],ecnt=0;
struct edge{
	int to,nxt;
	edge(){
		nxt=-1;
	}
}E[MAXM];
void addedge(int a,int b){
	ecnt++;
	E[ecnt].to=b;
	E[ecnt].nxt=head[a];
	head[a]=ecnt;
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	ll tmp=x;
	x=y;
	y=tmp-(a/b)*y;
}
ll mod_inverse(ll a){
	ll x,y;
	exgcd(a,MOD,x,y);
	return (MOD+x%MOD)%MOD;
}
ll pow2[MAXN];
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n=read(),m=read();
	bool f=1;
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
		if(f&&abs(u-v)!=1){
			f=0;
		}
	}
	if(f&&m==n-1){
		ll ans=0;
		pow2[0]=1;
		for(int i=1;i<=n;i++){
			pow2[i]=pow2[i-1]*2%MOD;
		}
		for(int len=1;len<=m;len++){
			for(int i=1;i<=n-len;i++){
				ans+=pow2[len-1]*pow2[m-len]%MOD;
			}
		}
		write(ans);
		return 0;
	}
	return 0;
}
