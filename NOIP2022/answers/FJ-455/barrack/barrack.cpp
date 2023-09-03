#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1,mod=1e9+7; 
int n,m,u,v,e[N<<1][2],ans;
vector<int>g[N];
bool vis[N],tis[N<<1],t[21][21],f[21][21],b[21][21],ff[21][21];
void dfs0(int s){
	if(s>m){
		int p[21]={},cnt=0;
		for(int i=1;i<=n;++i)
			if(vis[i])p[++cnt]=i;
		for(int i=1;i<=m;++i){
			memcpy(ff,t,sizeof ff);
			//f[e[i][0]][e[i][1]]=f[e[i][1]][e[i][0]]=0;
			//b[e[i][1]][e[i][0]];
			if(b[e[i][1]][e[i][0]]==1)
				memcpy(ff,f,sizeof ff);
			else{
				ff[e[i][0]][e[i][1]]=ff[e[i][1]][e[i][0]]=0;
				for(int a=1;a<=n;++a){
					for(int b=1;b<=n;++b){
						for(int c=1;c<=n;++c){
							ff[a][b]=(ff[a][b]||(ff[a][c]&&ff[c][b]));//putchar('p');
						}
					}
				}
			}
			for(int j=1;j<=cnt;++j)
				for(int k=j+1;k<=cnt;++k)
					if(!ff[p[j]][p[k]])
						return;
		}
		ans=(ans+1)%mod;
		/*
		for(int i=1;i<=n;++i)
			printf("%d ",vis[i]);
		puts("");
		for(int i=1;i<=m;++i)
			printf("%d ",tis[i]);
		printf("\n\n");
		*/
		return;
	}
	dfs0(s+1);
	b[e[s][0]][e[s][1]]=b[e[s][1]][e[s][0]]=1;
	tis[s]=1;
	dfs0(s+1);
	tis[s]=0;
	b[e[s][0]][e[s][1]]=b[e[s][1]][e[s][0]]=0;
}
void dfs(int s,bool was){
	if(s>n){
		if(was)dfs0(1);
		return;
	}
	dfs(s+1,was);
	vis[s]=1;
	dfs(s+1,1);
	vis[s]=0;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		e[i][0]=u,e[i][1]=v;
		t[u][v]=t[v][u]=1;
	}
	memcpy(f,t,sizeof f);
	for(int a=1;a<=n;++a){
		for(int b=1;b<=n;++b){
			for(int c=1;c<=n;++c){
				f[a][b]=(f[a][b]||(f[a][c]&&f[c][b]));//putchar('p');
			}
		}
	}
	/*
	for(int a=1;a<=n;++a){
		for(int b=1;b<=n;++b){
			printf("%d ",f[a][b]);
		}puts("");
	}
	*/
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
