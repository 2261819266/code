#include <bits/stdc++.h>
using namespace std;

bool a[1001][1001];
int n,m;
int shuzhe[1002][1002],hengzhe[1002][1002],shuzhef[1002][1002],hengzhehe[1002][1002];
long long sumc,sumf;
void getshuzhe(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==0){
				shuzhe[i][j]=shuzhe[i-1][j]+1;
			}
//			printf("%d ",shuzhe[i][j]);
		}
//		printf("\n");
	}
}
void gethengzhe(){
	for(int j=m;j>=1;j--){
		for(int i=1;i<=n;i++){
			if(a[i][j]==0){
				hengzhe[i][j]=hengzhe[i][j+1]+1;
			}
//			printf("%d ",hengzhe[i][j]);
		}
//		printf("\n");
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			printf("%d",hengzhe[i][j]);
//		}
//		printf("\n");
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==0){
				hengzhehe[i][j]=hengzhehe[i-1][j]+hengzhe[i][j]-1;
			}
//			printf("%d ",hengzhehe[i][j]);
		}
//		printf("\n");
	}
}
void getshuzhef(){
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(a[i][j]==0){
				shuzhef[i][j]=shuzhef[i+1][j]+1;
			}
		}
	}
}
void find(bool ffllaagg){
	sumc=0;
	if(ffllaagg){
		sumf=0;
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(shuzhe[i][j]>=3){
				int nnnnn=(hengzhehe[i-2][j]*(hengzhe[i][j]-1));
				sumc=(sumc+nnnnn)%998244353;
				if(ffllaagg){
					sumf=(sumf+nnnnn*(shuzhef[i][j]-1))%998244353;
				}
			}
		}
	}
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,_i_d_;
	scanf("%d%d",&T,&_i_d_);
	for(int i=1;i<=T;i++){
		int ccc,fff;
		scanf("%d%d%d%d",&n,&m,&ccc,&fff);
		for(int j=1;j<=n;j++){
			char ch[1001];
			scanf("%s",ch);
			for(int k=0;k<m;k++){
				a[j][k+1]=ch[k]-'0';
			}	
		}
		if(fff==1){
			getshuzhe();
			gethengzhe();
			getshuzhef();
			find(1);
			printf("%lld %lld\n",sumc,sumf);
		}
		else if(ccc==0){
			printf("0 0\n");
		}
		else{
			getshuzhe();
			gethengzhe();
			find(0);
			printf("%lld 0\n",sumc);
		}
	}
	return 0;
}
