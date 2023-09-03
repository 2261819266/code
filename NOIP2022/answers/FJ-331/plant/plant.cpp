#include<cstdio>
#include<cstring>
#include<iostream>
#define int long long
using namespace std;

const int N=1010,mod=998244353;
int T,id,n,m,c,f,a[N][N],nxth[N][N],nxtl[N][N];
int sumh[N][N],suml[N][N];
int ansc,ansf;
char s[N][N];

void init(){
	n=m=c=f=ansc=ansf=0;
	memset(a,0,sizeof(a));
	memset(nxth,0,sizeof(nxth));
	memset(nxtl,0,sizeof(nxtl));
	memset(sumh,0,sizeof(sumh));
	memset(suml,0,sizeof(suml));
	memset(s,0,sizeof(s));
}

signed main(){
	freopen("plant.in","r",stdin);freopen("plant.out","w",stdout);
	scanf("%lld%lld",&T,&id);
	while(T--){
		init();
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++){a[i][j]=s[i][j]-'0';}
		}
		for(int i=1;i<=n;i++){//nxth
			nxth[i][m+1]=m+1;
			for(int j=m;j>=1;j--){
				if(a[i][j]==1){nxth[i][j]=j;}else{nxth[i][j]=nxth[i][j+1];}
			}
		}
		for(int i=1;i<=m;i++)nxtl[n+1][i]=n+1;//nxth
		for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++){
				if(a[i][j]==1){nxtl[i][j]=i;}else{nxtl[i][j]=nxtl[i+1][j];}
			}
		}
		for(int i=n;i>=1;i--){//sumh
			for(int j=1;j<=m;j++){
				int k=nxth[i][j]-j-1;
				if(a[i][j]==1){sumh[i][j]=0;}
				else{sumh[i][j]=sumh[i+1][j]+k;}
			}
		}
		for(int i=n;i>=1;i--){//suml
			for(int j=1;j<=m;j++){
				int k=nxth[i][j]-j-1,l=nxtl[i][j]-i-1;
				if(a[i][j]==1){suml[i][j]=0;}
				else{suml[i][j]=suml[i+1][j]+k*l;}
			}
		}
		for(int i=1;i<=n-2;i++){//C
			for(int j=1;j<=m;j++){
				if(a[i][j]==1||a[i+1][j]==1||a[i+2][j]==1)continue;
				int k=nxth[i][j]-j-1;
				ansc=(ansc+sumh[i+2][j]*k%mod)%mod;;
			}
		}
		for(int i=1;i<=n-3;i++){//F
			for(int j=1;j<=m;j++){
				if(a[i][j]==1||a[i+1][j]==1||a[i+2][j]==1||a[i+3][j]==1)continue;
				int k=nxth[i][j]-j-1;
				ansf=(ansf+suml[i+2][j]*k%mod)%mod;;
			}
		}
		printf("%lld %lld\n",ansc*c%mod,ansf*f%mod);
	}
	return 0;
}
//noip2022rp++
