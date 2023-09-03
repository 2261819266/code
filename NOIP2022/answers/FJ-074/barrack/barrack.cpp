#include<cstdio>
#define P 1000000007
#define M 2000003
#define N 500005
using namespace std;
typedef long long i64;
struct doge{int next,to;bool vis,cut;}e[M],E[M];
int n,m;
int I[N],Rt,msiz;
bool ischain;
int dfn[N],low[N],Stk[N],top,scc[N],scnt;
i64 siz[N],Siz[N],ans;
bool f[N];
int h[N],N_E,H[N];
inline void addd(int from,int to,doge e[],int h[]){
	e[++N_E].next=h[from];h[from]=N_E;
	e[N_E].to=to;
	return;
}
inline int Fr(){
	int res=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res;
}
inline i64 Q_P(i64 base,int x){
	i64 res=1;
	while(x){
		if(x&1)res=res*base%P;
		base=base*base%P;
		x>>=1;
	}
	return res;
}
inline void Tarjan(int x){
	dfn[x]=low[x]=++N_E;
	Stk[++top]=x;f[x]=true;
	for(int i=h[x];i;i=e[i].next){
		int v=e[i].to;
		if(e[i].vis)continue;
		e[i].vis=e[i^1].vis=true;
		if(!dfn[v]){Tarjan(v);if(low[v]<low[x])low[x]=low[v];}
		else if(f[v]&&dfn[v]<low[x])low[x]=dfn[v];
		if(low[v]>dfn[x])e[i].cut=e[i^1].cut=true;
	}
	if(dfn[x]==low[x]){
		while(x!=Stk[top])f[Stk[top--]]=false;
		f[Stk[top--]]=false;
	}
	return;
}
inline void dfs(int x){
	scc[x]=scnt;siz[scnt]++;
	for(int i=h[x];i;i=e[i].next){
		int v=e[i].to;
		if(e[i].cut)continue;
		if(!scc[v])dfs(v);
	}
	return;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int _,__;
	n=Fr();m=Fr();N_E=1;
	for(int i=1;i<=m;i++){
		_=Fr();__=Fr();
		addd(_,__,e,h);addd(__,_,e,h);
	}
	N_E=0;
	Tarjan(1);
	for(int i=1;i<=n;i++)
		if(!scc[i]){
			++scnt,dfs(i);
			if(siz[scnt]>msiz)msiz=siz[scnt];
		}
	N_E=0;ischain=true;
	for(int i=1;i<=m;i++)
		if(e[i<<1].cut){
			_=scc[e[i<<1].to],__=scc[e[i<<1|1].to];
			addd(_,__,E,H);
			addd(__,_,E,H);
			I[_]++;I[__]++;
			if(I[_]>2||I[__]>2)ischain=false;
		}
	if(ischain){
		for(int i=1;i<=scnt;i++)if(I[_]<2){Rt=i;break;}
		int x=Rt;f[x]=true;Siz[1]=siz[x];
		for(int i=2;i<=scnt;i++){
			for(int j=H[x];j;j=E[j].next){
				int v=E[j].to;
				if(f[v])continue;
				x=v;f[x]=true;
				Siz[i]=Siz[i-1]+siz[x];
				break;
			}
		}
		if(msiz==1){printf("%lld",(Q_P(2,scnt-2)*((scnt*(scnt-1))>>1)+Q_P(2,scnt-1)*scnt)%P);return 0;}
		for(int l=1;l<=scnt;l++){
			for(int r=l+1;r<=scnt;r++){
				i64 tmp=Q_P(2,m+l-r);
				tmp=tmp*Q_P(2,Siz[r-1]-Siz[l])%P;
				tmp=tmp*(Q_P(2,Siz[r]-Siz[r-1])-1+P)%P;
				tmp=tmp*(Q_P(2,Siz[l]-Siz[l-1])-1+P)%P;
				//printf("%lld\n",tmp);
				ans=(ans+tmp)%P;
			}
			ans=(ans+((Q_P(2,siz[l])-1+P)*Q_P(2,m))%P)%P;
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
