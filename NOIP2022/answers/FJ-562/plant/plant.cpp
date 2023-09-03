#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
int a[N][N];
int n,m;
const int mod=998244353;
int vc(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1){
				if(a[i+1][j]==0)continue;
				int fir;
				for(fir=1;j+fir<=m&&a[i][j+fir]==1;fir++);
				int now;
				for(int k=i+2;k<=n&&a[k][j]==1;k++){
					for(now=1;j+now<=m&&a[k][j+now]==1;now++);
					ans=(ans+(fir-1)*(now-1))%mod;
				}
			}
		}
	}
	return ans;
}
int vf(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1){
				if(a[i+1][j]==0)continue;
				int fir;
				for(fir=1;j+fir<=m&&a[i][j+fir]==1;fir++);
				int now;
				for(int k=i+2;k<=n&&a[k][j]==1&&a[k+1][j]==1;k++){
					for(now=1;j+now<=m&&a[k][j+now]==1;now++);
					ans=(ans+(fir-1)*(now-1))%mod;
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,id;
	scanf("%d%d",&t,&id);
	while(t--){
		int c,f;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		char op[N];
		for(int i=1;i<=n;i++){
		scanf("%s",op);			
			for(int j=1;j<=m;j++){
				if(op[j-1]=='0')a[i][j]=1;
				else a[i][j]=0;
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d ",a[i][j]);
			}
			puts("");
		}*/
		if(c==1){
			printf("%d",vc());
		}
		else printf("0");
		printf(" ");
		if(f==1){
			printf("%d",vf());
		} 
		else printf("0");
		puts(""); 
	}
	return 0;
}
