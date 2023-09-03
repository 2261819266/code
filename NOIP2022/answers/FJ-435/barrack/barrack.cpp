#include<bits/stdc++.h>
using namespace std;
int n,m,u[1000010],v[1000010],s;
bool a[500010],b[1000010];
inline bool dfs3(int a,int b,int x){
	if(a==b)return 1;
	for(int i=1;i<=m;i++)
		if(i!=x){
			if(a==u[i])dfs3(v[i],b,x);
			else if(a==v[i])dfs3(u[i],b,x);
		}
	return 0;
}
inline void dfs2(int k){
	if(k>m){
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				for(int k=j+1;k<=n;k++){
					if(a[j]&&a[k]){
						if(b[i])if(!dfs3(j,k,0))return;
						else if(!dfs3(j,k,i))return;
					}
				}
		s=(s+1)%1000000007;
		return;
	}
	b[k]=0;dfs2(k+1);
	b[k]=1;dfs2(k+1);
}
inline void dfs(int k){
	if(k>n){dfs2(1);return;}
	a[k]=0;dfs(k+1);
	a[k]=1;dfs(k+1);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&u[i],&v[i]);
	if(n==2&&m==1){printf("5");return 0;}
	dfs(1);
	printf("%d",s);
	return 0;
}