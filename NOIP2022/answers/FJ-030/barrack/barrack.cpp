#include"stdio.h"
#include"time.h"
#include"vector"
#include"algorithm"
#define reg register
#define getchar()(inBuf==lenBuf?lenBuf=(inBuf=Buf)+fread(Buf,1,1<<20,stdin):0,inBuf==lenBuf?EOF:*inBuf++)
char Buf[1<<20],*inBuf,*lenBuf;
template<class T>void read(T&x){reg char ch,f=x=0;while(ch=getchar(),ch<'0'||ch>'9');while(x=x*10+(ch&15),ch=getchar(),ch<='9'&&ch>='0');f?x=-x:0;}
#define mod 1000000007
int n,m;std::vector<int>e[500010],E[500010];
int dfn[500010],low[500010],tm,stk[500010],tp;
int bl[500010],sz[500010],bln,pw[1000010];
void tj(int u,int f){
    dfn[u]=low[u]=++tm,stk[++tp]=u;
    for(reg int v:e[u])if(v!=f){
        if(!dfn[v]){
            tj(v,u);
            low[u]>low[v]?low[u]=low[v]:0;
        }
        else low[u]>dfn[v]?low[u]=dfn[v]:0;
    }
    if(dfn[u]==low[u]){
        sz[++bln]=0;
        do bl[stk[tp]]=bln,++sz[bln];while(stk[tp--]!=u);
    }
}
int dp[500010][2],ans,SZ[500010];
void dfs(int u,int f){
    dp[u][0]=dp[u][1]=SZ[u]=1;
    for(reg int v:E[u])if(v!=f)
        dfs(v,u),dp[u][0]=2ll*dp[u][0]*dp[v][0]%mod,dp[u][1]=dp[u][1]*(2ll*dp[v][0]+dp[v][1])%mod,SZ[u]+=SZ[v];
    dp[u][1]=((dp[u][1]-dp[u][0]+mod)*1ll*pw[sz[u]]+dp[u][0]*1ll*(pw[sz[u]]-1))%mod;
    ans=(ans+1ll*dp[u][1]*pw[u==1?0:bln-SZ[u]-1])%mod;
}
main(){
     freopen("barrack.in","r",stdin);
     freopen("barrack.out","w",stdout);
    read(n),read(m);for(reg int i=1,u,v;i<=m;++i)read(u),read(v),e[u].push_back(v),e[v].push_back(u);
    tj(1,0);
    // for(reg int i=1;i<=n;++i)printf("%d ",bl[i]);
    for(reg int i=1;i<=n;++i)for(reg int j:e[i])if(bl[i]!=bl[j])E[bl[i]].push_back(bl[j]),E[bl[j]].push_back(bl[i]);
    for(reg int i=1;i<=bln;++i)std::sort(E[i].begin(),E[i].end()),E[i].resize(std::unique(E[i].begin(),E[i].end())-E[i].begin());
    pw[0]=1;for(reg int i=1;i<=m;++i)pw[i]=pw[i-1]*2%mod;
    dfs(1,0);
    // printf("%d\n",bln);
    printf("%d\n",ans*1ll*pw[m-bln+1]%mod);
}
