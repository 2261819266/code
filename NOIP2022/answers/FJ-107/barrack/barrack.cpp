#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct Edge{
	int to,nex;
}e[N*4];
int n,m,head[N],tot;
int t,dfn[N],fa[N],f[N],sz[N],s[N],cnt,sum;
long long p[N*2],ans,mod=1e9+7,p1[N*2];
//bool v[105],vv[105],vvv[105],vvvv[105];
void add(int x,int y){
	e[++tot].to=y,e[tot].nex=head[x];
	head[x]=tot;
}
long long ksm(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void dfs(int x){
	dfn[x]=++t;
	f[x]=x;
	sz[x]++;
	for(int i=head[x];i;i=e[i].nex){
		int y=e[i].to;
		if(dfn[y]) {
			if(dfn[f[x]]>dfn[y]&&y!=fa[x]) f[x]=y,s[x]++;
			continue;
		}
		fa[y]=x;
		dfs(y);
		if(dfn[f[x]]>dfn[f[y]]) f[x]=f[y];
		sz[x]+=sz[y],s[x]+=s[y]+1;
		if(f[y]==y){
			cnt++;
			sum+=s[y];
			ans=(ans+p1[sz[y]]*p[s[y]]%mod*p1[n-sz[y]]%mod*p[m-s[y]-1]%mod)%mod;
		}
	}
//	cout<<x<<" "<<f[x]<<" "<<fa[x]<<endl;
}
/*void dfssss(int x){
	vvvv[x]=true;
	for(int i=head[x];i;i=e[i].nex){
		int y=e[i].to;
		if(vvv[i]) continue;
		vvv[i]=vvv[((i-1)^1)+1]=true;
		dfssss(y);
	}
}
void dfsss(int x){
	if(x>m){
		bool ffff=true;
		for(int i=1;i<=m;i++){
			if(!vv[i]){
				memset(vvv,0,sizeof(vvv));
				memset(vvvv,0,sizeof(vvvv));
				vvv[i*2]=vvv[i*2-1]=true;
				for(int i=1;i<=n;i++){
					if(v[i]){
						dfssss(i);
						break;
					}
				}
				for(int i=1;i<=n;i++)
					if(v[i]&&!vvvv[i]) ffff=false;
				vvv[i*2]=vvv[i*2-1]=false;
				if(ffff) ans++;
				cout<<ans<<endl;
			}
		}
		return;
	}
	vv[x]=true;
	dfsss(x+1);
	vv[x]=false;
	dfsss(x+1);
}
void dfss(int x){
	if(x>n){
		bool fff=false;
		for(int i=1;i<=n;i++)
			if(v[i]) {
				fff=true;
				break;
			}
		if(fff) dfsss(1);
		return;
	}
	v[x]=true;
	dfss(x+1);
	v[x]=false;
	dfss(x+1);
}*/
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	/*if(m<=10){
		dfss(1);
		cout<<ans<<endl;
		return 0;
	}*/
	p[0]=1;
	for(int i=1;i<=m+1;i++)
		p[i]=p[i-1]*2%mod,p1[i]=(p[i]-1+mod)%mod;
	dfs(1);
//	cout<<cnt+sum+s[1]<<" "<<m<<endl;
	ans=(p1[n]*p[m]%mod-ans+mod)%mod;
//	cout<<ans<<endl;
//	ans=ans*ksm(cnt,mod-2)%mod;
//	cout<<cnt<<endl;
//	ans=p1[n]*p[m-cnt]%mod;
	cout<<ans<<endl;
	return 0;
}
