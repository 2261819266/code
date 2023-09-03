#include<bits/stdc++.h>

using namespace std;

int t,n,m,k,a[2000005],ans[605][5],l,ovo,op,top[305],SLOW[305];
inline bool check() {
	for(int i=1;i<=n;i++) if(SLOW[i]<top[i]) return 1;
	return 0;
}
int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--) {
		op=ovo=0;
		l=1;
		scanf("%d%d%d",&n,&m,&k);
		int sta[n+1][m+1];
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) top[i]=0,SLOW[i]=1;
		while(l<=m) {
			int op1=op;
			for(int i=1;i<=n;i++) if(sta[i][top[i]]==a[l]) {
				ans[++op][1]=1;
				ans[op][2]=i;
				sta[i][top[i]+1]=a[l++];
				top[i]--;
				break;
			} 
			if(op!=op1) continue;
			for(int i=1;i<=n;i++) if(top[i]<ovo) {
				ans[++op][1]=1;
				ans[op][2]=i;
				sta[i][++top[i]]=a[l++];
				break;
			}
			if(op!=op1) continue;
			ans[++op][1]=1;
			ans[op][2]=1;
			sta[1][++top[1]]=a[l];
			l++,ovo++;
		}
		while(check()) {
			for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) {
				if(SLOW[i]>top[i]||SLOW[j]>top[j]) continue;
				if(sta[i][SLOW[i]]==sta[j][SLOW[j]]) {
					SLOW[i]++,SLOW[j]++;
					ans[++op][1]=2;
					ans[op][2]=i,ans[op][3]=j;
				}
			}
		}
		for(int i=1;i<=op;i++) {
			if(ans[i][1]==1) cout<<ans[i][1]<<" "<<ans[i][2]<<"\n";
			else cout<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<"\n";
		}
	}
	return 0;
}
