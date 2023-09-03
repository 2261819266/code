#include<bits/stdc++.h>
#define reg register
#define IL inline
using namespace std;
int T,n,h[307],id[307][5],cnt;
queue<int>q[5];
pair<int,int>p[607];
vector<int>Ans[1207];
IL void Insert(reg int w){
	reg int u;
	while(!q[1].empty()){
		u=q[1].front(),q[1].pop();
		if(h[u]==1){
			p[w]={u,1},++h[u],id[u][h[u]]=w;
			Ans[++cnt].push_back(1),Ans[cnt].push_back(u);
			return;
		}
	}
	while(!q[0].empty()){
		u=q[0].front(),q[0].pop();
		if(!h[u]){
			if(q[0].empty()){
				q[0].push(u);
				break;
			}
			p[w]={u,0},++h[u],q[1].push(u),id[u][h[u]]=w;
			Ans[++cnt].push_back(1),Ans[cnt].push_back(u);
			return;
		}
	}
	for(reg int i=n;i;--i){
		if(h[i]==2){
			u=i;
			p[w]={u,2},++h[u],id[u][h[u]]=w;
			Ans[++cnt].push_back(1),Ans[cnt].push_back(u);
		}
	}
	
}
IL void Del(reg int w){
	
	reg int u=p[w].first;
	
	if(!p[w].second&&h[u]>1){
		for(reg int i=h[u];i;--i)--p[id[u][i]].second;
		for(reg int i=1;i<h[u];++i)id[u][i]=id[u][i+1];
	}
	
	--h[u];
	if(h[u]<2)q[h[u]].push(u);
	p[w]={-1,-1};
}
int main(){
	freopen("meow.in","r",stdin),freopen("meow.out","w",stdout);
	scanf("%d",&T);
	for(reg int m,k;~--T;){
		scanf("%d%d%d",&n,&m,&k);
		for(reg int i=1;i<=n;++i)q[0].push(i),h[i]=0,id[i][1]=id[i][2]=0;
		for(reg int i=1;i<=k;++i)p[i]={-1,-1};
		for(reg int i=1;i<=(m<<1);++i)Ans[i].clear();
		cnt=0;
		for(reg int a;~--m;){
			scanf("%d",&a);
			if(!~p[a].first){
				Insert(a);
			}
			else{
				if(p[a].second==h[p[a].first]-1){
					Ans[++cnt].push_back(1),Ans[cnt].push_back(p[a].first);
				}
				else{
					reg int u;
					while(!q[0].empty()){
						u=q[0].front(),q[0].pop();
						if(!h[u]){
							break;
						}
					}
					Ans[++cnt].push_back(1),Ans[cnt].push_back(u);
					Ans[++cnt].push_back(2),Ans[cnt].push_back(u),Ans[cnt].push_back(p[a].first);
				}
				Del(a);
			}
		}
		printf("%d\n",cnt);
		for(reg int i=1;i<=cnt;++i,puts(""))for(reg auto j:Ans[i])printf("%d ",j);
	}
	return 0;
}
