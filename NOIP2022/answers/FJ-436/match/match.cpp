#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int t,n;
ull a[250005],b[250005];
int q;
int l,r;
ull aa[250005][21],bb[250005][21];
int lg[250005];
ull ans;
int main()
{
    freopen("match.in","r",stdin);
   freopen("match.out","w",stdout);
    scanf("%d%d",&t,&n);
    for(int i=1;i<=n;i++)
    scanf("%llu",&a[i]);
    for(int i=1;i<=n;i++)
    scanf("%llu",&b[i]);
    for(int i=2;i<=n;i++)
    {
    	lg[i]=lg[i>>1]+1;
	}
    for(int i=1;i<=n;i++)
    aa[i][0]=a[i];
    for(int i=1;i<=lg[n];i++)
    {
    	for(int j=1;j+(1<<i)-1<=n;j++)
    	{
    		aa[j][i]=max(aa[j][i-1],aa[j+(1<<i-1)][i-1]);
		}
	}
	//b
	for(int i=1;i<=n;i++)
    bb[i][0]=b[i];
    for(int i=1;i<=lg[n];i++)
    {
    	for(int j=1;j+(1<<i)-1<=n;j++)
    	{
    		bb[j][i]=max(bb[j][i-1],bb[j+(1<<i-1)][i-1]);
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=lg[n];j++)
		printf("%llu ",aa[i][j]);
		printf("\n");
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=lg[n];j++)
		printf("%llu ",bb[i][j]);
		printf("\n");
	}*/
    scanf("%d",&q);
    while(q--)
    {
    	ans=0;
    	scanf("%d%d",&l,&r);
    	for(int i=l;i<=r;i++)
    	{
    		for(int j=i;j<=r;j++)
    		{
    			ans+=max(aa[i][lg[j-i+1]],aa[j-(1<<lg[j-i+1])+1][lg[j-i+1]])*max(bb[i][lg[j-i+1]],bb[j-(1<<lg[j-i+1])+1][lg[j-i+1]]);
			}
		}
		printf("%llu\n",ans);
	}
    return 0;
}