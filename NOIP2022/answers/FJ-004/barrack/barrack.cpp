#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=20;
const int M=20;
bool bd[N],f[N];
bool mp[N][N];
int e[M][2];
int read(){
	int ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret;
}
int n,m;
bool vis[N];
void find(int x){
	vis[x]=1;
	for(int y=1;y<=n;y++){
		if(mp[x][y]==0||vis[y])continue;
		find(y);
	}
	return ;
}
bool check(){
	for(int i=1,ui,vi;i<=m;i++){
		if(f[i])continue;
		ui=e[i][0];
		vi=e[i][1];
		mp[ui][vi]=mp[vi][ui]=0;
		memset(vis,0,sizeof(vis));
		int id;
		for(int j=1;j<=n;j++){
			if(bd[j]){
				id=j;
				break;
			}
		}
		find(id);
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(bd[j]){
				mp[ui][vi]=mp[vi][ui]=1;
				return false;
			}
		}
		mp[ui][vi]=mp[vi][ui]=1;
	}
	return true;
}
ll ans;
void dfs(int dep,int tot){
	if(dep>n+m){
		if(tot>=1){
			if(check()){
				ans++;
				if(ans>mod)ans%=mod;
			}
		}
		return ;
	}
	if(dep>n){
		f[dep-n]=1;
		dfs(dep+1,tot);
		f[dep-n]=0;
		dfs(dep+1,tot);
	}else{
		bd[dep]=1;
		dfs(dep+1,tot+1);
		bd[dep]=0;
		dfs(dep+1,tot);
	}
	return ;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();
	m=read();
	for(int i=1,ui,vi;i<=m;i++){
		ui=read();
		vi=read();
		mp[ui][vi]=mp[vi][ui]=1;
		e[i][0]=ui;
		e[i][1]=vi;
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
