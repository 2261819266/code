#include<bits/stdc++.h>
using namespace std;
int first[51],nxt[51],to[51],js,ans,n,m,bcj[17],mb;
bool a[21],b[51],qg[51];
void add(int x,int y){
	to[++js]=y;
	nxt[js]=first[x];
	first[x]=js;
	to[++js]=x;
	nxt[js]=first[y];
	first[y]=js;
}
void dfs(int x){
	bcj[mb]=min(bcj[mb],bcj[x]);
	for(int i=first[x];i;i=nxt[i]){
		int u=to[i];
		if(qg[u]&&(b[(i+1)/2])){
			qg[u]=false;
			dfs(u);
			qg[u]=true;
		}
	}
}
void pdwork(){
	for(int i=1;i<=n;i++){
		bcj[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(a[i]){
			mb=i;
			memset(qg,true,sizeof(qg));
			qg[i]=false;
			dfs(i);
		}
	}
	int ltk=-1;
	bool flag=true;
	for(int i=1;flag&&i<=n;i++){
		if(a[i]){
			if(ltk==-1){
				ltk=bcj[i];
			}
			else{
				if(ltk!=bcj[i]){
					flag=false;
				}
			}
		}
	}
	if(flag){
		ans=(ans+1)%1000000007;
	}
}
void mgb(int x){
	if(x==m+1){
		pdwork();
		return;
	}
	b[x]=false;
	mgb(x+1);
	b[x]=true;
	mgb(x+1);
}
void mgd(int x){
	if(x==n+1){
		bool flag=false;
		for(int i=1;i<=n;i++){
			if(a[i]){
				flag=true;
			}
		}
		if(flag){
			mgb(1);	
		}
		return;
	}
	a[x]=false;
	mgd(x+1);
	a[x]=true;
	mgd(x+1);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		add(x,y);
	}
	mgd(1);
	cout<<ans;
	return 0;
}
