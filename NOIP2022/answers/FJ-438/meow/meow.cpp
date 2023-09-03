#include<bits/stdc++.h>
#define MAXM 2000017
#define MAXK 617
#define MAXN 317
using namespace std;
int T,n,m,k,a[MAXM];
int stp1[MAXK],stp2[MAXK],st2[MAXK],cnt1,cnt2,vis[MAXK];
int ans[MAXM<<1][2],r[MAXM<<1],num,now;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		num = 0,now = 1;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			if(cnt1 != n-1){
				if(stp1[a[i]] && vis[a[i]]){
					vis[a[i]]=0,r[++num] = 1,ans[num][0] = stp1[a[i]];
					now = i+1;
					continue;
				}
				vis[a[i]] = 1;
				stp1[a[i]] = ++cnt1;
				now = i+1;
			}
		}
		for(int i=now;i<=m;i++){
			if(st2[stp1[a[i]]] && vis[a[i]]){
				vis[a[i]]=0,r[++num] = 1,ans[num][0] = n;
				r[++num] = 2,ans[num][0] = stp1[a[i]],ans[num][1] = n;
				continue;
			}
			if(!st2[stp1[a[i]]] && vis[a[i]]){
				vis[a[i]]=0,r[++num] = 1,ans[num][0] = stp1[a[i]];
				continue;
			}
			vis[a[i]] = 1;
			if(cnt2 != n-1){
				st2[++cnt2] = 1;
				stp2[a[i]] = cnt2;
			}
		}
		cout<<num<<endl;
		for(int i=1;i<=num;i++){
			if(r[i]==1){
				cout<<r[i]<<" "<<ans[i][0]<<endl;
			}else{
				cout<<r[i]<<" "<<ans[i][0]<<" "<<ans[i][1]<<endl;
			}
		}
	}
	return 0;
}
