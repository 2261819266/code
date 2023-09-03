#include<bits/stdc++.h>
#define MAXN (500025)
#define XS ( 1000000007 )
#define mo(i) i%XS
using namespace std;
int m,n,a[2][MAXN],ans=0;
int tt(int i){
	int a=1,f=i;
	for(;f--;) a*=2;
	return (i==0)?0:a;
}
void hjy(int minn=0,int maxn=0,int nw=0,int i=0){
	if(minn==0&&i==1) minn=nw,maxn=minn;
	if(i==1&&nw>maxn) maxn=nw;
//	cout<<ans<<" "<<minn<<" "<<maxn<<" "<<nw<<" "<<i<<endl;
	if(nw==n){
		ans+=(maxn==0)?0:(tt(minn-1)+tt(n-maxn)+(minn==maxn?0:1));
		return ;
	}
	for(int j=0;j<=1;j++){
		hjy(minn,maxn,nw+1,j);
	}
	return ;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&a[0][i],&a[1][i]);
//	cin>>n;
//	cout<<tt(n);
	hjy();
	printf("%d",mo(ans));
	return 0;
}
