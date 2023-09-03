#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int t,id;
int n,m,c,f;
char s[1005][1005];
ll h[1005][1005],l[1005][1005];//h[i][j]第i行第j+1个数后有多少个连续0
ll ansc,ansf;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1; i<=n; i++)
		{
			scanf("%s",&s[i]);
			for(int j=m-1; j>=0; j--)
			{
				if(s[i][j]=='0')
					h[i][j]=h[i][j+1]+1;
			}
		}
		//C
		for(int i=0; i<=m-1; i++)
		{
			for(int j=n; j>=1; j--)
			{
				if(s[j][i]=='0')
					l[j][i]=l[j+1][i]+1;
			}
		}
		/*for(int i=1;i<=n;i++)
		{
			for(int j=0;j<m;j++)
			printf("%lld ",h[i][j]);
			printf("\n");
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<m;j++)
			printf("%lld ",l[i][j]);
			printf("\n");
		}*/
		for(int i=1; i<=n; i++)
		{
			for(int k=0; k<m; k++)
			{
				if(s[i][k]=='1')continue;
				for(int j=i+2; j<=i+l[i+1][k]; j++)
				{
				 
					ll tmp=h[i][k+1]*h[j][k+1]%mod;
					ansc=(ansc+tmp)%mod;
					//if(s[j+1][k]=='0')
					ansf=(ansf+tmp*(l[j+1][k]))%mod;
				//	printf("------i:%d k:%d j:%d tmp:%lld ansc:%lld ansf:%lld\n",i,k,j,tmp,ansc,ansf);
				}
			}

		}
		printf("%lld %lld\n",c*ansc,f*ansf);
	}
	return 0;
}
