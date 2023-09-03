#include<bits/stdc++.h>
using namespace std;
#define ll long long
unsigned long long ans,max1,max2;
int n,m,a[250005],b[250005],f1[250005][25],f2[250005][25],lg[250005],id,q,l,r;
unsigned long long power(unsigned long long x,unsigned long long y)
{
	if(!y)
		return 1;
	unsigned long long z=power(x,y/2);
	z=z*z;
	if(y&1)
		return z*x;
	return z;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&id,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&f1[i][0]);
	for(int i=1;i<=n;i++)
		scanf("%d",&f2[i][0]);
	lg[0]=-1;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=lg[n-i+1];j++)
			f1[i][j]=max(f1[i][j-1],f1[i+1<<(j-1)][j-1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=lg[n-i+1];j++)
			f2[i][j]=max(f2[i][j-1],f2[i+1<<(j-1)][j-1]);
	scanf("%d",&q);
	while(q--)
	{
		ans=0;
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++)
				ans+=max(f1[i][lg[j-i+1]],f1[j-(1<<(lg[j-i+1]))+1][lg[j-i+1]])*max(f2[i][lg[j-i+1]],f2[j-(1<<(lg[j-i+1]))+1][lg[j-i+1]]);
		printf("%llu\n",ans);
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
