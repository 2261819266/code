#include <bits/stdc++.h>
using namespace std;

int r[2000001],ne[2000001],la[500001],nnooww;
int fff[500001];
//int rroad[17][17][26][26],len;
//int theroad[26];
//int fa[500001];
//void maketree(int x,int father){
////	int i=la[x];
////	while(r[i]!=father){
////		i=ne[i];
////	}
//	fa[x]=father;
//	int j=la[x];
//	while(j!=0){
//		if(r[j]!=father){
//			maketree(r[j],x);
//		}
//		j=ne[j];
//	}
//}
//void dfs(int x){
//	int i=la[x];
//	while(i!=0){
//		if(fff[r[i]]==0){
//			rroad[nnooww][r[i]][0][0]++;
//			for(int i=1;i<=len;i++){
//				rroad[nnooww][r[i]][rroad[nnooww][r[i]][0][0]][i]=theroad[i];
//			}
//			theroad[++len]=i;
//			dfs(r[i]);
//			
//		}
//		i=ne[i];
//	}
//}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		r[++nnooww]=v;
		ne[nnooww]=la[u];
		la[u]=nnooww;
		r[++nnooww]=u;
		ne[nnooww]=la[v];
		la[v]=nnooww;
	}
	if(m==n-1){
//		maketree(1,0);
//changduwei0yaotepan
		fff[0]=1;
		long long sum=0;
		for(int i=1;i<=n;i++){
			fff[i]=(fff[i-1]*2)%1000000007;
		}
		for(int len=0;len<=m;len++){
			int a=n-len;
			sum+=(a*((len==0)?1:fff[len-1])%1000000007*fff[a-1]%1000000007);
//			printf("%d %lld\n",len,sum);
		}
		printf("%lld",sum);
	}
//	else if(n<=3000){
//		//liangdianlujing
//		for(int i=1;i<=n;i++){
//			nnooww=i;
//			fff[i]=1;
//			dfs(i);
//			fff[i]=0;
//		}
//	}
	return 0;
}
