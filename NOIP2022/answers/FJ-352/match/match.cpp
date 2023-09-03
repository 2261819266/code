#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int T,n,q,l,r;
ull ans,a[3004],b[3004],maxx[3004][3004],maxy[3004][3004],maxz[3004][3004];
void qmax()
{
	for(int i=1;i<=n;++i)
	{
		maxx[i][i]=a[i],maxy[i][i]=b[i],maxz[i][i]=a[i]*1llu*b[i];
		for(int j=i+1;j<=n;++j)maxx[i][j]=max(maxx[i][j-1],a[j]),maxy[i][j]=max(maxy[i][j-1],b[j]),maxz[i][j]=maxx[i][j]*1llu*maxy[i][j];
	}
	return ;
}
void f()
{
	for(int i=l;i<=r;++i)for(int j=i;j<=r;++j)ans+=maxz[i][j];
	return ;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i)scanf("%llu",&a[i]);
	for(int i=1;i<=n;++i)scanf("%llu",&b[i]);
	qmax();
	scanf("%d",&q);
	while(q--)scanf("%d%d",&l,&r),ans=0,f(),printf("%llu\n",ans);
	return 0;
}
