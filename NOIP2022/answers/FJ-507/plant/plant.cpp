#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
int n,m,T,id;
ll s,t,number,ans1,ans2;
char st;
int a[1005][1005],no[1005][1005],pre[1000005];
ll numc[1005][1005],numf[1005][1005];
int find(int x){
	if(pre[x]!=x) pre[x] = find(pre[x]);
	return pre[x];
}
void join(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx!=fy) pre[fx] = fy;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	if(id==1){
		while(T--) printf("0 0\n");
		return 0;
	}
	while(T--){
		scanf("%d%d%lld%lld",&n,&m,&s,&t);
		ans1 = 0,ans2 = 0,number = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>st;
				a[i][j] = st - '0';
				number++;
				no[i][j] = number;
				numc[i][j] = 0;
				numf[i][j] = 0;
			}
		}
		for(int i=1;i<=n*m;i++) pre[i] = i;
		for(int j=1;j<=m;j++){
			for(int i=2;i<=n;i++){
				if(a[i][j]==1) continue;
				if(a[i-1][j]==0) join(no[i-1][j],no[i][j]);
			}	
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==1) continue;
				for(int k=j+1;k<=m;k++){
					if(a[i][k]==1) break;
					if(a[i][k-1]==0) numc[i][j]++;
				}
			}
		}
		
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(a[i][j]==1) continue;
				if(numc[i][j]==0) continue;
				for(int k=i+2;k<=n;k++){
					if(numc[k][j]==0) continue; 
					if(find(no[k][j])==find(no[i][j])){
						ans1 += numc[i][j] * numc[k][j] % 998244353;
					}
				}
			}
		}
		printf("%lld ",s*ans1%998244353);
		if(t==0){
			printf("0\n");
			continue;
		}
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(a[i][j]==1) continue;
				for(int k=i+1;k<=n;k++){
					if(a[k][j]==1) break;
					if(a[k-1][j]==0) numf[i][j]++;
				}
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(a[i][j]==1) continue;
				if(numc[i][j]==0) continue;
				for(int k=i+2;k<=n;k++){
					if(numc[k][j]==0) continue; 
					if(find(no[k][j])==find(no[i][j])){
						ans2 += numc[i][j] * numc[k][j] * numf[k][j] % 998244353;
					}
				}
			}
		}
		
		printf("%lld\n",t*ans2%998244353);
	}
	
	return 0;
}
