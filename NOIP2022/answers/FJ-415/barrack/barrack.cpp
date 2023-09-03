#include<bits/stdc++.h>
using namespace std;
inline void dd(int &ss){
	ss=0;
	char ch=getchar();int ff=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ss=ss*10+ch-'0',ch=getchar();
	ss*=ff;	
}
const int N=101,mod=1e9+7;
struct aaa{
	int x,y;
}t[N];
int n,m,yy;
long long ans,dp[1000011],sum[1000011];
int fw[N],ll[N],bb[N],sc[N],pp;
int low[N],dfn[N],tot,qiao[N];
int cnt=1,v[N<<1],h[N],nt[N<<1];
long long ksm(long long a,int b){
	long long anss=1;
	for(;b;b>>=1){
		if(b&1)anss=anss*a%mod;
		a=a*a%mod;
	}
	return anss;
}
void add(int x,int y){
	v[++cnt]=y;
	nt[cnt]=h[x];
	h[x]=cnt;
}
void dfs(int x,int fa){
	low[x]=dfn[x]=++tot;
	for(int i=h[x];i;i=nt[i])
	if(!dfn[v[i]]){
		dfs(v[i],x);
		low[x]=min(low[x],low[v[i]]);
		if(low[v[i]]>low[x])
		qiao[i]=qiao[i^1]=1;
	}
	else if(v[i]!=fa)
	low[x]=min(low[x],dfn[v[i]]);
}
int fid(int x,int y){
	fw[x]=1;
	if(x==y)return 1;
	for(int i=h[x];i;i=nt[i])
	if(!fw[v[i]]){
		if(fid(v[i],y))return ll[i]=ll[i^1]=1;
	}
	return 0;
}
void bl(int u){
	if(u>n){
		int anss=0;
		for(int i=1;i<=cnt;++i)ll[i]=0;
		for(int i=1;i<=n;++i)
		if(bb[i])
		for(int j=i+1;j<=n;++j)
		if(bb[j]&&sc[i]!=sc[j]){
			for(int i=1;i<=pp;++i)fw[i]=0;
			int sb=fid(sc[i],sc[j]);
		}
//		cout<<bb[1]<<' '<<bb[2]<<" "<<bb[3]<<' '<<bb[4]<<'\n';
		for(int i=1;i<=cnt/2;++i)
		if(ll[i*2])--anss;
		anss+=m;
		if(yy)
		ans=(ans+(1<<anss))%mod;
		return ;
	}
	++yy;
	bb[u]=1;
	bl(u+1);
	--yy;
	bb[u]=0;
	bl(u+1);
}
void jc(int x){
	sc[x]=pp;
	for(int i=h[x];i;i=nt[i])
	if(!sc[v[i]]&&!qiao[i])
	jc(v[i]);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	dd(n),dd(m);
	if(n<=16){
		int x,y;
		for(int i=1;i<=m;++i)
		dd(x),dd(y),add(x,y),add(y,x),t[i].x=x,t[i].y=y;
		dfs(1,0);
		for(int i=1;i<=n;++i)
		if(!sc[i])
		++pp,jc(i);
		memset(h,0,sizeof(h));
		cnt=1;
		for(int i=1;i<=m;++i){
			x=t[i].x,y=t[i].y;
			if(sc[x]!=sc[y]){
				add(sc[x],sc[y]),add(sc[y],sc[x]);
			}
		}
		bl(1);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;++i){
		dp[i]=(ksm(2,i-1)+sum[i-1])%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	for(int i=1;i<=n;++i)
	ans=(ans+(ksm(2,n-i)*dp[i])%mod)%mod;
	cout<<ans;
}
