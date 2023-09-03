#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,a[2000005],st[305],F[1005],ans[4000005][2];
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1;i<=m;i++) scanf("%d",&a[i]);
		if (k%2==0){
			for (int i=1;i<=n;i++) q.push(i);
			for (int i=1;i<=m;i++){
				if (!F[a[i]]) ans[++ans[0][0]][0]=1,F[a[i]]=ans[ans[0][0]][1]=q.top(),st[q.top()]=a[i],q.pop();
				else ans[++ans[0][0]][0]=1,ans[ans[0][0]][1]=F[a[i]],q.push(F[a[i]]),F[a[i]]=0;
			}
			printf("%d\n",ans[0][0]);
			for (int i=1;i<=ans[0][0];i++) printf("%d %d\n",ans[i][0],ans[i][1]);
			while (q.size()) q.pop();
		}
	}
	return 0;
}
