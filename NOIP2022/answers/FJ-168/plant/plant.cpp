#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
char mep[1010][1010];
int sum[1010][1010],vis[1010][1010];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
	
	while(T--)
	{
		int n,m,c,f;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		if(c==0&&f==0)
		{
			printf("0\n");
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%s",mep[i]);
		}
		for (int i=1;i<=n;i++)
		{
			int now=-1;
			for (int j=m-1;j>=0;j--)
			{
				if(now==-1&&mep[i][j]=='0')now=j+1;
				if(mep[i][j]=='1')now=-1;
				
				sum[i][j]=now;
			}
		}
		
		for (int j=0;j<m;j++)
		{
			int now=-1;
			for (int i=n;i>=1;i--)
			{
				if(now==-1&&mep[i][j]=='0')now=i;
				if(mep[i][j]=='1')now=-1;
				vis[i][j]=now;
			}
		}
		
		long long cans=0; 
		for (int lie=0;lie<m;lie++)
		{
			for (int len=3;len<=n;len++)
			{
				int nowlen=0;
				for (int l=1;l+len-1<=n;l++)
				{
					int r=l+len-1;
					if(vis[l][lie]!=vis[r][lie])
					{
						nowlen++;
						continue;
					}
					int upnum=0,downnum=0;
					upnum=sum[l][lie]-lie-1;
					downnum=sum[r][lie]-lie-1;
					if(upnum<=0||downnum<=0)continue;
					cans+=upnum*downnum;
					cans%=MOD;
				}
				if(nowlen==n-len+1)break;
			}
		}
		
		long long fans=0;
		for (int lie=0;lie<m;lie++)
		{
			for (int len=4;len<=n;len++)
			{
				int nowlen=0;
				for (int l=1;l+len-1<=n;l++)
				{
					int r=l+len-1;
					if(vis[l][lie]!=vis[r][lie])
					{
						nowlen++;
						continue;
					}
					int upnum=0,downnum=0;
					upnum=sum[l][lie]-lie-1;
					for (int k=l+1;k<r;k++)
					{
						downnum=sum[k][lie]-lie-1;
						if(upnum<=0||downnum<=0)continue;
						fans+=upnum*downnum;
						fans%=MOD;
					}
				}
				if(nowlen==n-len+1)break;
			}
		}
		
		cans=(c*cans)%MOD;fans=(f*fans)%MOD;
		printf("%lld %lld\n",cans,fans);
	} 
}
/*
	我果然还是太菜了,本来拿到题还挺兴奋的 
*/
