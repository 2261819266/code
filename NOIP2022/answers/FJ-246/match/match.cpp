#include<iostream>
#include<cstdio>
#define ull unsigned long long
using namespace std;
int T,Q,n;
int a[250010],b[250010];
int lg[250010];
int f[250010][20],g[250010][20];
ull ans;
ull ma(int x,int y){
	int l = lg[y-x+1];
	return max(f[x][l],f[y-(1<<l)+1][l]);
}
ull mb(int x,int y){
	int l = lg[y-x+1];
	return max(g[x][l],g[y-(1<<l)+1][l]);
}
int main(){
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	lg[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lg[i]=lg[i>>1]+1;
		f[i][0]=a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		g[i][0]=b[i];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<(j-1))<=n;i++){
			f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			g[i][j] = max(g[i][j-1],g[i+(1<<(j-1))][j-1]);
		}
	}
	scanf("%d",&Q);
	while(Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		ans=0;
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				ans += ma(p,q)*mb(p,q);
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}

