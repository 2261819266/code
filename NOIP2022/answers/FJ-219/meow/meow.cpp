#include<bits/stdc++.h>
using namespace std;
const int N = 1000100,M = 305;
struct Node{
	int d,t;
}stk2[M];

struct Ans{
	int a,b,c;
}ans[M * 2];
int op;
int stk[M][N];
int a[N];
int counts;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		counts = n;
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			while(counts > 0){
				stk[counts][stk2[counts].t++] = a[i ++];
				op ++;
				ans[op] = {1,counts,0};
				counts --;
			}
			for(int j=1;j<=n;j++){
				if(stk[j][stk2[j].d] == a[i]){
					stk2[j].d++;
					op++;
					ans[op] = {1,j,0};
				}
			}
		}
		for(int i=1;i<=op;i++){
			if(ans[op].c == 0){
				printf("%d %d\n",ans[op].a,ans[op].b);
			}else{
				printf("%d %d %d\n",ans[op].a,ans[op].b,ans[op].c);
			}
		}
		return 0;
	}
}
