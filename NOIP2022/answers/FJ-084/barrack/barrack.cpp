#include<bits/stdc++.h>
#define ll long long 
#define N 1000010
#define P 1000000007
#define GC getchar()
using namespace std;
ll re(){
	ll s=0,b=1; char c=GC;
	while(c>'9'||c<'0'){if(c=='-')b=-b; c=GC;}
	while(c<='9'&&c>='0'){s=(s<<1)+(s<<3)+(c^48); c=GC;}
	return s*b;
}
void ks(ll s){
	if(s<0){s=-s; putchar('-');} 
	if(s>=10)ks(s/10); 
	putchar((s%10)|48);
}
int n,m,tt=1,he[N],x,y,df[N],lo[N],odf,zh[N],zd,nd[N];
int nn,tu,hf[N],dsi[N],dbs[N],sudbs[N],vi[N];
ll cf[N<<1],ans,dp[N][2];
struct A{int ne,to;}b[N<<1];
struct B{int ne,to;}c[N<<2];
void ad(int x,int y){
	b[++tt].to=y; b[tt].ne=he[x]; he[x]=tt;
	b[++tt].to=x; b[tt].ne=he[y]; he[y]=tt;
}
void ae(int x,int y){
	c[++tu].to=y; c[tu].ne=hf[x]; hf[x]=tu;
	c[++tu].to=x; c[tu].ne=hf[y]; hf[y]=tu;
}
void tar(int x,int f){
	df[x]=lo[x]=++odf; zh[++zd]=x;
	for(int i=he[x]; i; i=b[i].ne){
		if(i==(f^1))continue;
		int v=b[i].to; 
		if(!df[v]){tar(v,i); lo[x]=min(lo[x],lo[v]);}
		 else lo[x]=min(lo[x],df[v]);
	}
	if(df[x]==lo[x]){
		nn++; 
		while(zh[zd]!=x){
			nd[zh[zd]]=nn;; zd--; dsi[nn]++;
		} nd[x]=nn; zd--; dsi[nn]++;
	}
}
void dfs(int x,int f){
	sudbs[x]=dbs[x]; vi[x]=1;
	dp[x][0]=cf[dbs[x]];
	dp[x][1]=(cf[dsi[x]]+P-1)%P;
	dp[x][1]=dp[x][1]*cf[dbs[x]]%P;
	//cout<<x<<' '<<dp[x][0]<<' '<<dp[x][1]<<endl;
	for(int i=hf[x]; i; i=c[i].ne){
		int v=c[i].to; if(v==f||vi[v])continue; 
		dfs(v,x);
		ans+=(dp[v][1]*cf[m-sudbs[v]-1])%P; ans%=P;
		ll S1=dp[x][1]*dp[v][0]*2ll%P;
		ll S2=dp[x][1]*dp[v][1]%P;
		ll S3=dp[x][0]*dp[v][1]%P;
		dp[x][1]=(S1+S2+S3)%P;
		dp[x][0]=dp[x][0]*dp[v][0]*2ll%P;
		sudbs[x]+=sudbs[v]+1; 
	}
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=re(),m=re(); cf[0]=1;
	for(int i=1; i<=m*2; i++)
	 cf[i]=(cf[i-1]*2ll)%P;
	for(int i=1; i<=m; i++){
		x=re(),y=re(); ad(x,y);
	} tar(1,0); 
	for(int i=1; i<=n; i++){
		for(int j=he[i]; j; j=b[j].ne){
			int v=b[j].to;
			if(nd[v]!=nd[i])ae(nd[v],nd[i]);
			 else dbs[nd[i]]++;
		}
	} 
	for(int i=1; i<=nn; i++)dbs[i]=dbs[i]/2; 
	dfs(1,0); ans=(ans+dp[1][1])%P;
	//for(int i=1; i<=nn; i++)cout<<dp[i][0]<<' '<<dp[i][1]<<endl; 
	ks(ans);
}
