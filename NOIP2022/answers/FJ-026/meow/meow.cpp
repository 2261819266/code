#include<iostream>
#include<cstdio>
using namespace std;

int T;
struct cop{
	int opt,s1,s2;
};

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		cop ans[4000050];
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		int stack[305][5];
		bool vis[300]={false};
		int h[305]={0};
		int pre=0,op=0;
		for(int i=1;i<=m;i++){
			int a;
			scanf("%d",&a);
			if(a<=n*2-2){
				int p=a/2+(a%2);
				if(h[p]==0){
					vis[p]=1;
					h[p]++;
					stack[p][1]=a;
					ans[++op].opt=1;
					ans[op].s1=p;
					continue;
				}
				if(h[p]==1){
					if(stack[p][1]==a){
						h[p]=0;
						ans[++op].opt=1;
						ans[op].s1=n;
						ans[++op].opt=2;
						ans[op].s1=p;
						ans[op].s2=n;
					}else{
						vis[p]=1;
						h[p]++;
						stack[p][2]=a;
						ans[++op].opt=1;
						ans[op].s1=p;
					}
					continue;
				}
				if(h[p]==2){
					h[p]=1;
					if(stack[p][1]==a){
						stack[p][1]=stack[p][2];
						ans[++op].opt=1;
						ans[op].s1=n;
						ans[++op].opt=2;
						ans[op].s1=p;
						ans[op].s2=n;
					}else{
						vis[p]=1;
						ans[++op].opt=1;
						ans[op].s1=p;
					}
					continue;
				}
			}else{
				if(pre!=0){
					for(int i=1;i<=n-1;i++){
						if(!vis[i]){
							ans[pre].opt=1;
							ans[pre].s1=i;
							ans[++op].opt=1;
							ans[op].s1=i;
							pre=0;
							break;
						}
					}
				}else{
					pre=++op;
					for(int i=1;i<=n;i++){
						vis[i]=0;
					}
				}
			}
		}
		printf("%d\n",op);
		for(int i=1;i<=op;i++){
			if(ans[i].opt==1) printf("1 %d\n",ans[i].s1);
			else printf("2 %d %d\n",ans[i].s1,ans[i].s2);
		}
	}
	return 0;
}
