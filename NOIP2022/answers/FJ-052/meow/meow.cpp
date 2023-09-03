#include<bits/stdc++.h>
using namespace std;
const int N=305;
int t,n,m,k,a[N],x[N],y[N],tot;
/*bool dfs(int x,int s){
	if(x>m) {
		int c[N],d[N];
		for(int i=1;i<=n;i++) c[i]=l[i],d[i]=r[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				while(l[i]<r[i]&&l[j]<r[j]&&sta[i][l[i]]==sta[j][l[j]]) l[i]++,l[j]++,op++,s1[op]=i,s2[op]=j;
		for(int i=1;i<=n;i++) if(l[i]!=r[i]) return 0;
		for(int i=1;i<=n;i++) l[i]=c[i],r[i]=d[i];
		return 1;
	}
	for(int i=1;i<=s;i++){
		op++,sta[i][++r[i]]=a[x],s1[op]=i,s2[op]=0;
		if(dfs(x+1,s)) return 1;
		op--,r[i]--;
	}
	if(s<n) {
		op++,sta[s+1][++r[s+1]]=a[x],s1[op]=s+1,s2[op]=0;
		if(dfs(x+1,s+1)) return 1;
		r[s+1]--,op--;
	}
	return 0;
}*/
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			if(pre[a[i]]) x[++tot]=pre[a[i]],y[tot]=i,pre[a[i]]=0;
			else pre[a[i]]=i;
		}
		printf("0");
	}
	return 0;
}
