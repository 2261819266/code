#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int a[2000005];
int stac1[2000005],top1=0,di1=1;
int stac2[2000005],top2=0,di2=1;
int opt[4000005],st1[4000005],st2[4000005],cnt;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1; i<=m; i++)
			scanf("%d",&a[i]);
		if(n==2)
		{
			stac1[++top1]=a[1];
			opt[1]=1,st1[1]=1,cnt=1;
			for(int i=2; i<=m; i++)
			{
				if(stac1[top1]==a[i])
				{
					top1--;
					opt[++cnt]=1,st1[cnt]=1;
				}
				else if(stac2[top2]==a[i])
				{
					top2--;
					opt[++cnt]=1,st1[cnt]=2;
				}
				else if(stac1[di1]==a[i]&&top2-di2+1==0)
				{
					di1++;
					opt[++cnt]=1,st1[cnt]=2;
					opt[++cnt]=2,st1[cnt]=1,st2[cnt]=2;
				}
				else if(stac2[di2]==a[i]&&top1-di1+1==0)
				{
					di2++;
					opt[++cnt]=1,st1[cnt]=1;
					opt[++cnt]=2,st1[cnt]=1,st2[cnt]=2;
				}
				else
				{
					stac1[++top1]=a[i];
					opt[++cnt]=1,st1[cnt]=1;
				}
			}
		}
		printf("%d\n",cnt);
		for(int i=1; i<=cnt; i++)
		{
			if(opt[i]==1)
				printf("%d %d\n",opt[i],st1[i]);
			else printf("%d %d %d\n",opt[i],st1[i],st2[i]);
		}

	}

	return 0;
}