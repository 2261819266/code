#include <bits/stdc++.h>
using namespace std;
#define MAXX 2000005 
int T,n,m,k,a[MAXX],len=0;
struct stak { 
	int l,r,f[2345];
}q[105];
struct node { int opt,s1,s2; }g[MAXX];
void dfs(int x){
	int ok=0;
	for(int i=1;i<=n;i++) if(q[i].r-q[i].l<0) ok=1;
	cout<<ok<<" ";
	if(ok){
		cout<<len<<endl;
		for(int i=1;i<=n;i++) cout<<q[i].l<<" "<<q[i].r<<endl;
		for(int i=1;i<=n;i++) if(q[i].r-q[i].l>0) return;
		for(int i=1;i<=len;i++){
			if(g[i].opt==1) cout<<1<<" "<<g[i].s1<<endl;
			else cout<<2<<" " <<g[i].s1<<" "<<g[i].s2<<endl;
		}
		exit(0);
	}
	for(int i=1;i<=n;i++) {
		int qwe=1;
		g[++len].opt=1,g[len].s1=i;
		if(q[i].f[q[i].r]!=a[x]) q[i].r++,q[i].f[q[i].r]=a[x],qwe=1;
		else q[i].r--,qwe=0;
		dfs(x+1),len--;
		if(qwe==1) q[i].r--; else q[i].r++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(q[i].f[q[i].l]==q[j].f[q[j].l] && q[j].f[q[j].l]!=0){
				g[++len].opt=2,g[len].s1=i,g[len].s2=j;
				q[i].l++,q[j].l++,dfs(x+1),len--; 
				q[i].l--,q[j].l--;
			}
		}
	}
}
int main (){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		if(n==3){
			for(int i=1;i<=n;i++) q[i].l=q[i].r=0;
			dfs(1);	
		}
	}
	return 0;
}
