#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ll;
const int N=3010;
int n,Q;
bool o1;
ll a[N],b[N],fa[N][N],fb[N][N],sum[N][N],ans[N][N];
bool o2;
void work1(){
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			fa[i][j]=max(fa[i][j-1],a[j]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			fb[i][j]=max(fb[i][j-1],b[j]);
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
			sum[i][j]=sum[i-1][j]+fa[i][j]*fb[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans[i][j]=ans[i][j-1]+sum[j][j]-sum[i-1][j];
	int l,r;
	while(Q--){
		scanf("%d%d",&l,&r);
		printf("%llu\n",ans[l][r]);
	}
}
void work2(){
	
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T;
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	scanf("%d",&Q);
	if(T<=5)
		work1();
	else
		work2();
	return 0;
}
