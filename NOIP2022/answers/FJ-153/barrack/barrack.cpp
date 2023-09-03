#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
const int N=500005,M=1500005;
const int mod=1000000007;
typedef long long ll;
std::vector<int> to[N],to1[N];
int low[N],dfn[N],sum=0,stk[N],top=0,cnt=0;
int col[N],sz[N],sz1[N],sz2[N];
int pw[M],f[N];
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
void tarjan(int x,int f){
	dfn[x]=low[x]=++sum;stk[++top]=x;
	for(auto y:to[x]){
		if(!dfn[y]){
			tarjan(y,x);
			low[x]=std::min(low[x],low[y]);
			if(low[y]>dfn[x]){
				cnt++;
				while(top&&stk[top]!=y){
					int z=stk[top];col[z]=cnt;top--;
				}
				col[y]=cnt;top--;
			}
		}
		else if(y!=f) low[x]=std::min(low[x],dfn[y]);
	} 
}
int ans=0,n,m;
void dfs(int x,int fa){
	int res=1;
	sz2[x]=sz1[x];
	if(to1[x].size()==1&&x!=1) f[x]=sub(pw[sz1[x]+sz[x]],pw[sz1[x]]); 
	for(auto y:to1[x]){
		if(y==fa) continue;
		dfs(y,x);sz2[x]+=sz2[y]+1;
		res=(ll)res*add(f[y],(ll)pw[sz2[y]]*2%mod)%mod;
		ans=add(ans,(ll)f[y]*pw[m-sz2[y]-1]%mod);
	}
//	printf("%d %d %d %d\n",x,res,sz[x],sz1[x]);
	if(to1[x].size()>1||x==1) f[x]=sub((ll)res*pw[sz1[x]+sz[x]]%mod,pw[sz2[x]]);
//	printf("%d %d %d %d %d %d\n",x,f[x],sz2[x],sz1[x],sz[x],res);
//	printf("%d %d %d\n",(ll)res*pw[sz1[x]+sz[x]]%mod,pw[sz2[x]],sub((ll)res*pw[sz1[x]+sz[x]]%mod,pw[sz2[x]]));
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		to[x].emplace_back(y);to[y].emplace_back(x);
	}
	pw[0]=1;
	for(int i=1;i<=m+n;i++) pw[i]=2LL*pw[i-1]%mod;
	tarjan(1,0);
	for(int i=1;i<=n;i++) col[i]++;
	for(int i=1;i<=n;i++) sz[col[i]]++;
//	for(int i=1;i<=n;i++) printf("%d\n",col[i]);
//	printf("%d\n",cnt);
//	for(int i=cnt+1;i>=1;i--) sz[i]=sz[i-1];
//	puts("OK");
	for(int i=1;i<=n;i++){
		for(auto y:to[i]) if(y>i){
			if(col[y]==col[i]) sz1[col[y]]++;
			else to1[col[y]].emplace_back(col[i]),to1[col[i]].emplace_back(col[y]);
		}
	}
	if(cnt==0) return 0*printf("%d\n",sub(pw[n+m],pw[m]));
	dfs(1,0);
	ans=add(ans,f[1]);
	printf("%d\n",ans);
}
