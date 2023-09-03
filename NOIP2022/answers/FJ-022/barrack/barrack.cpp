#include<bits/stdc++.h>
#define spa putchar(' ')
#define ent putchar('\n')
using namespace std;
typedef long long ll;
inline void read(int &x){
	char c=getchar();
	int f=1;x=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	x*=f;
}
inline void write(ll x){
	char F[65];
	int cnt=0;
	if(x<0){putchar('-');x=-x;}
	do{F[++cnt]=x%10+'0';x/=10;}while(x);
	while(cnt)putchar(F[cnt--]);
}
const int mod=1e9+7,maxn=5e5+5,maxm=1e6+5;
int inv[maxn],p2[maxm],n,m,fst[maxn],cnt,low[maxn],dfn[maxn],x[maxm],y[maxm],tot,c[maxn],fstc[maxn],siz[maxn];
bool bri[maxm],f[maxn],vis[maxn],A=1;
ll ans,tmp;
int eg[maxn];
struct node{
	int to,nxt;
}e[maxm<<1];
void add(int u,int v){
	e[++cnt]=(node){v,fst[u]};
	fst[u]=cnt;
}
node ec[maxm<<1];
void addc(int u,int v){
	ec[++cnt]=(node){v,fstc[u]};
	fstc[u]=cnt;
}
void tarjan(int p){
	dfn[p]=++cnt;
	low[p]=cnt;
	for(int i=fst[p];i;i=e[i].nxt ){
		if(!dfn[e[i].to]){
			tarjan(e[i].to );
			low[p]=min(low[p],low[e[i].to ]);
			if(low[e[i].to ]>dfn[p]){
				bri[i]=1;
				if(i&1)bri[i+1]=1;
				else bri[i-1]=1;
			}
		}
		else low[p]=min(low[p],dfn[e[i].to ]);
	}
}
void dfs(int p){
	c[p]=tot;
	siz[tot]++;
	for(int i=fst[p];i;i=e[i].nxt ){
		if(c[e[i].to ]==0&&bri[i]==0)dfs(e[i].to );
	}
}

void dfsc(int p,int F){
	for(int i=fstc[p];i;i=e[i].nxt ){
		if(ec[i].to!=F&&f[ec[i].to ]==0){
			dfsc(ec[i].to ,p);
			f[ec[i].to ]=1;
			if((vis[ec[i].to ]&vis[p])||eg[ec[i].to ])eg[p]+=eg[ec[i].to ]+1;
		}
	}
	if(p==1){
		tmp=p2[m-eg[1]];
	}
}
void brut(int p,ll val){
	if(p>tot){
		for(int i=1;i<=tot;i++)eg[tot]=0;
		dfsc(1,0);
		ans=(ans+(val*tmp%mod))%mod;
		return ;
	}
	vis[p]=1;
	brut(p+1,1ll*(p2[siz[p]]-1)*val%mod);
	vis[p]=0;
	brut(p+1,val);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	read(n);
	read(m);
	if(n==1){
		putchar('1');
		return 0;
	}
	p2[0]=1;
	for(int i=1;i<=m;i++)p2[i]=p2[i-1]*2%mod;
	for(int i=1;i<=m;i++){
		read(x[i]);
		read(y[i]);
		if(abs(x[i]-y[i])!=1)A=0;
		add(x[i],y[i]);
		add(y[i],x[i]);
	}
	if(A){
		ans=(1ll*n*(n-1)/2)%mod;
		ans=ans*p2[n-2]%mod;
		write(ans);
		return 0;
	}
	cnt=0;
	tarjan(1);
	for(int i=1;i<=n;i++){
		if(!c[i]){
			tot++;
			dfs(i);
		}
	}
	cnt=0;
	for(int i=1;i<=m;i++){
		if(c[x[i]]!=c[y[i]]){
			addc(c[x[i]],c[y[i]]);
			addc(c[y[i]],c[x[i]]);
		}
	}
	brut(1,1);
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
