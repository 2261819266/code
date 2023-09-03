#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
struct node{
	int id,x,y;
}ans[N*2];
int T,TT,n,m,a[N];
int t[305][605],top[305],frt[305];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	TT=T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		int op=0,x;
		memset(frt,0,sizeof(frt));
		memset(t,0,sizeof(t));
		memset(top,0,sizeof(top));
		if(TT%10==1){
			for(int i=1;i<=n;i++)
				frt[i]=1;
			for(int i=1;i<=m;i++){
				x=a[i]%(n-1)+1;
				if(a[i]==t[x][frt[x]]){
					ans[++op].id=1;
					ans[op].x=n;
					ans[++op].id=2;
					ans[op].x=x,ans[op].y=n;
					frt[x]++;
				}
				else{
					t[x][++top[x]]=a[i];
					ans[++op].id=1;
					ans[op].x=x;
					if(t[x][top[x]]==t[x][top[x]-1]&&top[x]-frt[x]>=1)
						top[x]-=2;
				}
			}
			printf("%d\n",op);
			for(int i=1;i<=op;i++){
				printf("%d ",ans[i].id);
				if(ans[i].id==1)
					printf("%d\n",ans[i].x);
				else
					printf("%d %d\n",ans[i].x,ans[i].y);
			}
		}
	}
	return 0;
}
