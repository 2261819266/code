#include<bits/stdc++.h>
using namespace std;
int n,m,k,sta[320][20000],top[320],low[320];
int a[20000],op[20000],num1[20000],num2[20000],cnt1;
bool flag;
inline void pd(){
	for(int i=1;i<=n;i++)
		if(low[i]<=top[i]) return ;
	for(int i=1;i<=cnt1;i++)
	{
		printf("%d ",op[i]);
		if(op[i]==1) printf("%d\n",num1[i]);
		else printf("%d %d\n",num1[i],num2[i]);
	}
	flag=1;
}
inline void dfs(int x){
	if(x==m) pd();
	if(x>m) return ;
	if(flag) return ;
	for(int i=1;i<=n;i++)
	{
		if(sta[i][top[i]]==a[x]) op[++cnt1]=1,num1[cnt1]=i,top[i]--;
		else{
			sta[i][++top[i]]=a[x];
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(sta[i][low[i]]==sta[j][low[j]]&&low[i]<=top[i]&&low[j]<=top[j]){
						op[++cnt1]=2,num1[cnt1]=i,num2[cnt1]=j;
						low[i]++;
						low[j]++;
					}
		}
		dfs(x+1);
		if(sta[i][top[i]]==a[x]) cnt1--,top[i]++;
		else{
			sta[i][top[i]--]=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(sta[i][low[i]-1]==sta[j][low[j]-1]&&low[i]-1<=top[i]+1&&low[j]-1<=top[j]+1){
						cnt1--;
						low[i]--;
						low[j]--;
					}
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		flag=0;
		scanf("%d%d%d",&n,&m,&k);
		memset(sta,0,sizeof sta);
		memset(top,0,sizeof top);
		for(int i=1;i<=n;i++) low[i]=1;
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		dfs(1);
	}
}
