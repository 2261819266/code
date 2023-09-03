#include <bits/stdc++.h>
#define N 10
using namespace std;
int n,m,u,v,ans;
bool c[N],h[N],f[N];
vector<int> g[N],z[N];
void dfs3(int x,int w){
	f[x]=1;
	for(int i=0;i<g[x].size();i++){
		int ch=g[x][i];
		if(!f[ch]&&z[x][i]!=w)
			dfs3(ch,w);
	}
}
void dfs2(int d){
	if(d==m){
		bool flag=0;
		for(int i=0;i<n;i++){
			if(c[i])
				flag=1;
		}
		for(int i=0;i<m;i++){
			if(h[i]) continue;
			for(int j=0;j<n;j++){
				if(!c[j]) continue;
				memset(f,0,sizeof f);
				dfs3(j,i);
				for(int ii=0;ii<n;ii++){
					if(c[ii]&&!f[ii])
						flag=0;
				}
			}
		}
		ans+=flag;
		return;
	}
	h[d]=0;
	dfs2(d+1);
	h[d]=1;
	dfs2(d+1);
}
void dfs1(int d){
	if(d==n){
		dfs2(0);
		return;
	}
	c[d]=0;
	dfs1(d+1);
	c[d]=1;
	dfs1(d+1);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
		z[u].push_back(i);
		z[v].push_back(i);
	}
	dfs1(0);
	cout<<ans;
	return 0;
}
