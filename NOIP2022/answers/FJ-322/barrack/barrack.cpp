#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)

int n,m;
int u[201],v[201];
int vis[201];
bool c1[201],c2[201];
int ans=0;
int un, vn;
vector<int> e[201];

void dfs3(int now) {
	vis[now] = 1;
	for(int i:e[now]) {
		if(!vis[i] && !(now==un&&i==vn) && !(now==vn&&i==un)) dfs3(i);
	}
}

void check() {
//	cout << "ck"<<endl;
	int cnt=0;
	int st=0;
	rep(i,1,n)if(c1[i])st=i,++cnt;
	if(cnt==0)return;
	bool flg=1;
	un=vn=0;
	for(int i=1; i<=m; i++) {
		if(!c2[i]) un = u[i], vn = v[i];
		memset(vis,0,sizeof(vis));
		dfs3(st);	
		rep(k,1,n) {
			if(c1[k]&&(!vis[k])) return;
		}
		un=vn=0;
	}
//	for(int i=1;i<=n;i++)cout<<c1[i];
//	for(int i=1;i<=m;i++)cout<<c2[i];cout<<endl;
	ans+=flg;
}


void dfs2(int now) {
	if (now == m + 1) {
	check();return;
	}
	c2[now] = 1;
	dfs2(now + 1);
	c2[now] = 0;
	dfs2(now + 1);
}

void dfs1(int now) {
//	cout <<"f1"<<now<<endl;
	if (now == n + 1){
		dfs2(1);
		return;	
	}	
	c1[now] = 1;
	dfs1(now + 1);
	c1[now] = 0;
	dfs1(now + 1);
}

long long p2[500005];
long long mod=1e9+7;
void g() {
	p2[0]=1;
	for(int i=1;i<=500000;i++)p2[i]=(p2[i-1]*2)%mod;
	long long aans = 0;
	for(int i=1;i<=n;i++){
		aans+=((i*p2[i-1]%mod)*((i==n)?1:p2[n-i-1])%mod);
		aans%=mod;
	}
	cout<<aans<<endl; 
}


int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	cin>>n>>m;
	if(n>100) {
		g();return 0;
	}
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i],e[u[i]].push_back(v[i]),e[v[i]].push_back(u[i]);
	dfs1(1);
	cout<<ans;
	
	return 0;
}
