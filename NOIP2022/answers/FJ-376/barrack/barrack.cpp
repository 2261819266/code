#include<cstdio>
#define re register
#define il inline
const int N=3e3+3;
int n,m,ind=1,hd[N],to[N],nxt[N],ans,cut;
il void add(int u,int v){return ++ind,nxt[ind]=hd[u],to[ind]=v,hd[u]=ind,void();}
bool tag_1[N],tag_2[N],vis[N];
void dfs_3(int u)
{
	vis[u]=true;
	for(re int i=hd[u],v;v=to[i];i=nxt[i])
		if(((i^cut)&&((i^1)&&cut))&&!vis[v]) dfs_3(v);
	return;
}
il void calc()
{
	for(re int i=2;i<=ind;++i)
		if(!tag_2[i])
		{
			cut=i;
			for(re int i=1;i<=n;++i) vis[i]=false;
			for(re int i=1;i<=n;++i)
				if(tag_1[i])
				{
					dfs_3(i);
					break;
				}
			for(re int i=1;i<=n;++i) if(tag_1[i]&&!vis[i]) return;
		}
	++ans;
	return;
}
void dfs_2(int o)
{
	if(o==ind+1) return calc();
	return tag_2[o]=tag_2[o^1]=1,dfs_2(o+2),tag_2[o]=tag_2[o^1]=0,dfs_2(o+2),void();
}
void dfs_1(int o,bool cnt)
{
	if(o==n+1) return cnt?dfs_2(2):void();
	return tag_1[o]=1,dfs_1(o+1,cnt|1),tag_1[o]=0,dfs_1(o+1,cnt);
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(re int i=1,u,v;i<=m;++i) scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs_1(1,0);
	return printf("%d",ans),0;
}
