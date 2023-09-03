#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
unsigned long long ans,chengfa;
const int MAXN=1e4+10;
int a[MAXN],b[MAXN];
int sTa[MAXN][25],sTb[MAXN][25];
int T,n;
int Q;
void hanshu1(int n){
	for(int i=1;i<=n;i++)sTa[i][0]=a[i];
	int p=log(n)/log(2)+1;
	for(int j=1;j<p;j++){
		for(int i=1;i-(1<<j)+1<=n;i++){
			sTa[i][j]=max(sTa[i][j-1],sTa[i+(1<<(j-1))][j-1]);
		}
	}
}
void hanshu2(int n){
	for(int i=1;i<=n;i++)sTb[i][0]=b[i];
	int p=log(n)/log(2)+1;
	for(int j=1;j<p;j++){
		for(int i=1;i-(1<<j)+1<=n;i++){
			sTb[i][j]=max(sTb[i][j-1],sTb[i+(1<<(j-1))][j-1]);
		}
	}
}
int quer1(int l,int r){
	int x=log(r-l+1)/log(2);
	return x=max(sTa[l][x],sTa[r-(1<<(x))+1][x]);
}
int quer2(int l,int r){
	int x=log(r-l+1)/log(2);
	return x=max(sTb[l][x],sTb[r-(1<<(x))+1][x]);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	hanshu1(n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	scanf("%d",&Q);
	hanshu2(n);
	int l,r;
	for(int i=1;i<=Q;i++){
		scanf("%d%d",&l,&r);
		ans=0;
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				chengfa=quer1(p,q)*quer2(p,q);
				ans+=chengfa;
			}
		}
		printf("%llu\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
