#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int mod=1e9+7;
int n,m,u,v,ans,sum,num;
int head[N],Next[N],tot,ver[N],vis[10];
void add(int u,int v) {
	ver[++tot]=v;
	Next[tot]=head[u];
	head[u]=tot;
}
void check(int A,int B,int u) {
	for(int i=head[u];i;i=Next[i]) {
		if(i==B) continue;
		int v=ver[i];
		if(!vis[v]) {
			vis[v]=1;
			if((1<<(v-1))&A) sum++;
			check(A,B,v);
			vis[v]=1;
		}
	}
}
int main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=0;i<(1<<m);i++) {
		for(int j=1;j<(1<<n);j++) {
			int flag=1;
			for(int k=1;k<=tot;k++) {
				if((1<<(k/2))&i) continue;
				sum=1;
				memset(vis,0,sizeof(0));
				int st=1;
				while(!((1<<(st-1))&j)) st++;
				check(j,k,st); 
				num=0;
				for(int L=0;L<n;L++) {
					if((1<<L)&j) num++;
				}
				if(sum!=num) {
					flag=0;
					break;
				}	
			}
			if(flag) ans++;
		}
	}
	cout<<ans+1;
	return 0;
}
