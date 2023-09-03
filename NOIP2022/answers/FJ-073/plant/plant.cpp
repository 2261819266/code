#include <bits/stdc++.h>
using namespace std;
#define mod 99824353
#define ll long long
#define MAXX 1005
int a[MAXX][MAXX];
ll T,id,n,m,c,f,ansc,ansf,sum;
ll lcq[MAXX][MAXX],lcs[MAXX][MAXX];//至下向上 至右向左 
void ycl(){
	memset(lcs,0,sizeof(lcs)),memset(lcq,0,sizeof(lcq));
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(a[i][j]==0) lcs[i][j]=lcs[i][j+1]+1;
			else lcs[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(lcs[i][j]!=0)--lcs[i][j];
	for(int i=n;i>=1;--i){
		for(int j=1;j<=n;j++){
			if(a[i][j]==0) lcq[i][j]=lcq[i+1][j]+1;
			else lcq[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(lcq[i][j]!=0) --lcq[i][j];
}
inline int read(){
	char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	return ch-'0';
}
int main (){//90 min
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&T,&id);
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) a[i][j]=read();	
		ycl(),ansc=ansf=0;
		for(int j=1;j<=m;++j){
			sum=0;
			for(int i=1;i<=n;++i){
				if(a[i][j]==1) sum=0;
				else{
					ansc+=(sum-lcs[i-1][j])*lcs[i][j];
					ansf+=(sum-lcs[i-1][j])*lcs[i][j]*lcq[i][j];
					ansf%=mod,ansc%=mod,sum=(lcs[i][j]+sum)%mod;
				}
			}
		}
		printf("%lld %lld\n",ansc*c%mod,ansf*f%mod);
	}
	return 0;
} 
/*
1 0
6 6 1 1
000010
011000
000110
010000
011000
000000
*/
