#include <bits/stdc++.h>
using namespace std;
int t,idx;
int n,m,c1,f1;
char a[1003][1003];
int b[1003][1003];
int c[1003][1003];
int d[1003][1003];
int cntc=0,cntf=0;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&idx);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&c1,&f1);
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		cntc=0,cntf=0;
		for(int i=1;i<=n;i++){
			scanf("\n");
			for(int j=1;j<=m;j++){
				scanf("%c",&a[i][j]);
				b[i][j]=a[i][j]-'0';
			}
		}
		if(c1==0&&f1==0){
			printf("0 0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			int maxx=m;
			for(int j=m;j>=1;j--){
				if(b[i][j]==1){
					maxx=j-1;
				}
				c[i][j]=maxx;
			}
		}
		for(int j=1;j<=m;j++){
			int maxx=n;
			for(int i=n;i>=1;i--){
				if(b[i][j]==1){
					maxx=i-1;
				}
				d[i][j]=maxx;
			}
		}
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=m;j++){
	//			printf("%d ",d[i][j]);
	//		}
	//		printf("\n");
	//	}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(b[j][i]==1||b[j+1][i]==1) continue;
				for(int k=j+2;k<=n;k++){
					if(b[k][i]==1){
						break;
					}
					int tmp=(c[j][i]-i)*(c[k][i]-i)%998244353;
					cntc=(cntc+tmp)%998244353;
					int tmp2=tmp*(d[k][i]-k)%998244353;
					cntf=(cntf+tmp2)%998244353;
				}
			}
		}
		cntc=(cntc*c1)%998244353;
		cntf=(cntf*f1)%998244353;
		printf("%d %d\n",cntc,cntf);
	}
	
	return 0;
}
