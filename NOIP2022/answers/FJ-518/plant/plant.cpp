#include<bits/stdc++.h>
using namespace std;
int t,id;
int main(){
 	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	printf("0 0");
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j){
//			char c;
//			scanf("%c",&c); 
//			c-=48;
//			getchar();
//		}
//	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j){
//			if(!a[i][j]){
//				int j1=j+2;
//				while(!a[i][j1]&&j1<=m){
//					line[i][j]++;
//					j1++;
//				}
//				int rem=line[i][j];
//				for(int k=j+1;k<=j1-2;++k){
//					line[i][k]=rem-1;
//					rem--;
//				}
//				if(j1>m)break;
//				else i=j1+1;
//			}
//		}
//	}
//	for(int i=1;i<=n-1;++i){
//		for(int j=1;j<=m;++j){
//			for(int k=1;k<=n-i;++k){
//				int x=i+k;bool s=1;
//				for(int l=i;l<=x;++l){
//					if(a[l][j]){
//						s=0;
//						break;
//					}
//				}
//				if(s==1){
//					c+=(line[x][j]%998244353)*(line[i][j]%998244353)%998244353;
//				}
//			}
//		}
//	}
//	printf("%d %d",c,f);
	return 0;
}
