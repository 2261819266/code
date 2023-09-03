#include<cstdio>
#include<stack>
using namespace std;
int T;
int n,m,k,a[2000001];
int tot=0,vis[700][2];
stack<int>s;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)scanf("%d",&a[i]);
		printf("%d\n",m);
		for(int i=1;i<=n;i++)s.push(i);
		for(int i=1;i<=m;i++){
			if(vis[a[i]][0]){
				printf("1 %d\n",vis[a[i]][1]);
				s.push(vis[a[i]][0]);
				vis[a[i]][0]=0;
				vis[a[i]][1]=0;
			}else{
				vis[a[i]][0]=1;
				vis[a[i]][1]=s.top();
				printf("1 %d\n",vis[a[i]][1]);
				s.pop();
			}
		}
	}
	return 0;
}