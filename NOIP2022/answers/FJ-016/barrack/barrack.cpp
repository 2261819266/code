#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int Mod=1e9+7;
void Add(int &x,int y){if((x+=y)>=Mod)x-=Mod;}
void Del(int &x,int y){if((x-=y)<0)x+=Mod;}
int Pow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%Mod;
		x=1ll*x*x%Mod,k>>=1;
	}
	return res;
}

void read(int &x){
	static char c;
	static int f;
	f=1;
	while(!isdigit(c=getchar()))
		if(c=='-') f=-1;x=c^48;
	while(isdigit(c=getchar())) x=(x*10)+(c^48);
	x*=f;
}

void read(ll &x){
	static char c;
	static int f;
	f=1;
	while(!isdigit(c=getchar()))
		if(c=='-') f=-1;x=c^48;
	while(isdigit(c=getchar())) x=(x*10)+(c^48);
	x*=f;
}

void read(ull &x){
	static char c;
	while(!isdigit(c=getchar()));x=c^48;
	while(isdigit(c=getchar())) x=(x*10)+(c^48);
}

void chkmax(int &x,int y){if(y>x)x=y;}
void chkmin(int &x,int y){if(y<x)x=y;}
void chkmax(ll &x,ll y){if(y>x)x=y;}
void chkmin(ll &x,ll y){if(y<x)x=y;}
void chkmax(ull &x,ull y){if(y>x)x=y;}
void chkmin(ull &x,ull y){if(y<x)x=y;}

int n,m;
vector< vector<int> > Edge;

vector<int> f,s,po;
void dfs(int now,int fa){
	f[now]=1,s[now]=1;
	for(int v:Edge[now])
		if(v!=fa) dfs(v,now),s[now]+=s[v];
	int mul=1;
	for(int v:Edge[now])
		if(v!=fa){
			int tmp=f[v];
			Add(tmp,po[s[v]]);
			mul=1ll*tmp*mul%Mod;
		}
	f[now]=(2*mul%Mod);
	Del(f[now],po[s[u]-1]);
}

void Work(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	
	read(n),read(m),Edge.resize(n+1),f.resize(n+1),s.resize(n+1),po.resize(n+1);
	
	po[0]=1;
	for(int i=1;i<=n;++i) po[i]=2*po[i-1]%Mod;
	
	for(int i=1;i<=m;++i){
		int u,v;read(u),read(v);
		Edge[u].pb(v),Edge[v].pb(u);
	}
	
	if(n==1) return puts("1"),void();
	
	if(true){
		int Ans=0;
		Add(Ans,1ll*n*po[n-1]%Mod);
		Add(Ans,1ll*n*(n-1)/2%Mod*po[n-2]%Mod);
		printf("%d\n",Ans);
		return;
	}
}

int main(){Work();}

