#include<bits/stdc++.h>
#define int long long
//#define int unsigned long long
#define For(w,x,y,z) for(int w=(x);w<=(y);w+=(z))
#define foR(w,x,y,z) for(int w=(x);w>=(y);w-=(z))
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c-48);c=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0) {putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void fl(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
}
const int N=5e5+10;
const int mod=1e9+7;
int n,m,ans=0;
vector<int> V[N];
int f[10];
int find(int k){
	if(f[k]!=k) return f[k]=find(f[k]);
	return k;
}
int vis[11],flg[30][30];
void dfs(int u){
	for(int i=0;i<V[u].size();++i){
		if(vis[V[u][i]]) continue;
		if(flg[u][V[u][i]]||flg[V[u][i]][u]) vis[V[u][i]]=1,dfs(V[u][i]);
	}
}
signed main(){
	fl();
	n=read(),m=read();
	if(n<=8&&m<=10){
		int x[11],y[11];
		For(i,1,m,1){
			int u=read(),v=read();
			x[i]=u,y[i]=v;
			V[u].push_back(v);
			V[v].push_back(u);
		}
		int tag=1;
		For(i,1,(1<<n)-1,1){
			For(j,0,(1<<m)-1,1){
				memset(vis,0,sizeof vis);
				memset(flg,0,sizeof flg);
				For(k,0,m-1,1) if((1<<k)&j) flg[x[k+1]][y[k+1]]=1;
				tag=1;
				For(k,0,n-1,1){
					if((1<<k)&i){
						vis[k+1]=1;
						dfs(k+1);
						For(l,0,n-1,1){
							if((1<<l)&i) if(!vis[l+1]) {tag=0;break;}
						}
						break;
					}
				}
				if(!tag) continue;
				++ans;
			}
		}
		write(ans);
	}
	return 0;
}
