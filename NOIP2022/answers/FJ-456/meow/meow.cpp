#include <bits/stdc++.h>
using namespace std;

int s[301][10001],ll[301],rr[301],n,OP,nn[4000001],ss1[4000001],ss2[4000001];
void work(int x){
	for(int i=1;i<=n-1;i++){
		if(i!=x&&s[i][ll[i]+1]==s[x][ll[x]+1]&&ll[i]!=rr[i]){
//			printf("2 %d %d\n",x,i);
			nn[++OP]=2;
			ss1[OP]=x;
			ss2[OP]=i;
			ll[i]++;
			ll[x]++;
			if(ll[x]!=rr[x]) work(x);
			if(ll[i]!=rr[i]) work(i);
			break;
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
//	if(T==3){
//		for(int i=1;i<=3;i++){
//			int n,m,k;
//			scanf("%d%d%d",&n,&m,&k);
//			
//		}
//	}
	for(int i=1;i<=T;i++){
		int m,k;
		OP=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++){
			ll[i]=rr[i]=0;
		}
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			int t=1;
			int ffllaagg=0;
			for(k=1;k<=n-1;k++){
				if(x==s[k][rr[k]]&&ll[k]!=rr[k]&&ffllaagg==0){
					ffllaagg=k;
				}
				else if(x==s[k][ll[k]+1]&&ll[k]!=rr[k]){
					break;
				}
				if(rr[t]-ll[t]>rr[k]-ll[k]){
					t=k;
				}
			}
			//diduan
			if(k<=n-1){
//				printf("1 %d\n2 %d %d\n",n,k,n);
				nn[++OP]=1;
				ss1[OP]=n;
				nn[++OP]=2;
				ss1[OP]=k;
				ss2[OP]=n;
				ll[k]++;
				if(ll[k]!=rr[k]) work(k);
//				t=k;
//				ffllaagg=1;
//				while(ffllaagg){
//					for(k=1;k<=n-1;k++){
//						if(k!=t&&s[k][ll[k]+1]==s[t][ll[t]+1]){
//							printf("2 %d %d\n",k,t);
//							ll[k]
//						}
//					}
//				}
			}
			else if(ffllaagg!=0){
//				printf("1 %d\n",ffllaagg);
				nn[++OP]=1;
				ss1[OP]=ffllaagg;
				rr[ffllaagg]--;
			}
			else{
//				printf("1 %d\n",t);
				nn[++OP]=1;
				ss1[OP]=t;
				s[t][++rr[t]]=x;
			}
		}
		printf("%d\n",OP);
		for(int j=1;j<=OP;j++){
			printf("%d %d",nn[j],ss1[j]);
			if(nn[j]==2){
				printf(" %d",ss2[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
